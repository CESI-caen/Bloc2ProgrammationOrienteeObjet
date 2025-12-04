#include <memory>
#include <iostream>

#include "EtatCellule.h"
#include "EtatMort.h"
#include "Grille.h"
#include "Fichier.h"
    
std::vector<std::size_t> Grille::tableau_hashs;

Grille::Grille() {
    Fichier f("fichier1", "../grille_debut.txt");
    std::string s = f.Lire();
    this->largeur = largeur;
    this->longueur =longueur;

    grille.resize(largeur);
    for (int i = 0; i < largeur; i++) {
        grille[i].resize(longueur);
    }

    for(int i = 0 ; i < largeur ;i++ ){
        for(int j = 0 ; j < longueur ; j++){
            this->grille[i][j] = std::make_unique<Cellule>(i, j, std::make_unique<EtatMort>());
        }
    }
}

Grille::~Grille() {
    std::cout << "Destructeur Grille" <<std::endl;
}

int Grille::getLargeur() {
    return this->largeur;
}

int Grille::getLongueur() {
    return this-> longueur;
}

std::vector<std::size_t>  Grille::getTableauHash() {
    return this->tableau_hashs;
}

void Grille::modifierElementGrille(int i, int j, std::unique_ptr<Cellule>) {}

std::vector<std::vector<std::unique_ptr<Cellule>>> &Grille::getGrille() {
    return this->grille;
}

std::size_t Grille::getHash() {
    return this->hash;
}

void Grille::calculeHash() {
    std::string temp_string;

    for (int i = 0; i < this->largeur; i++) {
        for (int j = 0; j < this->longueur; j++) {
            temp_string += (this->grille[i][j] ? "1" : "0");
        }
        temp_string += ";"; 
    }

    std::cout << "String représentant la grille : " << temp_string << std::endl;

    std::size_t H = std::hash<std::string>{}(temp_string);
    std::cout << "Hash = " << H << std::endl;

    this->tableau_hashs.push_back(H);
    this->hash = H;
}

std::vector<Cellule *> Grille::voisines(const Cellule &c) const {
    std::vector<Cellule *> voisins;

    const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    int x = c.getX();
    int y = c.getY();

    for (int i = 0; i < 8; i++) {
        int nx = (x + dx[i] + this->largeur) % this->largeur;
        int ny = (y + dy[i] + this->longueur) % this->longueur;
        voisins.push_back(grille[nx][ny].get());
    }
    return voisins; 
}

int Grille::nbVoisineVivante(std::vector<Cellule *> list) const {
    int compteur = 0;

    for (std::size_t i = 0; i < list.size(); i++) {
        if (list[i]->estVivante()) {
            compteur ++;
        }
    }
    return compteur;
}

bool Grille::verifHash() const {
    if (std::find(this->tableau_hashs.begin(), this->tableau_hashs.end(), this->hash) != this->tableau_hashs.end()) {return true;}
    else {return false;}
}

void Grille::evoluer() {
    /*
    1. parcourir la grille existance
    2. calculer le nouvelle etat de chaque cellule
    3. enregistrer ce nouvelle etat dans une nouvelle grille
    4. move la nouvelle grille dans l'attribut grille
    */

    Grille g_temp(this->largeur, this->longueur);

    for (int i = 0; i < largeur; i++) {
        for (int j = 0; j < longueur; j++) {

            Cellule& c = *grille[i][j];
            auto v = voisines(c);
            int nb = nbVoisineVivante(v);

            g_temp.grille[i][j]->calculerProchaineEtat(nb);
        }
    }

    // on remplace l’ancienne grille par la nouvelle
    grille = std::move(g_temp.grille);
}
