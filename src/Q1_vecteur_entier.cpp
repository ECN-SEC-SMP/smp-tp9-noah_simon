#include "Q1_vecteur_entier.h"
#include <vector>
#include <iostream>

using namespace std;

int fonction_vecteur_entier(){

    // vecteur d'entiers vide
    vector<int> victor;

    // on réserve 3 cases
    victor.resize(3);

    // on met des valeurs dedans
    victor[0] = 10;
    victor[1] = 20;
    victor[2] = 30;

    // affichage avec les indices
    cout << "affichage avec indice" << endl;
    for (int i = 0; i < victor.size(); i++){
        cout << "indice:" << i << " = " << victor[i] << endl;
    }

    // affichage simple avec boucle sur le vecteur
    cout << "affichage avec boucle sur plage" << endl;
    for (int i : victor){
        cout << "valeur:" << i << endl;
    }

    // affichage avec un iterateur (ancienne methode)
    cout << "affichage avec iterateur" << endl;
    vector<int>::iterator it;
    for (it = victor.begin(); it != victor.end(); it++){
        cout << "valeur:" << *it << endl;
    }

    // ajout d'une valeur a la fin
    it = victor.end();
    victor.insert(it, 40);

    // taille apres ajout
    cout << "nouvelle taille de victor apres ajout: " << victor.size() << endl;

    // copie du vecteur
    vector<int> petitFrereDeVictor;
    petitFrereDeVictor = victor;

    // verification de la copie
    cout << "verification que victor a bien ete copie" << endl;
    for (int i : petitFrereDeVictor){
        cout << "valeur:" << i << endl;
    }


    return 0;
}