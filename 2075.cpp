//BOJ_2075 N번째 큰 수 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int ip; cin >> ip;
            if (pq.size() < N) pq.push(ip);
            else if (pq.top() < ip) {
                    pq.pop();
                    pq.push(ip);
            }
        }
    }

    cout << pq.top() << '\n';
}