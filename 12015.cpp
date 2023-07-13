//BOJ_12015 가장 긴 증가하는 부분 수열 2 [골드 2]
//이진 탐색을 이용한 LIS 구하기
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int A[1000006];
vector<int> lis;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    lis.push_back(A[0]);
    for (int i = 1; i < N; i++) {
        if (lis.back() < A[i]) {
            lis.push_back(A[i]);
        } else {
            int idx = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
            lis[idx] = A[i];
        }
    }
    
    cout << lis.size() << '\n';
}