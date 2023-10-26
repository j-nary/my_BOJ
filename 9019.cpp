//BOJ_9019 DSLR [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;
const int MOD = 10000;
pair<int, char> path[10004]; //value, method{D, S, L, R}
bool chk[10004];
void test_case() {
    memset(path, 0, sizeof(path));
    memset(chk, false, sizeof(chk));
    int A, B; cin >> A >> B;
    queue<int> q;
    q.push(A);
    chk[A] = true; 
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == B) break;
        //D
        int tmp = (cur * 2) % MOD;
        if (!chk[tmp]) {
            chk[tmp] = true;
            q.push(tmp);
            path[tmp] = {cur, 'D'};
        }

        //S
        tmp = cur ? cur - 1 : 9999;
        if (!chk[tmp]) {
            chk[tmp] = true;
            q.push(tmp);
            path[tmp] = {cur, 'S'};
        }

        //L
        string str = to_string(cur);
        int len = str.size();
        for (int i = 0; i < 4 - len; i++) {
            str.insert(str.begin(), '0');
        }
        char tstr = str[0];
        for (int i = 0; i < str.size() - 1; i++) {
            str[i] = str[i + 1];
        }
        str[str.size() - 1] = tstr;
        tmp = stoi(str);
        if (!chk[tmp]) {
            chk[tmp] = true;
            q.push(tmp);
            path[tmp] = {cur, 'L'};
        }

        //R
        str = to_string(cur);
        len = str.size();
        for (int i = 0; i < 4 - len; i++) {
            str.insert(str.begin(), '0');
        }
        tstr = str[str.size() - 1];
        for (int i = str.size() - 1; i > 0; i--) {
            str[i] = str[i - 1];
        }
        str[0] = tstr;
        tmp = stoi(str);
        if (!chk[tmp]) {
            chk[tmp] = true;
            q.push(tmp);
            path[tmp] = {cur, 'R'};
        }
    }

    int tmp = B;
    vector<char> ans;
    while(tmp != A) {
        ans.push_back(path[tmp].second);
        tmp = path[tmp].first;
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    } 
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}