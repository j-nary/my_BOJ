#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Track {
    int r;
    int c;
    int depth;
    bool isBrk;
};

int map[1003][1003];
bool isVis_nbrk[1003][1003];
bool isVis_brk[1003][1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            map[i][j] = tmp[j] - '0';
        }
    }

    queue<Track> q;
    q.push({0, 0, 0, 0});
    isVis_nbrk[0][0] = true;
    
    while (!q.empty()) {
        
    }
}