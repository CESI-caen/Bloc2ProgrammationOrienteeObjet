#if !defined(DEF_REGLE_JEU_VIE)
#define DEF_REGLE_JEU_VIE

#include <vector>

#include "Regle.h"


class RegleJeuVie : public Regle
{
private:
    std::vector<int> nb_voisines_vivantes_pour_naitre;
    std::vector<int> nb_voisines_vivantes_pour_survivre;

public:
    RegleJeuVie(std::vector<int> nb_voisines_vivantes_pour_naitre = {3}, std::vector<int> nb_voisines_vivantes_pour_survivre = {2, 3});
    ~RegleJeuVie();

    std::vector<int> getNbVoisinesVivantesPourNaitre() const;
    void setNbVoisinesVivantesPourNaitre(std::vector<int> list = {3});

    std::vector<int> getNbVoisinesVivantesPourSurvivre() const;
    void setNbVoisinesVivantesPourSurvivre(std::vector<int> list = {2, 3});

    //affiche les regles mise en place
    void afficherRegle() override; 
};

#endif // DEF_REGLE_JEU_VIE