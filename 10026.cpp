#include <iostream>

using namespace std;

int N;  
char art[102][102];
int visit[102][102];

void bfs(int r, int c) {
    if (visit[r-1][c] == -1 && r != 0 && art[r][c] == art[r-1][c]) {
        visit[r-1][c] = 1;
        bfs(r-1, c);
    }
    if (visit[r][c-1] == -1 && c != 0 && art[r][c] == art[r][c-1]) {
        visit[r][c-1] = 1;
        bfs(r, c-1);
    }
    if (visit[r][c+1] == -1 && c < N && art[r][c] == art[r][c+1]) {
        visit[r][c+1] = 1;
        bfs(r, c+1);
    }
    if (visit[r+1][c] == -1 && r < N && art[r][c] == art[r+1][c]) {
        visit[r+1][c] = 1;
        bfs(r+1, c);
    }
}
int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> art[i][j];
            visit[i][j] = -1;
        }
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit[i][j] == -1) {
                visit[i][j] = 1;
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << " ";

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            visit[i][j] = -1;
            if (art[i][j] == 'G')
                art[i][j] = 'R';
        }
    
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit[i][j] == -1) {
                visit[i][j] = 1;
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}