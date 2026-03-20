#include "Q1_vecteur_entier.h"  
#include "Q2_vecteur_string.h"
#include "Q3_liste.h"
#include "Q4_map.h"
#include "Q5_lire_csv.h"

#include <iostream>

int main() {
    cout << "Q1------------------------" << endl;
    fonction_vecteur_entier();
    cout << "Q2------------------------" << endl;
    Q2_vecteur_string();
    cout << "Q3 -----------------------" << endl;
    Q3_liste();
    cout << "Q4 -----------------------" << endl;
    Q4_map();
    cout << "Q5 -----------------------" << endl;
    Q5_csv();
    
    return 0;
}