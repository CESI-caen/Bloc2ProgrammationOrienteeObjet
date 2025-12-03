#if !defined(DEF_ETAT_OBSTACLE_VIVANT)
#define DEF_ETAT_OBSTACLE_VIVANT

#include <memory>

#include "EtatCellule.h"


class EtatObstacleVivant : public EtatCellule
{
public:
    EtatObstacleVivant();

    bool estVivante() const override;

    std::unique_ptr<EtatCellule> prochaineEtat(int nb_voisines_vivantes) const override;

    void dessiner(sf::RenderWindow &fenetre, sf::Vector2f position) const override;
};

#endif // DEF_ETAT_OBSTACLE_VIVANT