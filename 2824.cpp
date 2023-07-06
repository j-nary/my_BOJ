//BOJ_2824 최대공약수 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;
const int MOD = 1000000000;
vector<int> arr, brr;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        arr.push_back(input);
    }
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int input; cin >> input;
        brr.push_back(input);
    }

    ll ans = 1;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ll g = gcd(arr[i], brr[i]);
            ans *= g;
            arr[i] /= g;
            brr[i] /= g;
            if (ans >= 1e9) {
                ans %= (ll)1e9;
                flag = true;
            }
        }
    }

    if (flag)
        printf("%09lld\n", ans);
    else
        printf("%lld\n", ans);
}