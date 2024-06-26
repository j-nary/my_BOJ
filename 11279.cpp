//BOJ_11279 최대 힙 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    while(N--) {
        int input;
        cin >> input;

        if (input == 0) {
            if (q.empty()) cout << 0 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        } else {
            q.push(input);
        }
    }
}