#include "Fichier.h"

//variable pour savoir si on veut ajouter ou écraser les données dans le fichier
const bool ajouter_dans_fichier = true;

Fichier::~Fichier() {
    std::cout << "Destd::stringucteur Fichier appelé" << std::endl;
}

std::string Fichier::getChemin() const {
    return chemin;
}

std::string Fichier::getNom() const {
    return nom;
}

std::string Fichier::Lire() {
    std::ifstream reading(chemin); //création d'instance de fichier en lecture

    //possibilité :
    //std::ostd::stringingstd::stringeam output_oss;
    //comme std::stringing mais peux utiliser <<

    std::string output = "";

    if (reading.is_open()) {
        char c;

        while (reading.get()) {
            output += c;
        }
        reading.close();
    } else {
        std::cerr << "[ERROR]"
                  << ", Fichier : " << __FILE__
                  << ", Ligne : " << __LINE__
                  << ", Fonction : " << __func__
                  << " --> Impossible d'ouvrir le fichier spécifié : " << chemin
                  << std::endl;
    }
    return output;
}

void Fichier::Ecrire(std::string s) {
    std::ofstream writting;

    if(ajouter_dans_fichier) {writting.open(chemin, std::ios::app);}
    else {writting.open(chemin);}

    if (writting.is_open()) {
        writting << s << std::endl;
        writting.close();
    } else {
        std::cerr << "[ERROR]"
                  << ", Fichier : " << __FILE__
                  << ", Ligne : " << __LINE__
                  << ", Fonction : " << __func__
                  << " --> Impossible d'ouvrir le fichier spécifié : " << chemin
                  << std::endl;
    }
}
