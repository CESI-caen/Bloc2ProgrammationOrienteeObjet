#if !defined(DEF_ETAT_OBSTACLE_MORT)
#define DEF_ETAT_OBSTACLE_MORT

#include <memory>

#include "EtatCellule.h"


class EtatObstacleMort : public EtatCellule
{
public:
    EtatObstacleMort();

    bool estVivante() const override;
    bool estObstacle() const override;

    std::unique_ptr<EtatCellule> prochaineEtat(int nb_voisines_vivantes, const Regle& regle) const override;
};

#endif // DEF_ETAT_OBSTACLE_MORT