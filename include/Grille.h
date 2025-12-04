#if !defined(DEF_GRILLE)
#define DEF_GRILLE

#include <vector>
#include <memory>
#include <string>

#include "Cellule.h"


class Grille
{
private:
    int largeur;
    int longueur;

    //Tableau 2D avec comme contenue de unique_ptr de Cellule
    std::vector<std::vector<std::unique_ptr<Cellule>>> grille;

    std::size_t hash;

    static std::vector<std::size_t> tableau_hashs;

public:
    Grille();
    ~Grille();

    int getLargeur();
    int getLongueur();

    std::size_t getHash();
    void calculeHash();

    std::vector<std::vector<std::unique_ptr<Cellule>>> &getGrille();

    void modifierElementGrille(int i, int j, std::unique_ptr<Cellule>);

    std::vector<std::size_t> getTableauHash();

    //Liste de pointeurs vers des Cellule
    std::vector<Cellule *> voisines(const Cellule &c) const;

    //prendra en parametre la sorie de getVoisines()
    int nbVoisineVivante(std::vector<Cellule *> list) const;

    //utilise l'attribut static tableau_hashs de Grille
    bool verifHash() const; 
    void evoluer();
};

#endif // DEF_GRILLE