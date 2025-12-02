#if !defined(DEF_GRILLE_GRAPHIQUE)
#define DEF_GRILLE_GRAPHIQUE

#include <ElementGraphique.h>
#include <vector>

class GrilleGraphique :public ElementGraphique
{
private:
    std::vector<sf::RectangleShape> cellules_visuelles;
public:
    GrilleGraphique();
    void mettreAJour(const Grille &g) override;
    void dessiner(sf::RenderTarget & t, sf::RenderStates etats) const override;
};




#endif // DEF_GRILLE_GRAPHIQUE