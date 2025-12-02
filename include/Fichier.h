#if !defined(DEF_FICHIER)
#define DEF_FICHIER

#include <iostream>
#include <string>
#include <fstream>

using str = std::string;

class Fichier 
{
private:
    str nom; //utile parceque on a plrs fichiers 1 en entrée, 1 en sauvegarde   
    str chemin;

public:
    Fichier(str nom, str chemin) : nom(nom), chemin(chemin) {}
    ~Fichier();

    str getChemin(void) const;

    str getNom() const;

    str Lire(); //affiche directement dans la console mais return aussi le contenue
    void Ecrire(str s); //faire en sorte d'ajouter et de pas écraser !!
};

#endif // DEF_FICHIER`