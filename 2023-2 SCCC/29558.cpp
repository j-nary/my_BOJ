//BOJ_29558 축제 부스 기획하기 1
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, D; cin >> N >> D; //길이가 N, 평균이 D
    //모든 원소값이 서로 다른 정수인 수열을 가장 먼저 외치는 사람 승리
    
    vector<int> v;
    if (N % 2 != 0) v.push_back(D);

    int half = N / 2;
    for (int i = 1; i <= half; i ++) {
        v.push_back(D - i);
        v.push_back(D + i);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}