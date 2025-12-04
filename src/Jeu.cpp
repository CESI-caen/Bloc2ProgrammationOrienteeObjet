#include "Jeu.h"
#include <sstream>
#include <iostream>
Regle* Jeu::regle = new RegleJeuVie();
Jeu::Jeu() {}

Jeu::~Jeu() {
    std::cout << "Destructeur Jeu" << std::endl;
}

void Jeu::setObservateur(std::weak_ptr<JeuObservateur> observateur){
    this->observateur = observateur;
}

Regle *Jeu::getRegle(){ 
    return regle; 
}

// La fonction de parsing de la sortie de Lire() (Fichier)
DonneesFichierDebut Jeu::analyserStringFichier(const std::string& s) {
    DonneesFichierDebut donnees;

    //flux de chaîne à partir de la chaîne d'entrée
    std::istringstream stream(s);

    //verif donnees du fichier valide
    if (!(stream >> donnees.largeur >> donnees.longueur)) {
        //si la première ligne n'est pas au bon format
        std::cerr << "Erreur : Impossible de lire la largeur et la hauteur." << std::endl;
        return donnees; //structure vide/invalide
    }
  
    // Redimensionner le vecteur grille_debut AVANT d'y accéder
    // Convention: largeur = colonnes (X horizontal), longueur = lignes (Y vertical)
    // grille[ligne][colonne] donc grille[y][x]
    donnees.grille_debut.resize(donnees.longueur);
    for (int i = 0; i < donnees.longueur; i++) {
        donnees.grille_debut[i].resize(donnees.largeur);
    }
    afficherDonneesFichier(donnees); // Debug: afficher les dimensions lues

    // Parcourir les lignes restantes pour remplir la grille
    // i = ligne (Y), j = colonne (X)
    for (int i = 0; i < donnees.longueur; i++) {
        for (int j = 0; j < donnees.largeur; j++) {
            char etat_cellule;
            
            // IMPORTANT : lire effectivement le caractère du stream
            if (!(stream >> etat_cellule)) {
                std::cerr << "Erreur : Impossible de lire la cellule [" << i << "][" << j << "]" << std::endl;
            } else {
                //convertir le caractère en entier (0 ou 1 ou 8 ou 9 -> mort ou vivant ou obstacle mort ou obstacle vivant)
                donnees.grille_debut[i][j] = etat_cellule - '0';
            }
        }
    }
    return donnees;
}

//A enlever plus tard, juste pour debug
void Jeu::afficherDonneesFichier(const DonneesFichierDebut& donnees) const {
    std::cout << "=== Affichage DonneesFichierDebut ===" << std::endl;
    std::cout << "Largeur (colonnes): " << donnees.largeur << std::endl;
    std::cout << "Longueur (lignes): " << donnees.longueur << std::endl;
    std::cout << "\nGrille:" << std::endl;
    
    // i = ligne (Y), j = colonne (X)
    for (int i = 0; i < donnees.longueur; i++) {
        for (int j = 0; j < donnees.largeur; j++) {
            int valeur = donnees.grille_debut[i][j];
            
            // Affichage avec symboles pour meilleure lisibilité
            if (valeur == 0) {
                std::cout << ".";
            } else if (valeur == 1) {
                std::cout << "X";
            } else if (valeur == 8) {
                std::cout << "#";
            } else if (valeur == 9) {
                std::cout << "@";
            } else {
                std::cout << valeur; // Afficher la valeur si inconnue
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\nLégende: . = mort(0), X = vivant(1), # = obstacle mort(8), @ = obstacle vivant(9)" << std::endl;
    std::cout << "==================================" << std::endl;
}
