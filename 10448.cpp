//BOJ_10448 유레카 이론 [브론즈 1]
//Brute-force Search 연습
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> v;
vector<int> input;
bool ans[1000006];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 1; i <= 1000; i++) {
        int tmp = i * (i + 1) / 2;
        if (tmp > 1000) break;
        v.push_back(tmp);
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            for (int k = 0; k < v.size(); k++) {
                ans[v[i] + v[j] + v[k]] = true;
            }
        }
    }

    int N; cin >> N;
    for (int i = 0; i < N; i++){
        int input; cin >> input;
        cout << ans[input] << '\n';
    }
} 