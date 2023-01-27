//BOJ_2407 조합 [실버 3]
//https://www.acmicpc.net/problem/2407

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
string dp[102][102];
string bigAdd(string n1, string n2) {
    int sum = 0;
    string res;
    while(!n1.empty() || !n2.empty() || sum) {
        if (!n1.empty()) {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty()) {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        res.push_back(sum%10 + '0');
        sum /= 10;
    }
    
    reverse(res.begin(), res.end());
    return res;
}
string Combi(int n, int r) {
    if (dp[n][r] != "") return dp[n][r];
    if (r == 0 || r == n) return dp[n][r] = to_string(1);
    if (r == 1) return dp[n][r] = to_string(n);

    string& ret = dp[n][r];
    return ret = bigAdd(Combi(n-1, r-1), Combi(n-1, r));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    cout << Combi(n, m) << '\n';
}