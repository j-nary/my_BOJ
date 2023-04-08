//BOJ_3908 서로 다른 소수의 합 [골드 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sosuChae[1200];    //false이면 소수
vector<int> sosu;
long long dp[1200][20];
// dp[i][j] : i를 j개의 소수의 합으로 나타낼 수 있는 경우의 수

void dpSolve() {
    //초기값 설정
    dp[0][0] = 1;
    for (int s = 0;  s < sosu.size(); s++) {
        for (int i = 1120; i >= 0; i--) {
            for (int j = 0; j <= 14; j++) {
                //예외조건
                if (dp[i][j] == 0) continue;
                if (i + sosu[s] > 1200) continue;

                dp[i + sosu[s]][j + 1] += dp[i][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //소수 판별하기
    sosuChae[1] = true;
    for (int i = 2; i < 1200; i++) {
        if (sosuChae[i]) continue;
        sosu.push_back(i);
        for (int j = i + i; j < 1200; j += i)
            sosuChae[j] = true;
    }
    
    dpSolve();

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, k; cin >> n >> k;
        cout << dp[n][k] << '\n';
    }
}