#include <Cellule.h>
#include <string>
#include <vector>
class Grille
{
private:
    int largeur, longueur;
    std::vector<std::vector<int>> grille;
    std::string hash;
public:
    Grille(int largeur, int longueur);
    ~Grille();
    std::vector<std::vector<int>> getGrille();
    std::string getHash();
    void calculeHash();
    std::vector<Cellule> getVoisin(Cellule c);

};


