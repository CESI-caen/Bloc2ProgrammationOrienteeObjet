#if !defined(DEF_GRILLE)
#define DEF_GRILLE

#include <vector>
#include <memory>
#include <string>

#include "Cellule.h"
#include "Regle.h"


struct DonneesFichierDebut {
    int largeur;
    int longueur;
    //int plus facile ici, seront lu pour devenir des unique_ptr<Cellule> dans Grille::evoluer()
    std::vector<std::vector<int>> grille_debut; 
};

class Grille
{
private:
    int largeur;
    int longueur;

    //Tableau 2D avec comme contenue de unique_ptr de Cellule
    std::vector<std::vector<std::unique_ptr<Cellule>>> grille;

    std::size_t hash;

    static std::vector<std::size_t> tableau_hashs;
    
    Regle* regle; // Règle du jeu à appliquer

public:
    Grille(std::string largeur, std::string longueur, Regle* regle = nullptr);
    Grille(DonneesFichierDebut donnees, Regle* regle = nullptr);
    ~Grille();

    int getLargeur() const;
    int getLongueur() const;

    std::size_t getHash();
    void calculeHash();

    std::vector<std::vector<std::unique_ptr<Cellule>>> &getGrille();
    const std::vector<std::vector<std::unique_ptr<Cellule>>> &getGrille() const;

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