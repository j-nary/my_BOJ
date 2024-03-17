//BOJ_5648 역원소 정렬 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<long long> v;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        reverse(str.begin(), str.end());
        int idx = 0;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == '0') idx = j + 1;
            else break;
        }
        v.push_back(stoll(str.substr(idx)));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}