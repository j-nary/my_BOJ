//BOJ_11404 플로이드 [골드 4]
//https://www.acmicpc.net/problem/11404

#include <iostream>

using namespace std;
#define Inf 99999999

int W[102][102];
int D[102][102];

void floyd(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            D[i][j] = W[i][j];
        }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) W[i][j] = 0;
            else W[i][j] = Inf;
        }
    }
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        if (W[s-1][e-1] && W[s-1][e-1] < w) continue;
        W[s-1][e-1] = w;
    }

    floyd(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j< n; j++) {
            if (D[i][j] == Inf) cout << 0 << " ";
            else cout << D[i][j] << " ";
        }
        cout << '\n';
    }
}