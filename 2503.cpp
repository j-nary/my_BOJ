//BOJ_2503 숫자 야구 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node {
    string str;
    int stk, bll;
};
vector<node> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0 ; i < N; i++) {
        string ip; cin >> ip;
        int stk, bll; cin >> stk >> bll;
        v.push_back({ip, stk, bll});
    }
    int cnt = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (j == i) continue;
            for (int k = 1; k < 10; k++) {
                if (i == k || j == k) continue;
                string num = "";
                num += (i + '0');
                num += (j + '0');
                num += (k + '0');
                bool flag = false;
                for (int l = 0; l < N; l++) {
                    int s = 0, b = 0;
                    if (v[l].str[0] == num[0]) s++;
                    else if (v[l].str[0] == num[1] || v[l].str[0] == num[2]) b++;
                    if (v[l].str[1] == num[1]) s++;
                    else if (v[l].str[1] == num[0] || v[l].str[1] == num[2]) b++;
                    if (v[l].str[2] == num[2]) s++;
                    else if (v[l].str[2] == num[0] || v[l].str[2] == num[1]) b++;

                    if (s != v[l].stk || b != v[l].bll) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) cnt++;
            }
        }
    }
    cout << cnt << '\n';
}