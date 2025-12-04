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
    std::unique_ptr<Grille> grille;
    static Regle* regle;

    std::weak_ptr<JeuObservateur> observateur;
    //piste d'amélioration : std::vector<std::weak_ptr<JeuObservateur>>
    //pour avoir plusieurs observateurs

public:
    Jeu(Regle* r = nullptr);
    ~Jeu();

    void setObservateur(std::weak_ptr<JeuObservateur> observateur);

    static Regle* getRegle();

    DonneesFichierDebut analyserStringFichier(const std::string& s);
    
};

#endif // DEF_JEU