//BOJ_17298 오큰수 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int ans[1000006];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<int> A;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        A.push_back(input);
    }

    stack<int> S;
    for (int i = N-1; i >= 0; i--) {
        while(!S.empty() && S.top() <= A[i]) S.pop();
        if (S.empty()) ans[i] = -1;
        else ans[i] = S.top();

        S.push(A[i]);
    }

    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << '\n';
}