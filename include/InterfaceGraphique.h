#if !defined(DEF_INTERFACE_GRAPHIQUE)
#define DEF_INTERFACE_GRAPHIQUE

#include <memory>
#include <SFML/Graphics.hpp>

#include "JeuObservateur.h"
#include "GrilleGraphique.h"


class InterfaceConsole;

class InterfaceGraphique :public JeuObservateur
{
private:
   sf::RenderWindow fenetre;
   GrilleGraphique grille_graphique;
public:
    InterfaceGraphique(int l, int lg);
    void notifierFinSimulation(std::string& raison) override;
    void notifierChangementGrille(Grille& g) override;
    void jouer(Grille& grille, std::shared_ptr<InterfaceConsole> observateurConsole);
    void fermer();
};




#endif // DEF_INTERFACE_GRAPHIQUE