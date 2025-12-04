#include "Jeu.h"

/*Constructeur
Jeu(Grille *grille, Regle *regle) : grille(grille), regle(regle)
*/

Jeu::~Jeu() {
    std::cout << "Destructeur Jeu" << std::endl;
}

void Jeu::setObservateur(std::weak_ptr<JeuObservateur> observateur){
    this->observateur = observateur;
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

    // 4. Parcourir les lignes restantes pour remplir la grille
    for (int i=0; i < donnees.largeur; ++i) {
        for (int j=0; j < donnees.longueur; ++j) {
            char etat_cellule;

            //convertir le caractère en entier (0 ou 1 ou 8 ou 9 -> mort ou vivant ou obstacle mort ou obstacle vivant)
            donnees.grille_debut[i][j] = etat_cellule - '0';
        }
    }
    return donnees;
}
