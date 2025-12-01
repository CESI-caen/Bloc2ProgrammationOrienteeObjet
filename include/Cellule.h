#include <vector>
class Cellule
{
private:
    bool etat;
    std::vector<std::vector<int>> pos;

public:
    Cellule(bool etat, std::vector<std::vector<int>>& position);
    ~Cellule();
    bool getEtat();
    void inverseEtat();
    std::vector<std::vector<int>> getPosition();
    void setPosition();
};
/*
CPP
Cellule::Cellule(bool etat, std::vector<std::vector<int>>& position)
{
}

Cellule::~Cellule()
{
}
*/
