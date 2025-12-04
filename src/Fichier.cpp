#include "Fichier.h"

//variable pour savoir si on veut ajouter ou écraser les données dans le fichier
const bool ajouter_dans_fichier = true;

/*Constructeur
Fichier(std::string nom, std::string chemin) : nom(nom), chemin(chemin) {}
*/

Fichier::~Fichier() {
    std::cout << "Destructeur Fichier" << std::endl;
}

std::string Fichier::getChemin() const {
    return chemin;
}

std::string Fichier::getNom() const {
    return nom;
}

std::string Fichier::Lire() {
    std::ifstream reading(chemin); //création d'instance de fichier en lecture

    std::string output = "";

    if (reading.is_open()) {
        char c = reading.get(); //un seul caractère à la fois

        while (reading.good()) {
            c = reading.get();
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
