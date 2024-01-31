//BOJ_1927 최소 힙 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (long long int a, long long int b) {
        return abs(a) == abs(b) ? a > b : abs(a) > abs(b);
    }
};
priority_queue<long long int, vector<long long int>, cmp> q;
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