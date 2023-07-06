//BOJ_17245 서버실 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int com[1003][1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    long long stn = 0;
    int left = 0, right = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> com[i][j];
            stn += com[i][j];
            right = max(right, com[i][j]);
        }
    }
    stn = round(stn/2.0);

    int ans = 10000007;
    while (left <= right) {
        int mid = (left + right) / 2;
        
        long long cnt = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (com[i][j] >= mid) {
                    cnt += mid;
                } else {
                    cnt += com[i][j];
                }
            }
        }
        if (cnt >= stn) {
            ans = min(ans, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << '\n';
}