#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

pair<long long, long long> dp[102][102];
//{경우의 수, 맨 앞자리가 1인 경우의 수} 

void dpSolve() {
	dp[1][0] = {2, 1};
	dp[2][0].first += dp[1][0].first * 2 - dp[1][0].second;
	dp[2][1].first += dp[1][0].second;
	dp[2][0].second = 1;
	dp[2][1].second = 1;
	
	dp[3][0].first += (dp[2][0].first * 2 - dp[2][0].second);
	dp[3][1].first += dp[2][0].second;
	dp[3][1].first += (dp[2][1].first * 2 - dp[2][1].second);
	dp[3][2].first += dp[2][1].second;
	for (int r = 3; r < 102; r++) {
		for (int c = 0; c < r; c++) {
			if (c == r- 1 || c == r - 2) {
				dp[r][c].second = 1;
			} else {
				for (int k = 0; k <= c; k++) {
					dp[r][c].second += dp[r - (2 + c - k)][k].first;
				}
			}
			dp[r + 1][c].first += (dp[r][c].first * 2 - dp[r][c].second);
			dp[r + 1][c + 1].first += dp[r][c].second;
		}
	}
}
int main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	dpSolve();
	int test_case; cin >> test_case;
	while (test_case--) {
		int N, K; cin >> N >> K;
		cout << dp[N][K].first << '\n';
	}
	
}
