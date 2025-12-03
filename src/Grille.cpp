#include <memory>
#include <EtatCellule.h>
#include <Grille.h>
#include <iostream>


Grille::Grille(){
    int largeur = 2 ;
    int longueur = 5 ;

    for(int i = 0 ; i < largeur ;i++ ){
        for(int j = 0 ; j < longueur ; j++){
            this->grille[i][j] = std::make_unique<Cellule>(i, j ,std::unique_ptr<EtatCellule>());
        }
    } 
}
Grille::Grille(int largeur, int longueur){
this->largeur = largeur;
this->longueur =longueur;
for(int i = 0 ; i < largeur ;i++ ){
    for(int j = 0 ; j < longueur ; j++){
        this->grille[i][j] = std::make_unique<Cellule>(i, j ,std::unique_ptr<EtatCellule>());
    }
}
}
Grille::~Grille(){
    std::cout << "Destructeur Grille" <<std::endl;
}
int Grille::getLargeur(){
    return this->largeur;
}
int Grille::getLongueur(){
    return this-> longueur;
}
std::vector<std::size_t>  Grille::getTableauHash(){
    return this->tableau_hashs;
}
void modifierElementGrille(int i, int j, std::unique_ptr<Cellule>){

}
std::vector<std::vector<std::unique_ptr<Cellule>>> &Grille::getGrille(){
    return this->grille;
}
std::size_t Grille::getHash(){
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
std::vector<const Cellule *> Grille::getVoisines(const Cellule &c) const{
    std::vector<const Cellule *> voisins;
    const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int x = c.getX();
    int y = c.getY();
    for (int i = 0; i < 8; i++) {
        int nx = (x + dx[i] + this->largeur) % this->largeur;
        int ny = (y + dy[i] + this->longueur) % this->longueur;
        voisins.push_back(grille[ny][nx].get());
    }
    return voisins; 
}

int Grille::nbVoisineVivant(const Cellule &c) const {
    int compteur = 0;
    std::vector<const Cellule*> voisins = getVoisines(c);
    for (const Cellule* voisin : voisins) {
        if (voisin->estVivant()) {
            compteur++;
        }
    }
    return compteur;
}
