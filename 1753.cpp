//메모리 초과

#include <iostream>
#include <algorithm>

using namespace std;

#define INF 999

int W[20004][20004];
int length[20004];
int res[20004];

int main() {
    int V, E; cin >> V >> E;
    int start; cin >> start;

    for (int i = 0; i <= V; i++) {
        for (int j = 0; j <= V; j++) {
            W[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        W[u][v] = w;
    }

    for (int i = 1; i <= V; i++) {
        length[i] = W[start][i];
    }

    while(1) {
        int idx = 1, value = length[idx];
        for (int i = 2; i <= V; i++) {
            if (length[i] < length[idx]) {
                idx = i;
                value = length[i];
            }
        }
        if (value == INF) break;
        res[idx] = value;

        for (int i = 1; i <= V; i++) {
            int tmp = length[idx] + W[idx][i];
            if (tmp < length[i]) {
                length[i] = tmp;
            }
        }

        length[idx] = INF;
    }

    for (int i = 1; i <= V; i++) {
        if (i == start)
            cout << "0" << endl;
        else if (res[i] == INF)
            cout << "INF" <<endl;
        else
            cout << res[i] << endl;
    }
}