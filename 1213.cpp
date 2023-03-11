//BOJ_1213 팰린드롬 만들기 [실버 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int check[30];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;
    for (int i = 0; i < s.length(); i++) {
        check[s[i] - 'A']++;
    }

    //문자열이 홀수개일 때
    char flag = 0;
    string res = "";
    if (s.length() % 2 == 1) {
        for (int i = 0; i < 30; i++) {
            if (check[i] % 2 == 1 && flag == 0) {
                flag = i + 'A';
                continue;
            }
            if (check[i] % 2 == 1) {
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
        }
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < check[i]/2; j++) {
                res.push_back(i + 'A');
            }
        }
        cout << res << flag;
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }

    //문자열이 짝수일 때
    else {
        for (int i = 0; i < 30; i++) {
            if (check[i] % 2 == 1) {
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
        }
        res = "";
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < check[i]/2; j++) {
                res.push_back(i + 'A');
            }
        }
        cout << res;
        reverse(res.begin(), res.end());
        cout << res << '\n';        
    }
}