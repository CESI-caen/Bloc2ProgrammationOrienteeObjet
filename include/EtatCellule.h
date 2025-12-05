#if !defined(DEF_ETAT_CELLULE)
#define DEF_ETAT_CELLULE

#include <SFML/Graphics.hpp>
#include "Regle.h"
#include "RegleJeuVie.h" 

class Regle;
class EtatCellule
{
public:
    virtual ~EtatCellule() = default;

    virtual bool estVivante() const =0;
    virtual bool estObstacle() const =0;

    //retourne un unique_ptr d'un EtatCellule qui est celui de la prochaine ittération de la simulation
    virtual std::unique_ptr<EtatCellule> prochaineEtat(int nb_voisines_vivantes, const Regle& regle) const =0;

    virtual void dessiner(sf::RenderWindow &fenetre, sf::Vector2f position ) const =0;
};

#endif // DEF_ETAT_CELLULE