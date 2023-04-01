//BOJ_2613 숫자구슬 [골드 2]
//Dynamic Programming 으로 풀기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[302][302];
//dp[i][j] : i ~ n까지의 구술을 k개로 묶었을 때의 최적값
vector<int> v;
int N;
void path(int max, int M) {
    int cnt = 1;
    int sum = 0;
    vector<int> idx;
    for (int i = 0; i < N; i++) {
        sum += (v[i] - v[i - 1]);
        if (sum > max) {
            idx.push_back(i-1);
            cnt++;
            sum = 0;
            i--;
        }
    }
    if (cnt == M) {
        idx.push_back(N - 1);
    } else if (cnt < M) {
        int sz = M - cnt;
        while (idx.size() != M - 1) {
            if (idx.back() == idx.size() - 1) {
                idx.push_back(idx.size());
                continue;
            }
            for (int i = 0; i < idx.size(); i++) {
                if (idx.size() == M - 1) break;
                if (i == 0 && idx[i] >= 1) {
                    idx[i]--;
                    idx.insert(idx.begin() + i + 1, idx[i] + 1);
                    i--;
                } else if (idx[i] - idx[i - 1] >= 2) {
                    idx[i]--;
                    idx.insert(idx.begin() + i + 1, idx[i] + 1);
                    i--;
                }
            }
        }
        idx.push_back(N - 1);
    }

    for (int i = 0; i < M; i++) {
        if (i == 0) cout << idx[i] + 1 << " ";
        else cout  << idx[i] - idx[i - 1] << " ";
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int M; cin >> N >> M;
    int input; cin >> input;
    v.push_back(input);
    for (int i = 1; i < N; i++) {
        cin >> input;
        v.push_back(input + v[i-1]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= i + 1; j++) {
            if (i == 0 && j == 1) {
                dp[i][j] = v[0];
                continue;
            }
            if (j == 1) {
                dp[i][j] = dp[i - 1][j] + v[i] - v[i - 1];
                continue;
            }

            dp[i][j] = max(dp[i - 1][j - 1], v[i] - v[i - 1]);
            for (int k = i - 2; k + 2 >= j; k--) {
                int tmp = max(dp[k][j - 1], v[i] - v[k]);
                if (tmp < dp[i][j]) dp[i][j] = tmp;
            }
        }
    }

    cout << dp[N - 1][M] << '\n';
    path(dp[N - 1][M], M);
    cout << '\n';
}