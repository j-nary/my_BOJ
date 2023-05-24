//BOJ_11062 카드 게임 [골드 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int dp[1003][1003][2];
//dp[s][e][f] : s..e번째 카드만 남아있는 시점에서
//f번째 플레이어부터 시작했을 때 첫 번째 플레이어가 얻게 되는 점수

int game(int s, int e, bool o) {
    if (dp[s][e][o] != -1) return dp[s][e][o];
    if (s == e) {
        if (o) return dp[s][e][o] = v[s];
        else return dp[s][e][o] = 0;
    }

    if (o) return dp[s][e][o] = max(game(s + 1, e, false) + v[s], game(s, e - 1, false) + v[e]);
    else return dp[s][e][o] = min(game(s + 1, e, true), game(s, e - 1, true));
}

void test_case() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }
   cout << game(0, N - 1, true) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        memset(dp, -1, sizeof(dp));
        v.clear();
        test_case();
    }
}