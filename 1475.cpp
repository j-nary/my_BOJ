//BOJ_1475 방번호 [실버 5]
//
#include <bits/stdc++.h>

using namespace std;

int maxLen[10];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    string str = to_string(N);
    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        int sub = str[i] - '0';
        if (sub == 6 || sub == 9) tmp++;
        else maxLen[sub]++;
        ans = max(ans, maxLen[sub]);
    }

    tmp = (tmp + 1) / 2;
    ans = max(tmp, ans);
    cout << ans << '\n';

}