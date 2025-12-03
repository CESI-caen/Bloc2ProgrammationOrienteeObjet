#include <memory>
#include <EtatCellule.h>
#include <iostream>

EtatCellule::~EtatCellule(){
    std::cout << "Destructeur EtatCellule" << std::endl;
}