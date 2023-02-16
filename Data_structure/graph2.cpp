#include <iostream>
#include <string>
#include "graph2.h"
#include <fstream>

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
    check = new int[num];
    dist = new int[num];

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

void Graph::PrintShortestPathWeight(int s) {
    for (int i = 0; i < num; i++) {
        check[i] = false;
        dist[i] = adjmatrix[s][i];
    }
    check[s] = true;
    dist[s] = 0;
    for (int i = 0; i < num-2; i++) {
        int next = Choose(s);
        check[next] = true;
        for (int w = 0; w < num; w++) {
            if (!check[w] && dist[next] + adjmatrix[next][w] < dist[w])
                dist[w] = dist[next] + adjmatrix[next][w];
        }
    }
    for (int i = 0; i < num; i++) {
        cout << dist[i] << endl;
    }
}

int Graph::Choose(int v) {
    int min;
    for (int i = 0; i < num; i++){
        if (!check[i] && i!=v) {
            min = i;
            break;
        }
    }
    for (int i = 0; i < num; i++) {
        if (!check[i] && dist[min] > dist[i])
            min =i;
    }
    return min;
}


int main(void) {
    Graph g;
    
    string filename;
    getline(cin, filename);
    
    g.LoadMatrix(filename);
    int n = g.GetSize();
    for (int i = 0; i < n; i++) {
        g.PrintShortestPathWeight(i);
    }
    return 0;
}
