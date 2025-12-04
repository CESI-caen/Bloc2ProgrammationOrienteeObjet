#if !defined(DEF_JEU)
#define DEF_JEU

#include <memory>
#include <algorithm>

#include "RegleJeuVie.h"
#include "Grille.h"
#include "JeuObservateur.h"
#include "Fichier.h"


class Jeu
{
private:
    Grille grille;
    RegleJeuVie regle;

    std::weak_ptr<JeuObservateur> observateur;
    //piste d'amélioration : std::vector<std::weak_ptr<JeuObservateur>>
    //pour avoir plusieurs observateurs

public:
    Jeu(Grille grille, RegleJeuVie regle) : grille(grille), regle(regle) {}
    ~Jeu();

    void setObservateur(JeuObservateur *observateur);
};

#endif // DEF_JEU