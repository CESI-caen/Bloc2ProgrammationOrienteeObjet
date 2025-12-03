#include <memory>
#include <EtatMort.h>
#include <EtatVivant.h>
#include <algorithm>


EtatMort::EtatMort(){

}
bool EtatMort::estVivante() const{
    return false;
}
std::unique_ptr<EtatCellule> EtatMort::prochaineEtat(int nb_voisines_vivantes) const{
    RegleJeuVie r;

    if (std::find(r.getNbVoisinesVivantesPourSurvivre().begin(), r.getNbVoisinesVivantesPourSurvivre().end(), nb_voisines_vivantes)!=r.getNbVoisinesVivantesPourSurvivre().end()){     //Condition rester Vivante
        return std::make_unique<EtatVivant>();
    }else{
        return std::make_unique<EtatMort>(); 
    }
}
void EtatMort::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position)const{

}