#if !defined(DEF_ETAT_MORT)
#define DEF_ETAT_MORT

#include <memory>

#include "EtatCellule.h"


class EtatMort : public EtatCellule
{
public:
    EtatMort();

    bool estVivante() const override;
    bool estObstacle() const override;

    std::unique_ptr<EtatCellule> prochaineEtat(int nb_voisines_vivantes, const Regle& regle) const override;
};

#endif // DEF_ETAT_MORT