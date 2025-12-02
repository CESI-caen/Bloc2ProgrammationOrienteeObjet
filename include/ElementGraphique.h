#if !defined(DEF_ELEMENT_GRAPHIQUE)
#define DEF_ELEMENT_GRAPHIQUE

#include <Grille.h>
#include <SFML/Graphics.hpp>


class ElementGraphique :public sf::Drawable
{
public:
    virtual void mettreAJour(const Grille &g) =0;
    virtual void dessiner(sf::RenderTarget & t, sf::RenderStates etats) const =0;
};


#endif // DEF_ELEMENT_GRAPHIQUE