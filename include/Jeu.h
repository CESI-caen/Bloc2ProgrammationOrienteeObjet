#if !defined(DEF_JEU)
#define DEF_JEU

#include <RegleJeuVie.h>
#include <Grille.h>
#include <JeuObservateur.h>
#include <Fichier.h>
class Jeu
{
private:
    Grille g;
    RegleJeuVie r;
    JeuObservateur *observateur;
public:
    Jeu(Grille grille, RegleJeuVie regle);
    ~Jeu();
    bool verifHash();
    void evoluer();
    void setObservateur(JeuObservateur *observateur);
};







#endif // DEF_JEU