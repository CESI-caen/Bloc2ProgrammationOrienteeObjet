#include <memory>
#include <algorithm>

#include "EtatMort.h"
#include "EtatVivant.h"


EtatMort::EtatMort(){}

bool EtatMort::estVivante() const {
    return false;
}

std::unique_ptr<EtatCellule> EtatMort::prochaineEtat(int nb_voisines_vivantes) const {
    RegleJeuVie r;

    //Condition pour vivre, on recherche si le parametre de la methode appartient a l'ensemble de définition des regles (ici un vector de int)
    if (std::find(r.getNbVoisinesVivantesPourNaitre().begin(), r.getNbVoisinesVivantesPourNaitre().end(), nb_voisines_vivantes) != r.getNbVoisinesVivantesPourNaitre().end()){
        return std::make_unique<EtatVivant>();
    }else{
        return std::make_unique<EtatMort>(); 
    }
}

void EtatMort::dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const {}