#include "Q2_vecteur_string.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


//focntion qui affiche
void afficher_vector_string(const vector<string> &vs){
    for (auto i : vs) // access by value
        cout << i << ' ';
    cout << '\n';
}

string concatene(const vector<string> &vs){
    string a;
    for (unsigned int  i = 0; i != vs.size(); i++)
    {
        a += vs[i] + " ";
    }
    return a ;
}


void ajoute_virgule(vector<string>* vs){
    for_each(vs->begin(), vs->end(), [](string &s) {
        s+=",";  
    });
    // vs devient s et pour chaque valeur de vs on rajoute un , au texte déjà présent.
}

//Même chose mais avec un foncteur
class Ajoute_virgule
{
public:
    void operator()(vector<string>* vs)
    {
        for_each(vs->begin(), vs->end(), [](string &s) {
            s+=",";  
        });
    }
};


void Q2_vecteur_string(){
    vector<string> vecteurString = {"Bonjour","comment","allez","vous","?"};
    cout << "Taille vecteur : " << vecteurString.size() << endl;
    cout << "Capacité vecteur : " << vecteurString.capacity() << endl;

    vecteurString.push_back("Bien");vecteurString.push_back("bien");

    //Comparaison taile capacité : la taille correspond à son nombre d'élèment et la capacité correspond au nombre d'élèment avant réallocation en mémoire
    cout << "Comparaison taille:capacité : "  << vecteurString.size() << ":" << vecteurString.capacity() << endl;
    
    //Méthode 1 pour afficher le contenu du vecteur :
    for (unsigned int i = 0; i < vecteurString.size(); i++)
    {
        cout << vecteurString[i] << " ";
    }
    cout << endl;


    //Méthode 2 pour afficher le contenu du vecteur :
    for (auto i : vecteurString) // access by value
        cout << i << ' ';
    cout << '\n';


    //Méthode 3 pour afficher le contenu du vecteur :
    for(vector<string>::iterator it = vecteurString.begin(); it != vecteurString.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";


    //Swap :
    swap(vecteurString[1],vecteurString[3]);

    afficher_vector_string(vecteurString);

    //Insertion
    vector<string>::iterator it  = vecteurString.begin() + 1;
    vecteurString.insert(it,"a tous");
    afficher_vector_string(vecteurString);



    //Changer de valeur
    vecteurString[5] = "???";
    afficher_vector_string(vecteurString);

    //style csv:
    for (auto i : vecteurString) // access by value
        cout << i << ',';
    cout << '\n';


    //trie avec sort
    sort(vecteurString.begin(), vecteurString.end());
    afficher_vector_string(vecteurString);


    //concatene
    cout << concatene(vecteurString) << endl;

    vector<string> vecteurString_copy = vecteurString;

    ajoute_virgule(&vecteurString);
    afficher_vector_string(vecteurString);

    //Foncteur :
    Ajoute_virgule add_comma;
    add_comma(&vecteurString_copy);
    afficher_vector_string(vecteurString);
}


