//vector sum using the operator overload +

#include <iostream>

using namespace std;

class Point {
    private:
        double x, y;
    public:
        Point(double X, double Y) { this->x = X; this->y = Y; }
        Point() { x = y = 0.0; }
        void setX(double X) { this->x = X; }
        void setY(double Y) { this->y = Y; }
        double getX() { return x; }
        double getY() { return y; }

        //vector increment
        void operator+= (Point p2) {
            this->x += p2.getX();
            this->y += p2.getY();
        }
};

/*
    //vector sum

    Point operator+ (Point p1, Point p2) {
    Point tmp;
    tmp.setX(p1.getX() + p2.getX());
    tmp.setY(p1.getY() + p2.getY());
    
    return tmp;
}
*/

int main() {
    Point a(12.78, 33.45), b(2.55, 3.887);
    Point c;

    for(int i = 0; i < 5; i++) {
        a += b;
        cout << a.getX() << " , " << a.getY() << endl;
    }

    return 0;
}