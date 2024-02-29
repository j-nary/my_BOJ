//BOJ_11866 요세푸스 문제 0 [실버 5]
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }   

    cout << "<";
    while(!q.empty()) {
        for (int i = 0; i < K - 1; i++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << ">\n";
}