#if !defined(DEF_JEU_OBSERVATEUR)
#define DEF_JEU_OBSERVATEUR

#include <Grille.h>
#include <string>

class JeuObservateur
{
public:
    virtual ~JeuObservateur() = default;
    virtual void notifierChangementGrille(Grille& g) =0;
    virtual void notifierFinSimulation(std::string& raison) =0;
};


#endif // DEF_JEU_OBSERVATEUR
