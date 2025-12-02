#if !defined(DEF_JEU_OBSERVATEUR)
#define DEF_JEU_OBSERVATEUR

#include <Grille.h>
#include <string>

class JeuObservateur
{
public:
    ~JeuObservateur();
    virtual void notifierChangementGrille(const Grille& g) =0;
    virtual void notifierFinSimulation(const std::string& raison) =0;
};


#endif // DEF_JEU_OBSERVATEUR
