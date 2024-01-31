//BOJ_1715 카드 정렬하기 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> card;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        card.push(input);
    }

    int ans = 0;
    while(card.size() > 1) {
        int a = card.top(); card.pop();
        int b = card.top(); card.pop();
        ans += (a + b);
        card.push(a + b);
    }

    cout << ans << '\n';
}