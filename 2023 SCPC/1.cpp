//증강현실 배달 안경
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int test_case() {
    int N, A, B; cin >> N >> A >> B;
    if (A > B) swap(A, B);
    
    // int left = 0, right = N;
    int ans = 0;
    // while (left <= right) {
    //     int mid = (left + right) / 2;
    //     int tmp = N - (A * mid);
    //     if (tmp % B == 0) {
    //         ans = max(ans, mid + tmp/B);
    //         left = mid + 1;
    //     } else {
    //         right = mid - 1;
    //     }
    // }
    int mIdx = N / A;
    for (int i = mIdx; i >= 0; i --) {
        int tmp = N - i * A;
        if (tmp % B == 0) {
            tmp = i + (tmp / B);
            ans = max(ans, tmp);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << '\n';
        cout << test_case() << '\n';
    }
}