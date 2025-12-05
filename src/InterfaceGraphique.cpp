#include <InterfaceGraphique.h>
#include <iostream>
#include <SFML/System/Clock.hpp>
#include <chrono>
#include <thread>
#include "Grille.h"
#include "InterfaceConsole.h"
#include "EtatVivant.h"
#include "EtatMort.h"
#include "EtatObstacleMort.h"
#include "EtatObstacleVivant.h"
#include <memory>
class GrilleGraphique;

InterfaceGraphique::InterfaceGraphique(int l, int lg) {
    int largeurFenetre = l * grille_graphique.getTailleCellule();
    int longueurFenetre = lg * grille_graphique.getTailleCellule();
    fenetre.create(sf::VideoMode(largeurFenetre, longueurFenetre), "Jeu de la Vie");
}

void InterfaceGraphique::fermer() {
    fenetre.close();
}
void InterfaceGraphique::notifierFinSimulation(std::string& raison) {
    std::cout << "Fin de simulation : " << raison << std::endl;
}

void InterfaceGraphique::notifierChangementGrille(Grille& g) {
    // Transmet l'état de la grille à l'objet graphique
    this->grille_graphique.mettreAJour(g);
}


void InterfaceGraphique::jouer(Grille& grille, std::shared_ptr<InterfaceConsole> observateurConsole) {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(0.5f); // 500ms entre chaque itération

    int iteration = 0;
    bool simulationActive = false; //

    while (fenetre.isOpen()) {
        sf::Event event;
        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                fenetre.close();
                simulationActive = false;
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    clock.restart(); // Réinitialiser le timer
                    timeSinceLastUpdate = sf::Time::Zero;
                    simulationActive = !simulationActive;
                }
            }

            if(event.type == sf::Event::MouseButtonPressed ) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(fenetre);
                    int x = mousePos.x / grille_graphique.getTailleCellule();
                    int y = mousePos.y / grille_graphique.getTailleCellule();
                    if (x >= 0 && x < grille.getLargeur() && y >= 0 && y < grille.getLongueur()) {
                        Cellule& cellule = *grille.getGrille()[y][x];

                        if (!cellule.estVivante() && !cellule.estObstacle()) {
                            grille.modifierElementGrille(y, x, std::make_unique<Cellule>(y, x, std::make_unique<EtatVivant>()));
                        }
                        else if(cellule.estVivante() && !cellule.estObstacle()){
                            grille.modifierElementGrille(y, x, std::make_unique<Cellule>(y, x, std::make_unique<EtatObstacleVivant>()));
                        } 
                        else if (cellule.estVivante() && cellule.estObstacle()){
                            grille.modifierElementGrille(y, x, std::make_unique<Cellule>(y, x, std::make_unique<EtatObstacleMort>()));
                        } 
                        else if (!cellule.estVivante() && cellule.estObstacle()){
                            grille.modifierElementGrille(y, x, std::make_unique<Cellule>(y, x, std::make_unique<EtatMort>()));
                        }

                            // Mettre à jour les observateurs après la modification
                            observateurConsole->notifierChangementGrille(grille);
                            grille_graphique.mettreAJour(grille);
                        }
                    }
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
            }

        }

        // Logique de rendu
        fenetre.clear(sf::Color::Black);          
        grille_graphique.draw(fenetre, sf::RenderStates::Default);
        fenetre.display();                        
    }
}
