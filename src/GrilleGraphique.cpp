#include "GrilleGraphique.h"

GrilleGraphique::GrilleGraphique() {
    tailleCellule = 20;
    couleurVivante = sf::Color::White;
    couleurMorte = sf::Color::Black;
}

void GrilleGraphique::mettreAJour(const Grille &g) {
    int largeur = g.getLargeur();
    int longueur = g.getLongueur();
    
    cellules_visuelles.clear();
    // CORRECTION: grille[longueur][largeur]
    cellules_visuelles.resize(longueur);
    for (int i = 0; i < longueur; i++) {
        cellules_visuelles[i].resize(largeur);
    }

    // CORRECTION: i = ligne (longueur), j = colonne (largeur)
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) {
            sf::RectangleShape rect(sf::Vector2f(tailleCellule, tailleCellule));
            // CORRECTION: Inversion des coordonnées pour l'affichage (j=colonne, i=ligne)
            rect.setPosition(j * tailleCellule, i * tailleCellule);
            // CORRECTION: Accès à la grille (i=ligne, j=colonne)
            rect.setFillColor(g.getGrille()[i][j]->estVivante() ? couleurVivante : couleurMorte);
            
            // Ajouter une bordure fine grise pour séparer les cellules
            rect.setOutlineThickness(1.f);
            rect.setOutlineColor(sf::Color(50, 50, 50)); // Gris foncé
            
            cellules_visuelles[i][j] = rect;
        }
    }
}

void GrilleGraphique::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < cellules_visuelles.size(); i++) {
        for (int j = 0; j < cellules_visuelles[i].size(); j++) {
            target.draw(cellules_visuelles[i][j], states);
        }
    }
}
