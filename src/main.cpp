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
    Fichier f("fichier1", "../grille_debut.txt");
    // Création de la règle du jeu de la vie
    RegleJeuVie regle;
    // Création du jeu avec la grille et la règle
    Jeu jeu;
    std::string contenu = f.Lire();
    // Création d'une grille de 10x10
    Grille grille(jeu.analyserStringFichier(contenu));

    // Création d'un observateur console
    auto observateurConsole = std::make_shared<InterfaceConsole>();

    

    

    // Attachement de l'observateur au jeu
    jeu.setObservateur(observateurConsole);

    std::cout << "=== Simulation du Jeu de la Vie ===" << std::endl;
    std::cout << "Grille initiale:" << std::endl;
    
    // Affichage de l'état initial via l'observateur
    observateurConsole->notifierChangementGrille(grille);

    // Simulation de quelques itérations
    std::cout << "\nÉvolution de la grille..." << std::endl;
    
    for (int i = 0; i < 3; i++) {
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