#include <iostream>
#include <queue>    

using namespace std;

int map[1003][1003];
bool isVis_nbrk[1003][1003];
bool isVis_brk[1003][1003];

typedef struct Track {
    int r;
    int c;
    int depth;
    bool isBrk;
}track;

queue<Track> q;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    q.push({0, 0, 0, 0});
    isVis_nbrk[0][0] = true;

    int cur = 
    while(!q.empty()) {

    }
}