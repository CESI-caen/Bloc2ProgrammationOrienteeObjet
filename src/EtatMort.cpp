#include <memory>
#include <EtatMort.h>
#include <EtatVivant.h>


EtatMort::EtatMort(){

}
bool EtatMort::estVivante() const{
    return false;
}
std::unique_ptr<EtatCellule> EtatMort::prochaineEtat(int nb_voisines_vivantes) const{
    if (nb_voisines_vivantes == 3){     //Condition rester Vivante
        return std::make_unique<EtatVivant>();
    }else{
        return std::make_unique<EtatMort>(); 
    }
}
void EtatMort::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position)const{

}