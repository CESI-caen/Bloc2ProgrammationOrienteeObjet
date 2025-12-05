#include <memory>

#include "EtatObstacleMort.h"


EtatObstacleMort::EtatObstacleMort() {}

bool EtatObstacleMort::estVivante() const {
    return false;
}

bool EtatObstacleMort::estObstacle() const {
    return true;
}

//retourne toujours le meme état : mort
std::unique_ptr<EtatCellule> EtatObstacleMort::prochaineEtat(int nb_voisines_vivantes, const Regle& regle) const {
    return std::make_unique<EtatObstacleMort>();
}

void EtatObstacleMort::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const {}