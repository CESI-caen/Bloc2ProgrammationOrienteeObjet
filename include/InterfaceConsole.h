#if !defined(DEF_INTERFACE_CONSOLE)
#define DEF_INTERFACE_CONSOLE

#include <JeuObservateur.h>
class InterfaceConsole :public JeuObservateur
{
public:
    void notifierChangementGrille(Grille& g) override;
    void notifierFinSimulation(std::string& raison) override;
};



#endif // DEF_INTERFACE_CONSOLE