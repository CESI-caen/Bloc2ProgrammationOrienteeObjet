#include "Fichier.h"


int main(){
    Fichier f("fichier1", "../grille_debut.txt");

    std::string s = f.Lire();
    std::cout << s;

    return 0;
}