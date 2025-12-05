#if !defined(DEF_ETAT_VIVANT)
#define DEF_ETAT_VIVANT

#include <memory>

#include "EtatCellule.h"


class EtatVivant : public EtatCellule
{
public:
    EtatVivant();

    bool estVivante() const override;
    bool estObstacle() const override;

    std::unique_ptr<EtatCellule> prochaineEtat(int nb_voisines_vivantes, const Regle& regle) const override;
};

#endif // DEF_ETAT_VIVANT