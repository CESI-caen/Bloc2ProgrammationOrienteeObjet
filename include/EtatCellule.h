#if !defined(DEF_ETAT_CELLULE)
#define DEF_ETAT_CELLULE

#include <SFML/Graphics.hpp>

class EtatCellule
{
public:
    virtual ~EtatCellule();
    virtual bool estVivante() const =0;
    virtual EtatCellule *prochaineEtat(int nb_voisines_vivantes) const =0;
    virtual void dessiner(sf::RenderWindow &fenetre, sf::Vector2f position)const =0;
};





#endif // DEF_ETAT_CELLULE