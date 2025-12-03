#include <Jeu.h>

Jeu::~Jeu() {
    std::cout << "Destructeur Jeu appelé" << std::endl;
}

bool Jeu::verifHash() const {
    if (std::find(grille.getTableauHashs().begin(), grille.getTableauHashs().end(), grille.getHash()) != grille.getTableauHashs().end()) {return true;}
    else {return false;}
}

void Jeu::evoluer() {
    /*
    1. parcourir la grille existance
    2. calculer le nouvelle etat de chaque cellule
    3. enregistrer ce nouvelle etat dans une nouvelle grille
    4. move la nouvelle grille dans l'attribut grille
    */

    Grille temp_grille = grille.getGrille(); //normalement copie la grille (ce n'est pas par référence)

    int largeur = grille.getLargeur();
    int longueur = grille.getLongueur();

    std::vector<std::vector<std::unique_ptr<Cellule>>> g = grille.getGrille();

    //double parcours pour aller chercher chaque unique_ptr de Cellule
    for (int i=0; i<largeur; i++) {
        for (int j=0; j<longueur; j++) {
            std::unique_ptr<Cellule> c = g[i][j];

            //calcul le prochaine état de la cellule (en fonction du nombre de celulles vivantes voisines (en fonctions des cellules voisines)) 
            c->calculerProchaineEtat(grille.getNombreVoisinesVivantes(grille.getVoisines()));

            //on modifie la grille temporaire avec le prochaine etat de la cellule 
            temp_grille.modifierElementGrille(i, j, c);
        }
    }
    grille = temp_grille;
}

