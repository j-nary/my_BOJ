//BOJ_25344 행성 정렬 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> v;
int gcd(int A, int B) {
    return B ? gcd(B, A % B) : A;
}
int lcm(int A, int B) {
    return A / gcd(A, B) * B;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N-2; i++) {
        int input; cin >> input;
        v.push_back(input);
    }

    int ans = v[0];
    for (int i = 1; i < N-2; i++) {
        ans = lcm(ans, v[i]);
    }
    cout << ans << '\n';
}