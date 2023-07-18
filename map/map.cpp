/**
 * MAP
 * Sono contenitori di coppie ( key, value ) e possiedono un iteratore
 * bidirezionale. Un esempio di contenitore associativo è map
 * 
 * In map viene richiesto l’operatore < per la chiave
 * Gli elementi sono ordinati secondo la chiave
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    //Creazione della mappa
    map<string, int> amap;
    amap["Primo"] = 1;
    amap["Secondo"] = 2;
    //Size della mappa
    cout << "Size della map:  " << amap.size() << endl;

    amap["Terzo"] = 3;
    amap["Quarto"] = 4;
    //Inserimeto elemento in map
    amap.insert(pair<string, int>(string("Quinto"), 5));
    amap.insert(make_pair("Sesto", 6));
    cout << "Size della map:  " << amap.size() << endl; 

    map<string, int>::iterator it;
    for(it = amap.begin(); it != amap.end(); it++) {
        cout << "map: " << it->first << "\t" << it->second << endl;
    }

    //Ricerca
    cout << amap.find("Terzo")->second << endl;
    cout << amap.at("Quinto") << endl;
    //Se non esiste
    cout << amap.find("Settimo")->second << endl;

    amap.clear();

    return 0;
}