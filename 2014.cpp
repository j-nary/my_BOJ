//BOJ_2014 소수의 곱 [골드 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int K, N;
    cin >> K >> N;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    vector<int> prime;
    for (int i = 0; i < K; i++) {
        int ip; cin >> ip;
        pq.push(ip);
        prime.push_back(ip);
    }

    int cnt = 0;
    long long prev = 0;
    while(1) {
        long long top = pq.top();
        pq.pop();
        while (top == prev) {
            top = pq.top();
            pq.pop();
        }
        prev = top;
        cnt++;
        if (cnt == N) {
            cout << top << '\n';
            break;
        }

        // 마지막에 곱해진 소수 찾기
        int mIdx = 0;
        for (int i = 0; i < K; i++) {
            if (top % prime[i] == 0) mIdx= i;
        }
        for (int i = mIdx; i < K; i++) {
            pq.push(top * prime[i]);
        }
    }
    
}