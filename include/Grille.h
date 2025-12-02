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
    std::string hash;
public:
    Grille(int largeur, int longueur);
    ~Grille();
    std::vector<std::vector<std::unique_ptr<Cellule>>> getGrille();
    std::string getHash();
    void calculeHash();
    std::vector<std::unique_ptr<Cellule>> getVoisin(Cellule c); // Liste de pointeurs vers Cellule
};


#endif // DEF_GRILLE