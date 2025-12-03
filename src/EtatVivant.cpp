#include <memory>
#include <EtatVivant.h>
#include <EtatMort.h>

#include <algorithm>


EtatVivant::EtatVivant(){

}
bool EtatVivant::estVivante() const{
    return true;
}
std::unique_ptr<EtatCellule> EtatVivant::prochaineEtat(int nb_voisines_vivantes) const{
    RegleJeuVie r;
    if (std::find(r.getNbVoisinesVivantesPourNaitre().begin(), r.getNbVoisinesVivantesPourNaitre().end(), nb_voisines_vivantes)!=r.getNbVoisinesVivantesPourNaitre().end()){ //Condition rester Vivante
        return std::make_unique<EtatVivant>();
    }else{
        return std::make_unique<EtatMort>(); 
    }
}
void EtatVivant::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position)const{

}