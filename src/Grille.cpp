#include <memory>
#include <iostream>
#include <algorithm>
#include <sstream>

#include "EtatCellule.h"
#include "EtatMort.h"
#include "EtatVivant.h"
#include "EtatObstacleMort.h"
#include "EtatObstacleVivant.h"
#include "Grille.h"
#include "Fichier.h"


std::vector<std::size_t> Grille::tableau_hashs;

Grille::Grille(DonneesFichierDebut donnees, Regle* regle) : regle(regle) {
    this->largeur = donnees.largeur;   // largeur = colonnes (X)
    this->longueur = donnees.longueur; // longueur = lignes (Y)

    // grille[ligne][colonne] = grille[y][x]
    grille.resize(longueur);
    for (int i = 0; i < longueur; i++) {
        grille[i].resize(largeur);
    }

    // i = ligne (Y), j = colonne (X)
    for(int i = 0 ; i < longueur ;i++ ){
        for(int j = 0 ; j < largeur ; j++){
            if (donnees.grille_debut[i][j] == 0) {
                this->grille[i][j] = std::make_unique<Cellule>(i, j, std::make_unique<EtatMort>());
            } else if (donnees.grille_debut[i][j] == 1) {
                this->grille[i][j] = std::make_unique<Cellule>(i, j, std::make_unique<EtatVivant>());
            } else if (donnees.grille_debut[i][j] == 8) {
                this->grille[i][j] = std::make_unique<Cellule>(i, j, std::make_unique<EtatObstacleMort>());
            } else if (donnees.grille_debut[i][j] == 9) {
                this->grille[i][j] = std::make_unique<Cellule>(i, j, std::make_unique<EtatObstacleVivant>());
            }
        }
    }
}

Grille::~Grille() {
    std::cout << "Destructeur Grille" <<std::endl;
}

int Grille::getLargeur() const{
    return this->largeur;
}

int Grille::getLongueur() const{
    return this-> longueur;
}

std::vector<std::size_t>  Grille::getTableauHash() {
    return this->tableau_hashs;
}

void Grille::modifierElementGrille(int i, int j, std::unique_ptr<Cellule> cellule) {
    if (i >= 0 && i < largeur && j >= 0 && j < longueur) {
        grille[i][j] = std::move(cellule);
    }
}

std::vector<std::vector<std::unique_ptr<Cellule>>> &Grille::getGrille() {
    return this->grille;
}

const std::vector<std::vector<std::unique_ptr<Cellule>>> &Grille::getGrille() const {
    return this->grille;
}

std::size_t Grille::getHash() {
    return this->hash;
}

void Grille::calculeHash() {
    std::string temp_string;

    // i = ligne (Y), j = colonne (X)
    for (int i = 0; i < this->longueur; i++) {
        for (int j = 0; j < this->largeur; j++) {
            temp_string += (this->grille[i][j]->estVivante() ? "1" : "0");
        }
        temp_string += ";"; 
    }

    std::size_t H = std::hash<std::string>{}(temp_string);
    std::cout << "Hash = " << H << std::endl;

    this->tableau_hashs.push_back(H);
    this->hash = H;
}

std::vector<Cellule *> Grille::voisines(const Cellule &c) const {
    std::vector<Cellule *> voisins;

    // Déplacements pour les 8 voisins : [dLigne, dColonne]
    // dLigne : décalage en ligne (haut/bas)
    // dColonne : décalage en colonne (gauche/droite)
    const int dLigne[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    const int dColonne[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

    // ATTENTION: dans Cellule, x stocke la ligne et y stocke la colonne
    // (c'est contre-intuitif mais c'est comme ça que le code est fait)
    int ligne = c.getX();    // x stocke la ligne (i)
    int colonne = c.getY();  // y stocke la colonne (j)

    for (int i = 0; i < 8; i++) {
        // Calcul avec modulo pour grille torique
        int nouvelleLigne = (ligne + dLigne[i] + this->longueur) % this->longueur;
        int nouvelleColonne = (colonne + dColonne[i] + this->largeur) % this->largeur;
        voisins.push_back(grille[nouvelleLigne][nouvelleColonne].get());
    }
    return voisins; 
}

int Grille::nbVoisineVivante(std::vector<Cellule *> list) const {
    int compteur = 0;

    for (std::size_t i = 0; i < list.size(); i++) {
        if (list[i]->estVivante()) {
            compteur ++;
        }
    }
    return compteur;
}

bool Grille::verifHash() const {
    // Vérifie si le hash actuel existe déjà dans l'historique (excluant la dernière entrée qui est le hash actuel)
    // Si on a au moins 2 hashs et que le hash actuel apparaît avant la dernière position
    if (tableau_hashs.size() < 2) {
        return false; // Pas assez d'historique pour détecter une boucle
    }
    
    // Chercher le hash actuel dans l'historique (sauf la dernière position)
    for (size_t i = 0; i < tableau_hashs.size() - 1; i++) {
        if (tableau_hashs[i] == this->hash) {
            return true; // Configuration déjà vue
        }
    }
    return false;
}

void Grille::evoluer() {
    /*
    1. Parcourir la grille existante
    2. Calculer le nouvel état de chaque cellule
    3. Enregistrer ce nouvel état dans une nouvelle grille temporaire
    4. Remplacer l'ancienne grille par la nouvelle
    */

    // Créer une grille temporaire
    std::vector<std::vector<std::unique_ptr<Cellule>>> g_temp;
    g_temp.resize(longueur);
    for (int i = 0; i < longueur; i++) {
        g_temp[i].resize(largeur);
    }

    // Boucle sur chaque cellule
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) {
            Cellule& c = *grille[i][j];

            // CORRECTION: Utiliser la fonction voisines() pour une gestion cohérente de la grille torique
            std::vector<Cellule*> vois = voisines(c);

            // Compter le nombre de voisines vivantes
            int nb = nbVoisineVivante(vois);

            // --- Calculer le prochain état ---
            const Regle* regleAUtiliser = regle;
            RegleJeuVie regleDefaut;
            if (regleAUtiliser == nullptr) regleAUtiliser = &regleDefaut;

            std::unique_ptr<EtatCellule> nouvelEtat;
            if (c.estVivante()) {
                EtatVivant etatVivantTemp;
                nouvelEtat = etatVivantTemp.prochaineEtat(nb, *regleAUtiliser);
            } else {
                EtatMort etatMortTemp;
                nouvelEtat = etatMortTemp.prochaineEtat(nb, *regleAUtiliser);
            }

            // Créer une nouvelle cellule avec le nouvel état
            g_temp[i][j] = std::make_unique<Cellule>(i, j, std::move(nouvelEtat));
        }
    }

    // Remplacer l'ancienne grille par la nouvelle
    grille = std::move(g_temp);
}


