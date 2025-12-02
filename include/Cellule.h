#include <vector>
class Cellule
{
private:
    bool etat; // Mort = 0 | Vivant = 1
    bool immune; // Oui = 1 | Non = 0
    std::vector<std::vector<int>> pos;

public:
    Cellule(bool etat, std::vector<std::vector<int>>& position);
    ~Cellule();
    bool getEtat();
    void inverseEtat();
    std::vector<std::vector<int>> getPosition();
    void setPosition(); // Pas sur de ce setter
};

