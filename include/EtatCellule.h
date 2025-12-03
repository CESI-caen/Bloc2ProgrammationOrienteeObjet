#if !defined(DEF_ETAT_CELLULE)
#define DEF_ETAT_CELLULE

#include <SFML/Graphics.hpp>
#include <RegleJeuVie.h> // Pourquoi RegleJeuVie.h et pas que Regle.h ?

class EtatCellule
{
public:
    ~EtatCellule();
    virtual bool estVivante() const =0;
    virtual std::unique_ptr<EtatCellule> prochaineEtat(int nb_voisines_vivantes) const =0;
    virtual void dessiner(sf::RenderWindow &fenetre, sf::Vector2f position)const =0;
};





#endif // DEF_ETAT_CELLULE