#include <memory>
#include <EtatVivant.h>
#include <EtatMort.h>


EtatVivant::EtatVivant(){

}
bool EtatVivant::estVivante() const{
    return true;
}
std::unique_ptr<EtatCellule> EtatVivant::prochaineEtat(int nb_voisines_vivantes) const{
    if (nb_voisines_vivantes == 2 || nb_voisines_vivantes == 3){ //Condition rester Vivante
        return std::make_unique<EtatVivant>();
    }else{
        return std::make_unique<EtatMort>(); 
    }
}
void EtatVivant::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position)const{

}