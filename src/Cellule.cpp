#include <Cellule.h>
#include <iostream>


Cellule::~Cellule(){
    std::cout << "Destructeur Cellule" << std::endl;
}
bool Cellule::estVivant(){
    return this->etat->estVivante();
}
void Cellule::calculerProchaineEtat(int nb_voisines_vivantes){
    this->etat = std::move(this->etat->prochaineEtat(nb_voisines_vivantes));
}