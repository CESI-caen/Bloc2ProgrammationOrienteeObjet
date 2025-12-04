#include <memory>

#include "EtatVivant.h"
#include "EtatMort.h"


EtatVivant::EtatVivant() {}

bool EtatVivant::estVivante() const {
    return true;
}

std::unique_ptr<EtatCellule> EtatVivant::prochaineEtat(int nb_voisines_vivantes) const {
    const RegleJeuVie r;
    const auto& nbPourSurvivre = r.getNbVoisinesVivantesPourSurvivre(); // référence constante

    if (std::find(nbPourSurvivre.begin(), nbPourSurvivre.end(), nb_voisines_vivantes) != nbPourSurvivre.end()) {
        return std::make_unique<EtatVivant>();
    } else {
        return std::make_unique<EtatMort>();
    }
}


void EtatVivant::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const {}