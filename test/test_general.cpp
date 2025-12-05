#include <gtest/gtest.h>
#include <memory>

#include "../include/Grille.h"
#include "../include/Cellule.h"
#include "../include/EtatMort.h"
#include "../include/EtatVivant.h"
#include "../include/RegleJeuVie.h"

/*

                                    Voici des Tests unitaires pour la classe Grille et classe Cellule

                                    Elles testent :
                                        - La création d'une grille vide
                                        - Le calcul de hash
                                        - La détection de boucle
                                        - La modification d'une cellule


*/

// ---------------------------------------------Test de création d'une grille vide--------------------------------------------------
TEST(GrilleTest, CreationGrilleVide) {
    RegleJeuVie regle;
    Grille grille("5", "5", &regle);
    
    EXPECT_EQ(grille.getLargeur(), 5);
    EXPECT_EQ(grille.getLongueur(), 5);
    
    // Vérifier que toutes les cellules sont mortes
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_FALSE(grille.getGrille()[i][j]->estVivante());
        }
    }
}

// ---------------------------------------------Test de calcul de hash--------------------------------------------------
TEST(GrilleTest, CalculHash) {
    RegleJeuVie regle;
    Grille grille1("3", "3", &regle);
    Grille grille2("3", "3", &regle);
    
    grille1.calculeHash();
    grille2.calculeHash();
    
    // Deux grilles identiques doivent avoir le même hash
    EXPECT_EQ(grille1.getHash(), grille2.getHash());
    
    // Modifier une grille
    grille1.modifierElementGrille(1, 1, std::make_unique<Cellule>(1, 1, std::make_unique<EtatVivant>()));
    grille1.calculeHash();
    
    // Les hash doivent être différents
    EXPECT_NE(grille1.getHash(), grille2.getHash());
}

// ---------------------------------------------Test de détection de boucle--------------------------------------------------
TEST(GrilleTest, DetectionBoucle) {
    RegleJeuVie regle;
    
    // Créer un oscillateur (blinker)
    DonneesFichierDebut donnees;
    donnees.largeur = 5;
    donnees.longueur = 5;
    donnees.grille_debut.resize(5);
    for (int i = 0; i < 5; i++) {
        donnees.grille_debut[i].resize(5, 0);
    }
    
    // Configuration horizontale: 111
    donnees.grille_debut[2][1] = 1;
    donnees.grille_debut[2][2] = 1;
    donnees.grille_debut[2][3] = 1;
    
    Grille grille(donnees, &regle);
    
    grille.calculeHash();
    EXPECT_FALSE(grille.verifHash()); // Pas encore de boucle
    
    grille.evoluer();
    grille.calculeHash();
    EXPECT_FALSE(grille.verifHash()); // Forme verticale
    
    grille.evoluer();
    grille.calculeHash();
    EXPECT_TRUE(grille.verifHash()); // Retour à la forme horizontale - boucle détectée
}

// ---------------------------------------------------------------Test de modification d'une cellule------------------------------------------
TEST(GrilleTest, ModificationCellule) {
    RegleJeuVie regle;
    Grille grille("5", "5", &regle);
    
    // Modifier une cellule pour la rendre vivante
    grille.modifierElementGrille(2, 2, std::make_unique<Cellule>(2, 2, std::make_unique<EtatVivant>()));
    
    EXPECT_TRUE(grille.getGrille()[2][2]->estVivante());
    EXPECT_FALSE(grille.getGrille()[0][0]->estVivante());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
