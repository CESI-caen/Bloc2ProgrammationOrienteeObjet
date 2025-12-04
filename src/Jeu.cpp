#include "Jeu.h"


Jeu::~Jeu() {
    std::cout << "Destructeur Jeu" << std::endl;
}

void Jeu::setObservateur(std::weak_ptr<JeuObservateur> observateur){
    this->observateur = observateur;
}


