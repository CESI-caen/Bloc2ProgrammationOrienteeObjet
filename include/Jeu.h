#if !defined(DEF_JEU)
#define DEF_JEU

#include <RegleJeuVie.h>
#include <Grille.h>
#include <JeuObservateur.h>
#include <Fichier.h>
#include <memory> //std::unique_ptd<>, std::weak_ptr<>

class Jeu
{
private:
    Grille g;
    RegleJeuVie r;
    JeuObservateur std::weak_ptr<observateur>;
    //piste d'amélioration : std::vector<std::weak_ptr<JeuObservateur>>
    //pour avoir plusieurs observateurs

public:
    Jeu(Grille grille, RegleJeuVie regle);
    ~Jeu();

    //Logiquement devrait être une méthode de Grille
    bool verifHash(const Fichier &f); //passage par référence pour ne pas faire de copie

    void evoluer();
    void setObservateur(JeuObservateur *observateur);
};







#endif // DEF_JEU