#include <iostream>
#include <sstream>
#include <iomanip>

#include "RegleJeuVie.h"


RegleJeuVie::~RegleJeuVie() {
}

RegleJeuVie::RegleJeuVie(std::vector<int> nb_voisines_vivantes_pour_naitre, std::vector<int> nb_voisines_vivantes_pour_survivre) {
    this->nb_voisines_vivantes_pour_naitre = nb_voisines_vivantes_pour_naitre;
    this->nb_voisines_vivantes_pour_survivre = nb_voisines_vivantes_pour_survivre;
}

std::vector<int> RegleJeuVie::getNbVoisinesVivantesPourNaitre() const {
    return this->nb_voisines_vivantes_pour_naitre;
}

void RegleJeuVie::setNbVoisinesVivantesPourNaitre(std::vector<int> list) {
    this->nb_voisines_vivantes_pour_naitre = list;
}

std::vector<int> RegleJeuVie::getNbVoisinesVivantesPourSurvivre() const {
    return this->nb_voisines_vivantes_pour_survivre;
}

void RegleJeuVie::setNbVoisinesVivantesPourSurvivre(std::vector<int> list) {
    this->nb_voisines_vivantes_pour_survivre = list;
}

void RegleJeuVie::afficherRegle() {
    std::ostringstream oss; //output string stream

    oss << " ---------------------------- Regle du Jeu de la vie ---------------------------- \n"
    
        << "Nombre de cellules vivantes voisines nécessaires pour qu'une cellule morte vive : [";
    for (int i=0; i<(this->nb_voisines_vivantes_pour_naitre).size(); i++) {
        oss << nb_voisines_vivantes_pour_naitre[i]
            << ", ";}
        oss << "]\n"

    
        << "Nombre de cellules vivantes voisines nécessaires pour qu'une cellule reste en vie : [";
    for (int i=0; i<(this->nb_voisines_vivantes_pour_survivre).size(); i++) {
        oss << nb_voisines_vivantes_pour_survivre[i]
            << ", ";}
        oss << "]\n";

    std::cout << oss.str() << std::endl;
}
