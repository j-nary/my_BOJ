#include <iostream>
#include <string>
#include <fstream>
#include "polynomial.h"
#include <algorithm>

using namespace std;

void Polynomial::SortPolynomial() {
    sort(termArray, termArray + capacity, [](const auto &a, const auto &b) {
        if (a.exp == b.exp) return a.coef > b.coef;
        return a.exp > b.exp;
    });
}



void Polynomial::LoadPolynomial(std::string& filename) {
    ifstream in;
    in.open(filename);
    if (!in.is_open()) {
        cerr << " ?              ? ." << endl;
        return;
    }
    in >> capacity;;
    termArray = new Term[capacity];
    
    for (int i = 0; i < capacity; i++) {
        in >> termArray[i].coef;
        in >> termArray[i].exp;
    }
    
}

void Polynomial::PrintPolynomial() {
    for(int i = 0; i < capacity; i++) {
        cout << termArray[i].coef << " " << termArray[i].exp << endl;
    }
}

 /*int main(void) {
    Polynomial p;

    string filename;
    getline(cin, filename);

    p.LoadPolynomial(filename);
    p.PrintPolynomial();
    
    return 0;
}
*/