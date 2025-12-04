#include <memory>

#include "EtatObstacleVivant.h"


EtatObstacleVivant::EtatObstacleVivant() {}

bool EtatObstacleVivant::estVivante() const{
    return true;
}

//retourne toujours le meme état : vivant
std::unique_ptr<EtatCellule> EtatObstacleVivant::prochaineEtat(int nb_voisines_vivantes, const Regle& regle) const {
    return std::make_unique<EtatObstacleVivant>();
}

void EtatObstacleVivant::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const {}