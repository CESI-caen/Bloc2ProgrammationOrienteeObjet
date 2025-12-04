#include <InterfaceGraphique.h>
#include <iostream>
#include <SFML/System/Clock.hpp>
#include <chrono>
#include <thread>
#include "Grille.h"
#include "InterfaceConsole.h"
#include <memory>


InterfaceGraphique::InterfaceGraphique(): fenetre(sf::VideoMode(800, 600), "Jeu de la Vie") 
{}

void InterfaceGraphique::fermer() {
    fenetre.close();
}
void InterfaceGraphique::notifierFinSimulation(std::string& raison) {
    std::cout << "Fin de simulation : " << raison << std::endl;
}



void InterfaceGraphique::notifierChangementGrille(Grille& g) {
    // Transmet l'état de la grille à l'objet graphique
    grille_graphique.mettreAJour(g);
}

// ...existing code...

void InterfaceGraphique::jouer(Grille& grille, std::shared_ptr<InterfaceConsole> observateurConsole) {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(0.5f); // 500ms entre chaque itération

    int iteration = 0;
    bool simulationActive = true;

    while (fenetre.isOpen()) {
        sf::Event event;
        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                fenetre.close();
                simulationActive = false;
            }
        }

        timeSinceLastUpdate += clock.restart();
        
        // Logique de simulation (évolution)
        if (simulationActive && timeSinceLastUpdate >= TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            
            iteration++;
            std::cout << "\n--- Itération " << iteration << " ---" << std::endl;
            
            grille.evoluer();
            grille.calculeHash();
            
            // Mise à jour des observateurs
            observateurConsole->notifierChangementGrille(grille);
            grille_graphique.mettreAJour(grille); // Mise à jour de l'affichage graphique

            
            // Vérification de stabilité (via le hash)
            if (grille.verifHash()) {
                std::string raison = "La grille est devenue stable (même configuration déjà vue)";
                observateurConsole->notifierFinSimulation(raison);
                simulationActive = false;
                fenetre.close(); // CORRECTION: Fermer la fenêtre ici
            }
            
            if (iteration >= 100) { // Limite arbitraire de 100 itérations
                std::string raison = "Nombre maximum d'itérations atteint (100)";
                observateurConsole->notifierFinSimulation(raison);
                simulationActive = false;
                fenetre.close(); // CORRECTION: Fermer la fenêtre ici
            }

        }

        // Logique de rendu
        fenetre.clear(sf::Color::Black);          
        grille_graphique.draw(fenetre, sf::RenderStates::Default);
        fenetre.display();                        
    }
}
