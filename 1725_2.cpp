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

    cout << DC(0, N) << '\n';
}