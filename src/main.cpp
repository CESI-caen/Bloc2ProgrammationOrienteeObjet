#include "Grille.h"
#include "Cellule.h"
#include "EtatCellule.h"
#include "EtatMort.h"
#include "EtatVivant.h"
#include "InterfaceConsole.h"
#include "Jeu.h"
#include "RegleJeuVie.h"
#include <iostream>
#include <memory>

int main(){
    // Création d'une grille de 10x10
    Grille grille(10, 10);

    // Initialisation de quelques cellules vivantes dans la grille
    // On crée un motif simple (par exemple, un "blinker" ou quelques cellules aléatoires)
    
    // Cellule vivante en position (2, 3)
    grille.modifierElementGrille(2, 3, std::make_unique<Cellule>(2, 3, std::make_unique<EtatVivant>()));
    
    // Cellule vivante en position (3, 3)
    grille.modifierElementGrille(3, 4, std::make_unique<Cellule>(3, 4, std::make_unique<EtatVivant>()));
    
    // Cellule vivante en position (4, 3)
    grille.modifierElementGrille(4, 4, std::make_unique<Cellule>(4, 4, std::make_unique<EtatVivant>()));
    
    // Cellule morte en position (5, 5)
    grille.modifierElementGrille(4, 3, std::make_unique<Cellule>(4, 3, std::make_unique<EtatVivant>()));

    // Cellule morte en position (5, 5)
    grille.modifierElementGrille(4, 2, std::make_unique<Cellule>(4, 2, std::make_unique<EtatVivant>()));

    // Création d'un observateur console
    auto observateurConsole = std::make_shared<InterfaceConsole>();

    // Création de la règle du jeu de la vie
    RegleJeuVie regle;

    // Création du jeu avec la grille et la règle
    Jeu jeu(&grille, &regle);

    // Attachement de l'observateur au jeu
    jeu.setObservateur(observateurConsole);

    std::cout << "=== Simulation du Jeu de la Vie ===" << std::endl;
    std::cout << "Grille initiale:" << std::endl;
    
    // Affichage de l'état initial via l'observateur
    observateurConsole->notifierChangementGrille(grille);

    // Simulation de quelques itérations
    std::cout << "\nÉvolution de la grille..." << std::endl;
    
    for (int i = 0; i < 100; i++) {
        std::cout << "\n--- Itération " << (i + 1) << " ---" << std::endl;
        grille.evoluer();
        observateurConsole->notifierChangementGrille(grille);
        
        // Vérification de stabilité (via le hash)
        if (grille.verifHash()) {
            std::string raison = "La grille est devenue stable (même configuration déjà vue)";
            observateurConsole->notifierFinSimulation(raison);
            break;
        }
    }

    std::cout << "\n=== Fin de la simulation ===" << std::endl;

    return 0;
}