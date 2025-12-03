#include <memory>

#include "EtatVivant.h"
#include "EtatMort.h"


EtatVivant::EtatVivant() {}

bool EtatVivant::estVivante() const {
    return true;
}

std::unique_ptr<EtatCellule> EtatVivant::prochaineEtat(int nb_voisines_vivantes) const {
    RegleJeuVie r;

    //Condition pour rester Vivante
    if (std::find(r.getNbVoisinesVivantesPourSurvivre().begin(), r.getNbVoisinesVivantesPourSurvivre().end(), nb_voisines_vivantes) != r.getNbVoisinesVivantesPourSurvivre().end()){
        return std::make_unique<EtatVivant>();
    }else{
        return std::make_unique<EtatMort>(); 
    }
}

void EtatVivant::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const {}