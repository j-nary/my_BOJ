#include <iostream>
#include <string>
#include <fstream>
#include "polynomial2.h"
#include <algorithm>

using namespace std;

void Polynomial::SortPolynomial() {
    int tmp = 0;
    for (int i = 0; i < capacity-1; i++)
        for (int j = capacity-1; j > i; j--) {
            if (termArray[j-1].exp < termArray[j].exp){
                swap(termArray[j-1], termArray[j]);
            }
        }
    return;
}

void Polynomial::LoadPolynomial(std::string& filename) {
    ifstream in;
    in.open(filename);
    if (!in.is_open()) {
        cerr << "해당 파일이 없습니다." << endl;
        return;
    }
    in >> capacity;;
    termArray = new Term[capacity];
    int i = 0;
    while (!in.eof()) {
        in >> termArray[i].coef;
        in >> termArray[i].exp;
        i++;
    }
    in.close();
    SortPolynomial();
    return;
}

void Polynomial::PrintPolynomial() {
    for(int i = 0; i < capacity; i++) {
        cout << termArray[i].coef << " " << termArray[i].exp;
        if (i == (capacity-1))
            return;
        else
            cout << ""<< endl;
    }
    return;
}

/*int main(void) {
    Polynomial p;

    string filename;
    getline(cin, filename);

    p.LoadPolynomial(filename);
    p.PrintPolynomial();
    
    return 0;
}*/
