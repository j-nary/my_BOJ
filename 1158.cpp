//BOJ_1158 요세푸스 문제 [실버 4]

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, K; cin >> N >> K;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    cout << '<';
    while(!q.empty()) {
        for (int i = 0; i < K - 1; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
        else cout << ">\n";
    }
}