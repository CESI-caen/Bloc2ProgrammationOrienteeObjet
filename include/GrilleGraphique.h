#if !defined(DEF_GRILLE_GRAPHIQUE)
#define DEF_GRILLE_GRAPHIQUE

#include "ElementGraphique.h"
#include <vector>

class GrilleGraphique :public ElementGraphique
{
private:
    std::vector<std::vector<sf::RectangleShape>> cellules_visuelles;
    float tailleCellule;
    sf::Color couleurVivante;
    sf::Color couleurMorte;
    sf::Color couleurObstacleMorte;
    sf::Color couleurObstacleVivante;
public:
    GrilleGraphique();
    float getTailleCellule() const;
    void mettreAJour(const Grille &g) override;
    void draw(sf::RenderTarget &t, sf::RenderStates etats) const override;
};




#endif // DEF_GRILLE_GRAPHIQUE