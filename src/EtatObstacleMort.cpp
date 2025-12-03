#include <memory>
#include <EtatObstacleMort.h>

EtatObstacleMort::EtatObstacleMort(){

}
bool EtatObstacleMort::estVivante() const{
    return false;
}
std::unique_ptr<EtatCellule> EtatObstacleMort::prochaineEtat(int nb_voisines_vivantes) const{
    return std::make_unique<EtatObstacleMort>();
}
void EtatObstacleMort::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const{

}