//Example of writing on file 

#include <iostream>
#include <fstream> //libreria per operazioni di I/O su file

using namespace std;

int main() {
    //dichiariamo un oggetto della classe ofstream
    ofstream filewrite("file1.txt");    //output file stream e crea un riferimento ad un file su cui scrivere
    filewrite << "HelloWorld by Vincenzo Bucciero!!" << endl;
    filewrite.close();  //chiude il file, dopodichè il file non è piu accessibile

    return 0;
}