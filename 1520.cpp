#include <iostream>

using namespace std;

int arr[505][505];
int dp[505][505];

int pre[505][505];
void inc(int i, int j) {
        if (arr[i][j] > arr[i-1][j]) {  //상
            dp[i-1][j] -= pre[i][j];
            dp[i-1][j] += dp[i][j];
        }
        if (arr[i][j] > arr[i+1][j]) {  //하
            dp[i+1][j] -= pre[i][j];
            dp[i+1][j] += dp[i][j];        
        }
        if (arr[i][j] > arr[i][j-1]) {  //좌
            dp[i][j-1] -= pre[i][j];
            dp[i][j-1] += dp[i][j];
        }
        if (arr[i][j] > arr[i][j+1]) {  //우
            dp[i][j+1] -= pre[i][j];
            dp[i][j+1] += dp[i][j];        
        }
}

void cmp(int i, int j) {
        if (arr[i][j] > arr[i-1][j]) {  //상
            dp[i-1][j] += dp[i][j];
            inc(i-1, j);
            pre[i-1][j] = dp[i-1][j];
        }
        if (arr[i][j] > arr[i+1][j]) {  //하
            dp[i+1][j] += dp[i][j];
            inc(i+1, j);
            pre[i+1][j] = dp[i+1][j];
        }
        if (arr[i][j] > arr[i][j-1]) {  //좌
            dp[i][j-1] += dp[i][j];
            inc(i, j-1);
            pre[i][j-1] = dp[i][j-1];

        }
        if (arr[i][j] > arr[i][j+1]) {  //우
            dp[i][j+1] += dp[i][j];
            inc(i, j+1);
            pre[i][j+1] = dp[i][j+1]; 
        }
}

int main() {
    int M, N;        //세로M, 가로N
    cin >> M >> N;
    

    for (int i = 0; i < M+2; i++)
        for (int j = 0; j < N+2; j++) {
            if (i == 0 || i == M+1 || j ==0 || j== N+1)
                arr[i][j] == 10004;
            else cin >> arr[i][j];
        }

    
    dp[1][1] = 1;
    pre[1][1] = 1;

    for (int i = 1; i < M+1; i++)
        for (int j = 1; j < N+1; j++) {
            cmp(i, j);
        }
    
    for (int i = 1; i < M+1; i++) {
        for (int j = 1; j < N+1; j++) {
            cout << dp[i][j] << "   " ;
        }
        cout << "" << endl;
    }

    cout << dp[M][N] << endl;

}