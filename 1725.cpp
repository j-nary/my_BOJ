//BOJ_1725 히스토그램 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<unsigned int> hist;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        hist.push_back(input);
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        for (int left = i - 1; left >= 0; left--) {
            if (hist[left] >= hist[i]) cnt++;
            else break;
        }
        for (int right = i + 1; right < N; right++) {
            if (hist[right] >= hist[i]) cnt++;
            else break;
        }

        res = max(res, (int)(cnt * hist[i]));
    }

    cout << res << '\n';
}