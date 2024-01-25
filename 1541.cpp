//BOJ_1541 잃어버린 괄호 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> v;
bool chk[100];
string cal(string a, string op, string b) {
    int aa = stoi(a);
    int bb = stoi(b);

    if (op == "+") return to_string(aa + bb);
    else if (op == "-") return to_string(aa - bb);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string ip; cin >> ip;
    string str = "";
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] == '+' || ip[i] == '-') {
            v.push_back(str);
            if (ip[i] == '+') v.push_back("+");
            else v.push_back("-");
            str = "";
        } else {
            str.push_back(ip[i]);
        }
    }
    v.push_back(str);

    int len = v.size() / 2;
    vector<int> seq;
    for (int i = 1; i <= len; i++) {
        seq.push_back(i);
    }

    int ans = 1e9;
    do {
        vector<string> tmp;
        for (int i = 0; i < v.size(); i++) {
            tmp.push_back(v[i]);
        }
        memset(chk, 0, sizeof(chk));
        string res;
        for (int num : seq) {
            chk[(num * 2 - 1)] = chk[(num * 2 - 1) - 1] = chk[(num * 2 - 1) + 1] = true;
            res = cal(tmp[(num * 2 - 1) - 1], tmp[(num * 2 - 1)], tmp[(num * 2 - 1) + 1]);
            for (int i = (num * 2 - 1); i < ip.size(); i++) {
                if (chk[i]) tmp[i] = res;
                else break;
            }
            for (int i = (num * 2 - 1) - 1; i >= 0; i--) {
                if (chk[i]) tmp[i] = res;
                else break;
            }
        }
        ans = min(ans, stoi(res));
    } while (next_permutation(seq.begin(), seq.end()));
    cout << ans << '\n';
}