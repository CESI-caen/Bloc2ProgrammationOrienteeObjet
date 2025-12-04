#include <memory>

#include "EtatVivant.h"
#include "EtatMort.h"


EtatVivant::EtatVivant() {}

bool EtatVivant::estVivante() const {
    return true;
}

std::unique_ptr<EtatCellule> EtatVivant::prochaineEtat(int nb_voisines_vivantes) const {
    Regle* r =new RegleJeuVie();
    RegleJeuVie* d = dynamic_cast<RegleJeuVie*>(r);

    //Condition pour rester Vivante
    if (std::find(d->getNbVoisinesVivantesPourSurvivre().begin(), d->getNbVoisinesVivantesPourSurvivre().end(), nb_voisines_vivantes) != d->getNbVoisinesVivantesPourSurvivre().end()){
        return std::make_unique<EtatVivant>();
    }else{
        return std::make_unique<EtatMort>(); 
    }
}

void EtatVivant::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const {}