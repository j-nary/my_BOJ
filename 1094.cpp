//BOJ_1094 막대기 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int X; cin >> X;

    vector<int> bar;
    bar.push_back(64);

    while(1) {
        int sum = 0;
        for (int i = 0; i < bar.size(); i++) {
            sum += bar[i];
        }
        if (sum <= X) break;
        sort(bar.begin(), bar.end());
        bar[0] /= 2;
        sum = 0;
        for (int i = 0; i < bar.size(); i++) {
            sum += bar[i];
        }
        if (sum < X) bar.push_back(bar[0]);
    }

    cout << bar.size() << '\n';
}

// 32
// 16 16
// 16 8
// 16 4 4
// 16 4 2 2
// 16 4 2 1 
// -> 2진수로 나타냈을 때 1의 개수