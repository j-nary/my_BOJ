#include <iostream>
#include <string>
#include "graph1.h"
#include <fstream>
#include <algorithm>

using namespace std;

void Graph::LoadMatrix(std::string& filename){
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        cerr << "해당 파일이 없습니다." << endl;
        return;
    }

    fin >> num;
    adjmatrix = new int*[num];
    for (int i = 0; i < num; i ++) {
        adjmatrix[i] = new int[num];
    }

    for (int i = 0; i < num; i++) {
        if (fin.eof()) break;
        for (int j = 0; j < num; j++) {
            fin >> adjmatrix[i][j];
        }
    }
    fin.close();
    return;
}

void Graph::PrintMatrix() {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << adjmatrix[i][j] << " ";
        }
        cout << "" << endl;
    }
}


/*
int main(void) {
    Graph g;
    
    string filename;
    getline(cin, filename);
    
    g.LoadMatrix(filename);
    g.PrintMatrix();
    
    return 0;
}
*/