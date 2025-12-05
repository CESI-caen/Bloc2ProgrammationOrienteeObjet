#include "Grille.h"
#include "Cellule.h"
#include "EtatCellule.h"
#include "EtatMort.h"
#include "EtatVivant.h"
#include "InterfaceConsole.h"
#include "InterfaceGraphique.h"
#include "Jeu.h"
#include "RegleJeuVie.h"
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <SFML/System/Clock.hpp> // Ajout pour la gestion du temps dans la boucle principale

int main(){
    // CORRECTION: Pour le mode graphique, on va gérer l'évolution dans la boucle principale
    // de l'interface graphique pour éviter les problèmes de concurrence.
    // Pour le mode console, il faudrait une logique différente, mais ici on se concentre sur le mode graphique.
    Fichier f("Glidder", "../grille_debut.txt");
    // Création de la règle du jeu de la vie
    RegleJeuVie regle;
    // Création du jeu avec la grille et la règle
    Jeu jeu(&regle);
    std::string contenu = f.Lire();
    // Création d'une grille avec les données du fichier ET la règle
    Grille grille(jeu.analyserStringFichier(contenu), &regle);

    // Création des observateurs
    auto observateurConsole = std::make_shared<InterfaceConsole>();
    auto observateurGraphique = std::make_shared<InterfaceGraphique>();

    // Attachement de l'observateur console au jeu
    jeu.setObservateur(observateurConsole);
    // Attachement de l'observateur graphique au jeu
    jeu.setObservateur(observateurGraphique);

    std::cout << "=== Simulation du Jeu de la Vie ===" << std::endl;
    std::cout << "Grille initiale:" << std::endl;
    
    // Affichage de l'état initial
    observateurConsole->notifierChangementGrille(grille);
    observateurGraphique->notifierChangementGrille(grille);

    // Simulation de quelques itérations
    std::cout << "\nÉvolution de la grille..." << std::endl;
    
    // Lancement de l'interface graphique (boucle principale)
    // CORRECTION: Intégration de la boucle de simulation dans la boucle principale
    // pour éviter les problèmes de concurrence avec SFML et la gestion des événements.
    // La boucle jouer() de l'interface graphique doit gérer l'évolution.
    observateurGraphique->jouer(grille, observateurConsole);

    std::cout << "\n=== Fin de la simulation ===" << std::endl;

    return 0;
}