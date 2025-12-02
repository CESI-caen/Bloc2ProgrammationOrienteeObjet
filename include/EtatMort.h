#if !defined(DEF_ETAT_MORT)
#define DEF_ETAT_MORT
#include <EtatCellule.h>

class EtatMort :public EtatCellule
{
public:
    EtatMort();
    bool estVivante() const override;
    EtatCellule *prochaineEtat(int nb_voisines_vivantes) const override;
    void dessiner(sf::RenderWindow &fenetre, sf::Vector2f position)const override;
};



#endif // DEF_ETAT_MORT