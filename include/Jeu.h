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
    Grille *grille;
    static Regle *regle;

    std::weak_ptr<JeuObservateur> observateur;
    //piste d'amélioration : std::vector<std::weak_ptr<JeuObservateur>>
    //pour avoir plusieurs observateurs

public:
    Jeu();
    ~Jeu();

    void setObservateur(std::weak_ptr<JeuObservateur> observateur);

    static Regle *getRegle();

    DonneesFichierDebut analyserStringFichier(const std::string& s);
    
    //A enlever plus tard, juste pour debug
    void afficherDonneesFichier(const DonneesFichierDebut& donnees) const;
};

#endif // DEF_JEU