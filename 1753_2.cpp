//시간 초과
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 999

int length[20004];
int res[20004];

struct node {
    int x;
    int y;
    int weight;
};

int main() {
    int V, E; cin >> V >> E;
    int start; cin >> start;

    vector<node> W;
    node n;

    for (int i = 0; i < E; i++) {
        cin >> n.x >> n.y >> n.weight;
        W.push_back(n);
    }

    for (int i = 0; i < W.size(); i++) {
        if (W[i].x == start) {
            int tmp = W[i].y;
            length[tmp] = W[i].weight;
        }
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
            int  Widx = -1;
            for (int j = 0; j < W.size(); j++) {
                if (W[j].x == idx)
                    Widx = j;
            }
            if (Widx == -1)
                continue;
            if (W[Widx].y != i)
                continue;
            int tmp = length[idx] + W[Widx].weight;
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