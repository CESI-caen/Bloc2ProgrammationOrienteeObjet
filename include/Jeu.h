#if !defined(DEF_JEU)
#define DEF_JEU

#include <RegleJeuVie.h>
#include <Grille.h>
#include <JeuObservateur.h>
#include <Fichier.h>
#include <memory> //std::unique_ptd<>, std::weak_ptr<>
#include <algorithm> //std::find

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

    //Logiquement devrait être une méthode de Grille
    bool verifHash() const; //utilise l'attribut static tableau_hashs de Grille

    void evoluer();
    void setObservateur(JeuObservateur *observateur);
};







#endif // DEF_JEU