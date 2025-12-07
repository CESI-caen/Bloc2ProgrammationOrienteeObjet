#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <SFML/System/Clock.hpp> 

#include "Grille.h"
#include "Cellule.h"
#include "EtatCellule.h"
#include "EtatMort.h"
#include "EtatVivant.h"
#include "InterfaceConsole.h"
#include "InterfaceGraphique.h"
#include "Jeu.h"
#include "RegleJeuVie.h"


int main(){
    Fichier f_out("grille_fin", "../grille_debut_out.txt");

    std::string user;
    std::string largeur;
    std::string longueur;
    // Pour le mode graphique, on va gérer l'évolution dans la boucle principale

    f_out.Vider();
    std::cout << "Quel grille souhaitez-vous ? (Grille 'propre' à vous / ou grille 'vide')" << std::endl;
    std::cin >> user;
    
    if (user != "propre" && user != "Propre" &&  user != "vide" && user != "Vide"){
        std::cout << "Entrée non reconnue, veuillez réessayer." << std::endl;
        return 1;
    }
    else if (user == "vide" || user == "Vide"){
        std::cout << "Entrez la largeur en de la grille vide à créer :" << std::endl;
        std::cin >> largeur;
        std::cout << "Entrez la longueur de la grille vide à créer :" << std::endl;
        std::cin >> longueur;

        RegleJeuVie regle;
        // Affiche les regles du jeu de la vie
        regle.afficherRegle();

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
        
        // Lancement de l'interface graphique
        observateurGraphique->jouer(grille, observateurConsole);

        std::cout << "\n=== Fin de la simulation ===" << std::endl;
        f_out.Ecrire("Grille finale après simulation :");
        return 0;
    }

    else if (user == "propre" || user == "Propre"){
    Fichier f("grille_debut", "../grille_debut.txt");
    // Création de la règle du jeu de la vie
    RegleJeuVie regle;
    // Affiche les regles du jeu de la vie
    regle.afficherRegle();
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
    
    // Lancement de l'interface graphique
    observateurGraphique->jouer(grille, observateurConsole);

    std::cout << "\n=== Fin de la simulation ===" << std::endl;

    f_out.Ecrire("Grille finale après simulation :");
    return 0;
}
}
