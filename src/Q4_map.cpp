#include <iostream>
#include <list>
#include <map>
#include <array>
#include <string>

#include "Q4_map.h"

using namespace std;

void showYear(map<int,list<string>> &m, int date );
void ajoute_evenement(map<int,list<string>> &m, int date , string intitule);

void Q4_map(){
    array<string,6> event = {"warehouse_mousse", "buffaloDrill les goat", "WEI", "David KO", "soirée K", "Nantes revient officiellement en Bretagne même si elle est déjà en Bretagne dans nos coeurs tmtc"};
    
    map<int,list<string>> mAgenda;
    for (unsigned int i = 2021; i < 2027; i++)
    {
        ajoute_evenement(mAgenda,i,event[i-2021]);
    }

    ajoute_evenement(mAgenda,1, "Naissance du J");
    ajoute_evenement(mAgenda,1998,"Victoire de la france à la coupe du monde !!");
    ajoute_evenement(mAgenda,2023,"J'ai eu mon bac");

    
    for (int year = 1; year < 2027; year++) {
        if (mAgenda[year].empty())
        {
            continue;
        }
        cout << year << " : ";
        showYear(mAgenda, year);
    }
}


void showYear(map<int,list<string>> &m, int date ){
     for(list<string>::iterator it = m[date].begin(); it != m[date].end(); it++){
        cout << *it << ",";
    }
    cout << "\n";
}


void ajoute_evenement(map<int,list<string>> &m, int date , string intitule){
    if (m.find(date) == m.end())
    {
        //Créer la liste puis ajoute l'intitule
        list<string> newYear;
        m[date] = newYear;
        m[date].push_back(intitule);
    }else
    {
        //ajoute l'intitule dans lal iste 
        m[date].push_back(intitule);
    }
}