#include <Cellule.h>
#include <iostream>


Cellule::~Cellule(){
    std::cout << "Destructeur Cellule" << std::endl;
}
int Cellule::getX() const {
    return this->x;
}
int Cellule::getY() const {
return this->y;
}
bool Cellule::estVivant() const{
    return this->etat->estVivante();
}
void Cellule::calculerProchaineEtat(int nb_voisines_vivantes){
    this->etat = std::move(this->etat->prochaineEtat(nb_voisines_vivantes));
}
