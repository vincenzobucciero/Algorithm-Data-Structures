//Example of writing on file 

#include <iostream>
#include <fstream> //libreria per operazioni di I/O su file
#include <string>

using namespace std;

int main() {
    /*

    //dichiariamo un oggetto della classe ofstream
    ofstream filewrite("file1.txt");    //output file stream e crea un riferimento ad un file su cui scrivere
    filewrite << "HelloWorld by Vincenzo Bucciero!!" << endl;
    filewrite.close();  //chiude il file, dopodichè il file non è piu accessibile
    
    */

    /*

    ifstream fileread("file1.txt");     //input file stream, classe oggetto parametro per il costruttore
    char ch;
    while(fileread.get(ch))     //legge da file
        //il metoodo get memorizza nella variabile passata come argomento 
        //il carattere puntato dalla posizione corrente e sposta il puntatore di una posizione
        cout << ch;
    cout << endl;
    fileread.close();
    
    */

    string filename = "file1.txt", out = "nuovo";
    fstream optfile;    //fstream perchè non sappiamo se è in lettura o scrittura
    optfile.open(filename.c_str(), ios::in);    //ios::in lettura
    char ch;
    optfile.get(ch);
    optfile.close();

    optfile.open(filename.c_str(), ios::in | ios::out);     //lettura or scrittura (operatore pipe | )
    optfile << out << " " << ch << endl;
    optfile.close();

    return 0;
}