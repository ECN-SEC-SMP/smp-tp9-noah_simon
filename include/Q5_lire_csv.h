#ifndef Q5_CSV_H
#define Q5_CSV_H

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>

class csv {
private:
    std::map<int, std::list<std::string>> agenda;

public:
    // Constructeur
    csv();

    // Ajouter un événement dans la map
    void ajoute_evenement(int date, const std::string& intitule);

    // Afficher tout le contenu
    void affiche() const;

    // Lire un fichier CSV au format : date;description
    bool lire(const std::string& nomFichier);

    // Écrire le contenu de la map dans un fichier CSV
    bool ecrire(const std::string& nomFichier) const;

    // Accesseur si besoin
    const std::map<int, std::list<std::string>>& getAgenda() const;
};

// Fonction de test de la question 5
void Q5_csv();

#endif