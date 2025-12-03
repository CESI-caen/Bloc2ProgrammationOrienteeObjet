#if !defined(DEF_REGLE_JEU_VIE)
#define DEF_REGLE_JEU_VIE

#include <vector>

#include "Regle.h"


class RegleJeuVie : public Regle
{
private:
    //idées ajout d'antonin
    std::vector<int> nb_voisines_vivantes_pour_naitre;
    std::vector<int> nb_voisines_vivantes_pour_survivre;

public:
    RegleJeuVie();
    ~RegleJeuVie();

    std::vector<int> getNbVoisinesVivantesPourNaitre() const;
    void setNbVoisinesVivantesPourNaitre(int n);

    std::vector<int> getNbVoisinesVivantesPourSurvivre() const;
    void setNbVoisinesVivantesPourSurvivre(std::vector<int> list);

    bool respecte() override; //ne sert pas forcément, EtatCellule calcul déjà son avenir

    void afficher() override; //affiche les regles mise en place
};

#endif // DEF_REGLE_JEU_VIE