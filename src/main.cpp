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
    std::string user;
    std::string largeur;
    std::string longueur;
    // Pour le mode graphique, on va gérer l'évolution dans la boucle principale
    // de l'interface graphique pour éviter les problèmes de concurrence.
    // Pour le mode console, il faudrait une logique différente, mais ici on se concentre sur le mode graphique.
    std::cout << "Quel grille souhaitez-vous ? (Grille 'propre' à vous / ou grille 'vide')" << std::endl;
    std::cin >> user;
    
    if (user != "propre" && user != "Propre" &&  user != "vide" && user != "Vide"){
        std::cout << "Entrée non reconnue, veuillez réessayer." << std::endl;
        return 1;
    }
    else if (user == "vide" || user == "Vide"){
        std::cout << "Entrez la largeur de la grille vide à créer :" << std::endl;
        std::cin >> largeur;
        std::cout << "Entrez la longueur de la grille vide à créer :" << std::endl;
        std::cin >> longueur;

        RegleJeuVie regle;
        // Création du jeu avec la grille et la règle
        Jeu jeu(&regle);
        Grille grille(largeur, longueur, &regle);

         // Création des observateurs par pointeur partagé pour Jeu::weak_ptr<Observateur>
        auto observateurConsole = std::make_shared<InterfaceConsole>();
        auto observateurGraphique = std::make_shared<InterfaceGraphique>(std::stoi(largeur), std::stoi(longueur));

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
        // Intégration de la boucle de simulation dans la boucle principale
        // pour éviter les problèmes de concurrence avec SFML et la gestion des événements.
        // La boucle jouer() de l'interface graphique doit gérer l'évolution.
        observateurGraphique->jouer(grille, observateurConsole);

        std::cout << "\n=== Fin de la simulation ===" << std::endl;
        return 0;
    }

    else if (user == "propre" || user == "Propre"){
    Fichier f("Glidder", "../grille_debut.txt");
    // Création de la règle du jeu de la vie
    RegleJeuVie regle;
    // Création du jeu avec la grille et la règle
    Jeu jeu(&regle);
    std::string contenu = f.Lire();
    // Création d'une grille avec les données du fichier ET la règle
    Grille grille(jeu.analyserStringFichier(contenu), &regle);

    // Création des observateurs par pointeur partagé pour Jeu::weak_ptr<Observateur>
    auto observateurConsole = std::make_shared<InterfaceConsole>();
    auto observateurGraphique = std::make_shared<InterfaceGraphique>(jeu.analyserStringFichier(contenu).largeur, jeu.analyserStringFichier(contenu).longueur);

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
    // Intégration de la boucle de simulation dans la boucle principale
    // pour éviter les problèmes de concurrence avec SFML et la gestion des événements.
    // La boucle jouer() de l'interface graphique doit gérer l'évolution.
    observateurGraphique->jouer(grille, observateurConsole);

    std::cout << "\n=== Fin de la simulation ===" << std::endl;

    return 0;
}
}
