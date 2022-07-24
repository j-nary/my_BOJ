#include <iostream>

using namespace std;

int dp[30][30];

int combination(int M, int N) {
    if (N == 0) return dp[M][N] = 1;
    else if (N == 1) return dp[M][N] = M;
    else if (N == M) return dp[M][N] = 1;

    if (dp[M][N] != 0) return dp[M][N];
    else return dp[M][N] = combination(M-1, N) + combination(M-1, N-1);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    //cout << "T=" << T << endl;
    unsigned long long N, M;
    unsigned long long res;

    while(T--) {
        cin >> N; cin >> M;
        //cout << "why" << endl;
        cout << combination(M, N) << endl;
       //cout << "ha......." << endl;
    }

    return 0;
}