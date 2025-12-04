#include <memory>
#include <algorithm>

#include "EtatMort.h"
#include "EtatVivant.h"
#include "Jeu.h"


EtatMort::EtatMort(){}

bool EtatMort::estVivante() const {
    return false;
}

std::unique_ptr<EtatCellule> EtatMort::prochaineEtat(int nb_voisines_vivantes) const {

    Regle* b = new RegleJeuVie();
    RegleJeuVie* r = dynamic_cast<RegleJeuVie*>(b);


    const auto& nbPourNaitre = r->getNbVoisinesVivantesPourNaitre(); // référence constante pour éviter la copie

    if (std::find(nbPourNaitre.begin(), nbPourNaitre.end(), nb_voisines_vivantes) != nbPourNaitre.end()) {
        return std::make_unique<EtatVivant>();
    } else {
        return std::make_unique<EtatMort>();
    }
}


void EtatMort::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const {}