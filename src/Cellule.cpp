#include <iostream>

#include "Cellule.h"


/* Constructeur Cellule.hpp
Cellule(int x, int y, std::unique_ptr<EtatCellule> etat) : x(x), y(y), etat(std::move(etat)) {}
*/

Cellule::~Cellule() {
}

int Cellule::getX() const {
    return this->x;
}

int Cellule::getY() const {
    return this->y;
}

//delegue la responsabilité à une fille d'EtatCellule (attribut etat ici), celui retournera true ou false
bool Cellule::estVivante() const{
    return this->etat->estVivante();
}

//ne renvoie rien car modifie directement l'attribut, en changeant le unique_ptr (avec move())
void Cellule::calculerProchaineEtat(int nb_voisines_vivantes, const Regle& regle) {
    this->etat = std::move(this->etat->prochaineEtat(nb_voisines_vivantes, regle));
}