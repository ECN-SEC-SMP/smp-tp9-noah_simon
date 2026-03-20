#include "Q5_lire_csv.h"

using namespace std;

csv::csv() {}

void csv::ajoute_evenement(int date, const string& intitule) {
    if (agenda.find(date) == agenda.end()) {
        list<string> nouvelleListe;
        agenda[date] = nouvelleListe;
    }
    agenda[date].push_back(intitule);
}

void csv::affiche() const {
    for (map<int, list<string>>::const_iterator itMap = agenda.begin(); itMap != agenda.end(); ++itMap) {
        cout << itMap->first << " : ";
        for (list<string>::const_iterator itList = itMap->second.begin(); itList != itMap->second.end(); ++itList) {
            cout << *itList;
            list<string>::const_iterator nextIt = itList;
            ++nextIt;
            if (nextIt != itMap->second.end()) {
                cout << " | ";
            }
        }
        cout << endl;
    }
}

bool csv::lire(const string& nomFichier) {
    ifstream fichier(nomFichier.c_str());
    if (!fichier.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << nomFichier << endl;
        return false;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        if (ligne.empty()) {
            continue;
        }

        size_t pos = ligne.find(';');
        if (pos == string::npos) {
            cerr << "Ligne invalide ignoree : " << ligne << endl;
            continue;
        }

        string dateStr = ligne.substr(0, pos);
        string description = ligne.substr(pos + 1);

        int date = stoi(dateStr);
        ajoute_evenement(date, description);
    }

    fichier.close();
    return true;
}

bool csv::ecrire(const string& nomFichier) const {
    ofstream fichier(nomFichier.c_str());
    if (!fichier.is_open()) {
        cerr << "Erreur : impossible de creer le fichier " << nomFichier << endl;
        return false;
    }

    for (map<int, list<string>>::const_iterator itMap = agenda.begin(); itMap != agenda.end(); ++itMap) {
        for (list<string>::const_iterator itList = itMap->second.begin(); itList != itMap->second.end(); ++itList) {
            fichier << itMap->first << ";" << *itList << endl;
        }
    }

    fichier.close();
    return true;
}

const map<int, list<string>>& csv::getAgenda() const {
    return agenda;
}

void Q5_csv() {
    csv fichierCSV;

    // Ajout manuel d'événements
    fichierCSV.ajoute_evenement(2021, "warehouse_mousse");
    fichierCSV.ajoute_evenement(2022, "buffaloDrill les goat");
    fichierCSV.ajoute_evenement(2023, "WEI");
    fichierCSV.ajoute_evenement(2024, "David KO");
    fichierCSV.ajoute_evenement(2025, "soiree K");
    fichierCSV.ajoute_evenement(2026, "Nantes revient officiellement en Bretagne");

    cout << "=== Affichage avant ecriture ===" << endl;
    fichierCSV.affiche();

    // Écriture dans un fichier CSV
    fichierCSV.ecrire("agenda.csv");

    // Lecture dans un autre objet pour test
    csv lectureCSV;
    lectureCSV.lire("agenda.csv");

    cout << endl << "=== Affichage apres lecture ===" << endl;
    lectureCSV.affiche();
}