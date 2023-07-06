//BOJ_1990 소수인팰린드롬 [골드 5]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sosu[100000008];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int S, E; cin >> S >> E;
    
    //소수 판별
    sosu[1] = true;
    for (int i = 2; i * i < 100000008; i++) {
        if (sosu[i]) continue;
        for (int j = i * i; j < 100000008; j += i) {
            sosu[j] = true;
        }
    }

    for (int i = S; i <= E ; i++) {
        if (sosu[i]) continue;
        string s = to_string(i);
        int len = s.length();
        if (len == 1) {
            cout << s << '\n';
            continue;
        }
        bool flag = 1;
        for (int i = 0, j = len - 1; i <= j; i++, j--) {
            if (s[i] != s[j]) {
                flag = 0; break;
            }
        }
        if (flag) {
            cout << s << '\n';
        }
    }
    cout << -1 << '\n';
}