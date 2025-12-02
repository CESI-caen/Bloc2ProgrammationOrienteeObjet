#if !defined(DEF_CELLULE)
#define DEF_CELLULE

#include <memory>
#include <EtatCellule.h>
class Cellule
{
private:
    int x;
    int y;
    std::unique_ptr<EtatCellule> etat;
public:
    Cellule(int x, int y, std::unique_ptr<EtatCellule> etat) : x(x), y(y), etat(std::move(etat)) {}
    ~Cellule();
    bool estVivant();
    void calculerProchaineEtat(int nb_voisines_vivantes);
};





#endif // DEF_CELLULE