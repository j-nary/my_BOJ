#include <iostream>
#include <string>
#include "rectangle.h"

using namespace std;

int Rectangle::area() {
    return width * height;
}

int Rectangle::perimeter() {
    return 2*(width + height);
}

int main(void) {
    int w, h;
    cin >> w >> h;
    
    Rectangle r(w, h);
    
    cout << r.area() << endl;
    cout << r.perimeter() << endl;
    
    return 0;
}