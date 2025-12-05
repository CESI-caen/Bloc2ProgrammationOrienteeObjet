#if !defined(DEF_FICHIER)
#define DEF_FICHIER

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


class Fichier 
{
private:
        //utile parce qu'on a plusieurs fichiers 1 en entrée, 1 en sauvegarde   
    std::string nom; 
    std::string chemin;

public:
    Fichier(std::string nom, std::string chemin) : nom(nom), chemin(chemin) {}
    ~Fichier();

    std::string getChemin() const;

    std::string getNom() const;

    std::string Lire(); //n'affiche pas directement dans la console mais return le contenue
    void Ecrire(std::string s); //faire en sorte d'ajouter et de pas écraser !!
};

#endif // DEF_FICHIER 