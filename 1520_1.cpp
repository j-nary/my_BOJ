#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 500
using namespace std;

int M, N;        //세로M, 가로N
int map[MAX_N + 5][MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];

int DFS(int i, int j) {
    if ( i == M-1 && j == N-1 ) return 1;
    if ( i < 0 || j < 0 || i >= M || j >= N ) return 0;

    if ( dp[i][j] != -1 ) return dp[i][j];

    else {
        int sum = 0;
        if (map[i][j] > map[i-1][j]) {    //상
            sum += DFS(i-1, j);
        }
        if (map[i][j] >map[i+1][j]) {    //하
            sum += DFS(i+1, j);
        }
        if (map[i][j] >map[i][j-1]) {    //좌
            sum += DFS(i, j-1);
        } 
        if (map[i][j] >map[i][j+1]) {    //우
            sum += DFS(i, j+1);
        }                       
        return dp[i][j] = sum;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }

    memset(dp, -1, sizeof(dp));
    cout << DFS(0,0) << '\n';
    /*
    for (int i = 1; i < M+1; i++) {
        for (int j = 1; j < N+1; j++) {
            cout << dp[i][j] << "   " ;
        }
        cout << "" << endl;
    }
    */


}