#include <memory>
#include <algorithm>

#include "EtatMort.h"
#include "EtatVivant.h"


EtatMort::EtatMort(){}

bool EtatMort::estVivante() const {
    return false;
}

std::unique_ptr<EtatCellule> EtatMort::prochaineEtat(int nb_voisines_vivantes) const {

    /*
    Regle* r =new RegleJeuVie();
    RegleJeuVie* d = dynamic_cast<RegleJeuVie*>(r);
    */
   
    RegleJeuVie r;
    if (std::find(r.getNbVoisinesVivantesPourNaitre().begin(), r.getNbVoisinesVivantesPourNaitre().end(), nb_voisines_vivantes) != r.getNbVoisinesVivantesPourNaitre().end()) {
        return std::make_unique<EtatVivant>();
    } else {
        return std::make_unique<EtatMort>(); 
    }
}

void EtatMort::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const {}