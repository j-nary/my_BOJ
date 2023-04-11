//BOJ_1747 소수&팰린드롬 [실버 1]
//PS 중간고사 대비 다시풀기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sosu[10000007];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    
    //소수 판별
    sosu[1] = true;
    for (int i = 2; i * i < 10000007; i++) {
        if (sosu[i]) continue;
        for (int j = i + i; j < 10000007; j += i) {
            sosu[j] = true;
        }
    }

    for (int i = N; ; i++) {
        if (sosu[i]) continue;
        string s = to_string(i);
        int len = s.length();
        if (len == 1) {
            cout << s << '\n';
            return 0;
        }
        bool flag = 1;
        for (int i = 0, j = len - 1; i <= j; i++, j--) {
            if (s[i] != s[j]) {
                flag = 0; break;
            }
        }
        if (flag) {
            cout << s << '\n';
            return 0;
        }
    }
}