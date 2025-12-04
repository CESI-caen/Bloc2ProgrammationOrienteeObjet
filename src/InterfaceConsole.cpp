#include <InterfaceConsole.h>
#include <iostream>

void InterfaceConsole::notifierChangementGrille(Grille& g) {
    int largeur = g.getLargeur();   // colonnes (X)
    int longueur = g.getLongueur(); // lignes (Y)

    // i = ligne (Y), j = colonne (X)
    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            std::cout << (g.getGrille()[i][j]->estVivante() ? "1" : "0");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void InterfaceConsole::notifierFinSimulation(std::string& raison) {
    std::cout << "Simulation terminée : " << raison << std::endl;
}
