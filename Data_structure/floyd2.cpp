#include <iostream>

using namespace std;
#define Inf 999

int P[5][5];

void path(int q, int r) {
    cout << "재귀호출 : P[" << q << "][" << r << "]\n";
    if (P[q][r] != -1) {
        path(q, P[q][r]);
        cout << " v" << P[q][r];
        path(P[q][r], r);
    }
}

void floyd(int n, const int W[5][5], int D[5][5]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            P[i][j] = -1;
            D[i][j] = W[i][j];
        }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        cout << "k = " << k << endl;
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                cout << D[p][q] << " ";
            }
            cout << endl;
        }
        cout<<endl;
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                cout << P[p][q] << " ";
            }
            cout<<endl;
        }
        cout << "_________________________" << endl;
    }
    path(4, 2);
}

int main() {
    int W[5][5] = {{0, 3, Inf, 6, 1},
                {7, 0, 2, Inf, Inf},
                {Inf,Inf, 0, 2, Inf},
                {Inf, Inf, Inf, 0, 5},
                {9, 4, Inf, Inf, 0}};
    int D[5][5];
    floyd(5, W, D);
    cout << endl;
}