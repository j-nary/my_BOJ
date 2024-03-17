//BOJ_1456 거의 소수 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool sosu[10000007];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int A, B;
    cin >> A >> B;

    sosu[1] = true;
    for (int i = 2; i * i <= B; i++) {
        if (sosu[i]) continue;
        for (int j = i + i; j <= B; j += i) {
            sosu[j] = true;
        }
    }

    int ans = 0;
    for (int i = 1; i * i <= B; i++) {
        if (i * i < A || sosu[i]) continue;
        if (i == 1) {
            ans++;
            continue;
        }

        int tmp = i;
        while(1) {
            tmp *= i;
            if (tmp >= A && tmp <= B) {
                ans++;
                break;
            }
            if (tmp > B) break;
        }
    }

    cout << ans << '\n';
}

// 1 10 -> 1 2