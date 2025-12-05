#if !defined(DEF_JEU_OBSERVATEUR)
#define DEF_JEU_OBSERVATEUR


#include <string>
#include "Grille.h"

class JeuObservateur
{
public:
    virtual ~JeuObservateur() = default;
    virtual void notifierChangementGrille(Grille& g) =0;
    virtual void notifierFinSimulation(std::string& raison) =0;
};


#endif // DEF_JEU_OBSERVATEUR
