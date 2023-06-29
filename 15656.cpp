//BOJ_15656 N과 M (7) [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
vector<int> vec;
vector<int> p;
// bool chk[10];

void per() {
    if (p.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << p[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        int tmp = vec[i];
        // if (chk[i]) continue;
        p.push_back(tmp);
        // chk[i] = 1;
        per();
        p.pop_back();
        // chk[i] = 0;
        
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());
    per();
}