#if !defined(DEF_ETAT_VIVANT)
#define DEF_ETAT_VIVANT

#include <EtatCellule.h>
#include <memory>

class EtatVivant :public EtatCellule
{
public:
    EtatVivant();
    bool estVivante() const override;
    std::unique_ptr<EtatCellule> prochaineEtat(int nb_voisines_vivantes) const override;
    void dessiner(sf::RenderWindow &fenetre, sf::Vector2f position)const override;
};

#endif // DEF_ETAT_VIVANT