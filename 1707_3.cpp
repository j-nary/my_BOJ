#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define RED 1
#define BLUE 2

int vtx, edg;
vector<vector<int>> v;
int isVis[20004];

void DFS(int cur) {
    if (!isVis[cur]) isVis[cur] = RED;

    for (int i = 0; i < v[cur].size(); i++) {
        int nxt = v[cur][i];
        if (!isVis[nxt]) {
            if(isVis[cur] == RED)   isVis[nxt] = BLUE;
            else if(isVis[cur] == BLUE) isVis[nxt] = RED;            
            DFS(nxt);
        }
    }
}


void test_case() {
    v.clear();
    memset(isVis, 0, sizeof(isVis));
    cin >> vtx >> edg;
    v.assign(vtx + 1, vector<int>(0, 0));
    for (int i = 0; i < edg; i++) {
        int dt1, dt2;
        cin >> dt1 >> dt2;
        v[dt1].emplace_back(dt2);
        v[dt2].emplace_back(dt1);
    }

    for (int i = 1; i <= vtx; i++) {
        if (!isVis[i]) DFS(i);
    }

    for (int i = 1; i <= vtx; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int nxt = v[i][j];
            if (isVis[i] == isVis[nxt]) {
                cout << "NO" <<'\n';
                return;
            }
        }
    }
    cout << "YES" <<'\n';
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}