#if !defined(DEF_INTERFACE_GRAPHIQUE)
#define DEF_INTERFACE_GRAPHIQUE

#include <JeuObservateur.h>
#include <SFML/Graphics.hpp>
#include <GrilleGraphique.h>
#include <memory>

class InterfaceConsole; // Forward declaration
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