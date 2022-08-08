#include <iostream>
#include <queue>    

using namespace std;

int map[1003][1003];
bool isVisited_non_brk[1003][1003];
bool isVisited_brk[1003][1003];

typedef struct Track {
    int r;
    int c;
    int depth;
    bool isBrk;
}track;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    
}