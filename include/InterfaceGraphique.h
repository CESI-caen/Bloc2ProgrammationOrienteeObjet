#if !defined(DEF_INTERFACE_GRAPHIQUE)
#define DEF_INTERFACE_GRAPHIQUE

#include <JeuObservateur.h>
#include <SFML/Graphics.hpp>
#include <GrilleGraphique.h>
class InterfaceGraphique :public JeuObservateur
{
private:
   sf::RenderWindow fenetre;
   GrilleGraphique grille_graphique;
public:
    InterfaceGraphique();
    void notifierChangementGrille(Grille& g) override;
    void jouer();
};




#endif // DEF_INTERFACE_GRAPHIQUE