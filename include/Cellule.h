#if !defined(DEF_CELLULE)
#define DEF_CELLULE

#include <memory>

#include "EtatCellule.h"


class Cellule
{
private:
    //position dans la grille (tableau 2D : vector<vector>)
    int x;
    int y;

    //pointeur intelligent vers un etat, n'importe lequel
    std::unique_ptr<EtatCellule> etat;

public:
    Cellule(int x, int y, std::unique_ptr<EtatCellule> etat) : x(x), y(y), etat(std::move(etat)) {}
    ~Cellule();

    int getX() const;
    int getY() const;

    bool estVivante() const;
    bool estObstacle() const;

    void calculerProchaineEtat(int nb_voisines_vivantes, const Regle& regle);
};

#endif // DEF_CELLULE