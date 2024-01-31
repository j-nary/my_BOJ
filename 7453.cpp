//BOJ_7453 합이 0인 네 정수 [골드 2]
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

vector<int> Arr, Brr, Crr, Drr;
vector<int> S1, S2;
int ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Arr.push_back(a);
        Brr.push_back(b);
        Crr.push_back(c);
        Drr.push_back(d);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            S1.push_back(Arr[i] + Brr[j]);
            S2.push_back(Crr[i] + Drr[j]);
        }
    }

    // for (auto it = S1.begin(); it != S1.end(); it++) {
    //     int tmp = (it -> first) * (-1);
    //     if (S2.find(tmp) != S2.end()) {
    //         ans += S2[tmp] * it->second;
    //     }
    // }

    sort(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());

    long long left = 0, right = S2.size() - 1;
    long long ans = 0;
    while (left < S1.size() - 1 && right >= 0) {
        if (S1[left] + S2[right] == 0) {
            long long AB = 0, CD = 0;
            long long prev = left;
            while (S1[left] + S2[right] == 0) {
                if (left > S2.size() - 1) break;
                AB++;
                left++;
            }
            while (S1[prev] + S2[right] == 0) {
                if (right < 0) break;
                CD++;
                right--;
            }
            ans += (AB * CD);
        } else if (S1[left] + S2[right] < 0) {
            left++;
        } else {
            right--;
        }

    }
    cout << ans << '\n';
}