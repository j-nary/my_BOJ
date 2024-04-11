//BOJ_3896 소수 사이 수열 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
const int maxValue = 12999709;
bool sosu[13000006];
int test_case() {
    int K; cin >> K;
    if (K == 1 || !sosu[K]) return 0;
    
    int minIdx = 2, maxIdx = maxValue;
    for (int i = K; i > 1; i--) {
        if (!sosu[i]) {
            minIdx = i;
            break;
        }
    }

    for (int i = K; i <= maxValue; i++) {
        if (!sosu[i]) {
            maxIdx = i;
            break;
        }
    }
    return maxIdx - minIdx;
}
// 7 8 9 10 11
// 23 24 25 26 27 28 29
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    sosu[1] = true;
    for (int i = 2; i <= maxValue; i++) {
        if (sosu[i]) continue;
        for (long long j = (long long)i * i; j < maxValue; j += i) {
            sosu[j] = true;
        }
    }
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << test_case() << '\n';
    }
}