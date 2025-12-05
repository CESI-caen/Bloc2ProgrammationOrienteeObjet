#include <memory>
#include <iostream>
#include "EtatVivant.h"
#include "EtatMort.h"
#include <algorithm> // Ajout de l'include pour std::find


EtatVivant::EtatVivant() {}

bool EtatVivant::estVivante() const {
    return true;
}
bool EtatVivant::estObstacle() const {
    return false;
}

std::unique_ptr<EtatCellule> EtatVivant::prochaineEtat(int nb_voisines_vivantes, const Regle& regle) const {
    const RegleJeuVie& r = dynamic_cast<const RegleJeuVie&>(regle);
    const auto& nbPourSurvivre = r.getNbVoisinesVivantesPourSurvivre(); // référence constante
    if (std::find(nbPourSurvivre.begin(), nbPourSurvivre.end(), nb_voisines_vivantes) != nbPourSurvivre.end()) {
        return std::make_unique<EtatVivant>();
    } else {
        return std::make_unique<EtatMort>();
    }
}


void EtatVivant::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const {}