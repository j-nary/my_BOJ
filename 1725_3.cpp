//BOJ_1725 히스토그램 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> hist;
int square(int s, int e) {
    //기저 조건
    if (s >= e) return 0;
    if (e - s == 1) return hist[s];

    //양쪽 구간 최댓값
    int mid = (s + e) / 2;
    int ret = max(square(s, mid), square(mid, e));

    //걸쳐있는 구간 최댓값
    int w = 1, h = hist[mid], l = mid, r = mid;
    while (r - l <= e - s) {
        int p = l > s ? min(h, hist[l - 1]) : -1;   //왼쪽 확장 시의 높이
        int q = r < e - 1 ? min(h, hist[r + 1]) : -1;   //오른쪽 확장 시의 높이

        //더 높은 쪽으로 확장
        if (p >= q) {
            h = p;
            l--;
        } else {
            h = q;
            r++;
        }
        ret = max(ret, ++w * h);
    }

    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int ip; cin >> ip;
        hist.push_back(ip);
    }
    cout << square(0, N) << '\n';
}