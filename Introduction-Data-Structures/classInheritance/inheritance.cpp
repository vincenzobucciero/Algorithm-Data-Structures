#include <iostream>
using namespace std;

/**
 * L’ ereditarietà è il meccanismo che consente ad una
 * classe di avere accesso ai dati membro di un’altra classe senza doverli ridefinire.
 * 
 * La classe originaria si dice classe base 
 * Le classi che ereditano si dicono classi derivate
*/

class point {
    private:
        double x, y;
    public:
        point(double x, double y) {this->x = x; this->y = y;}   //this all'interno di una classe rappresenta un puntatore alla classe stessa
        void setX(double x);
        void setY(double y);
        double getX();
        double getY();
};

void point::setX(double x) {
    this->x = x;
}
void point::setY(double y) {
    this->y = y;
}
double point::getX() {
    return x;
}
double point::getY() {
    return y;
}

/**
 * Definiamo una classe derivata point3D che rappresenti i punti 
 * nello spazio euclideo utilizzando la classe point e
 * aggiungendovi una nuova coordinata z. 
 * 
 * Abbiamo tre tipi di ereditarietà:
 * -> private (default): metodi e variabili private sono visibili solo da metodi della classe stessa;
 * -> public: metodi e variabili public sono visibili al di fuori della classe stessa;
 * -> protected: metodi e variabili protected sono visibili dai metodi della classe e da metodi 
 *               di classi che ereditano da questa, ma restano inaccessibili dagli oggetti della classe.
*/
class point3d : public point {
    private:
        double z;
    public:
        point3d(double x, double y, double z):point(x,y){z = z;} 
        void setZ(double z);
        double getZ();
};

void point3d::setZ(double z) {
    this->z = z;
}
double point3d::getZ() {
    return z;
}

int main() {

}


