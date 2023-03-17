//BOJ_1415 사탕 [골드 1]
//사탕 가격의 합이 소수
//(1, 2, 1, 3, 1), (3, 1, 1, 1, 2) 는 한 가지로 취급
//2차원 배열로 Bottom-up
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool sosu[500005];   //false이면 소수
int N;
long long dp[2][500005];
int cnt[10004];
vector<int> input;
int maxSum;

void dpSolve() {
    //초기값 설정
    int start = input[0];
    for (int i = 1; i <= cnt[start]; i++) {
        dp[0][start * i] ++;
    }

    for (int i = 1; i < N; i++) {
        int idx = input[i];

        for (int k = 0; k <= maxSum; k++) {
            dp[i%2][k] = 0; //초기화
        }

        for (int j = 0; j < idx; j++) {
            dp[i%2][j] = dp[(i-1)%2][j];
        }

        for (int j = idx; j <= maxSum; j++) {
            for (int k = 0; k <= cnt[idx]; k++) {
                int tmp = j - idx* k;
                if (tmp < 0) break;
                else dp[i%2][j] += dp[(i-1)%2][tmp];

                if (tmp == 0) dp[i%2][j]++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N;    // 1 <= N <= 50
    //0 <= 가격 <= 10,000
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        input.push_back(tmp);
        cnt[tmp]++;
        maxSum += tmp;
    }

    sort(input.begin(), input.end());
    input.erase(unique(input.begin(), input.end()), input.end());
    N = input.size();
    //소수판별
    sosu[1] = sosu[0] = true;
    for (int i = 0; i * i < 500005; i++) {
        if (sosu[i]) continue;
        for (int j = i + i; j < 500005; j += i) {
            sosu[j] = true;
        }
    }

    dpSolve();
    long long res = 0;
    for (int i = 1; i <= maxSum; i++) {
        if (sosu[i]) continue;
        res += dp[(N-1)%2][i];
    }
    cout << res << '\n';
}