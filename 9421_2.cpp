//BOJ_9421 소수상근수 [실버 1]
#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

bool sosu[1000006];
set<int> s;

bool sgs(int num) {
    if (s.find(num) != s.end()) return false;
    s.insert(num);
    string str = to_string(num);
    int ret = 0;
    for (int i = 0; i < str.size(); i++) {
        int tmp = str[i] - '0';
        ret += (tmp * tmp);
    }
    if (ret == 1) return true;
    return sgs(ret);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    sosu[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (sosu[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            sosu[j] = true;
        }
    }

    for (int i = 7; i <= N; i++) {
        if (sosu[i]) continue;
        s.clear();
        if (sgs(i)) cout << i << '\n';
    }
}