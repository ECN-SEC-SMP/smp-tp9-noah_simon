#include <iostream>
#include <list>
#include "Q3_liste.h"

using namespace std;


void Q3_liste(){
    //Création de la list
    list<int> l = {1, 2, 6, 4, 5, 6, 7, 8};
    int i = 0;

    //it au début de la list
    list<int>::iterator it = l.begin();
    while (it != l.end()){
        if (i == 2)//Detecte quand on est au 2 ème élèment
        {
            it = l.erase(it);// remplace l'iterateur actuelle pas l'iterateur si il etait suprimé
            ++i;//Incrémente l'itérateur
        }
        else
        {
            cout << *it; // Affiche la valeur de l'itérateur
            ++it;
            ++i;
        } 
    }
    cout << "\n";
}




