#include <iostream>
#include <string>
#include "graph.h"
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
    path = new int[num];
    adjmatrix = new int*[num];
    for (int i = 0; i < num; i ++) {
        adjmatrix[i] = new int[num];
        path[i] = 0;
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
            if (!check[w] && dist[next] + adjmatrix[next][w] < dist[w]) {
                dist[w] = dist[next] + adjmatrix[next][w];
                path[w] = next;
            }
        }
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

void Graph::PrintShortestPath(int s) {
    PrintShortestPathWeight(s);
    for (int i = 0; i < num; i++) {
        if (i != s) {
            int tmp = 0;
            int tmpArr[num] = {0};
            int cnt = 0;
            tmp = path[i];
            while(tmp != 0) {
                tmpArr[cnt++] = tmp;
                tmp = path[tmp];
            }
            cout << "0 ";
            for (int j = num-1; j >= 0 ; j--) {
                if (tmpArr[j] != 0) {
                    cout << tmpArr[j] << " ";
                }
            }
            cout << i <<endl;
        }
    }
}



int main(void) {
    Graph g;
    
    string filename;
    getline(cin, filename);
    
    g.LoadMatrix(filename);
    g.PrintShortestPath(0);

    return 0;
}
