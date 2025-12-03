#if !defined(DEF_GRILLE)
#define DEF_GRILLE

#include <vector>
#include <memory>
#include <string>
#include <Cellule.h>

class Grille
{
private:
    int largeur;
    int longueur;
    std::vector<std::vector<std::unique_ptr<Cellule>>> grille;  // Tableau 2D
    std::size_t hash;
    static std::vector<std::size_t> tableau_hashs;
public:
     

    Grille();
    Grille(int largeur, int longueur);
    ~Grille();
    int getLargeur();
    int getLongueur();
    std::vector<std::size_t> getTableauHash();
    void modifierElementGrille(int i, int j, std::unique_ptr<Cellule>);
    std::vector<std::vector<std::unique_ptr<Cellule>>> &getGrille();
    std::size_t getHash();
    void calculeHash();
    std::vector<const Cellule *> getVoisines(const Cellule &c) const; // Liste de pointeurs vers Cellule 
    int nbVoisineVivant(const Cellule &c) const;
};


#endif // DEF_GRILLE