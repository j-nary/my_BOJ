//BOJ_2145 숫자 놀이 [브론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void test_case(int N) {
    string str = to_string(N);
    while(1) {
        int tmp = 0;
        for (int i = 0; i < str.size(); i++) {
            tmp += (str[i]-'0');
        }
        if (tmp / 10 == 0) {
            cout << tmp << '\n';
            return;
        }
        str = to_string(tmp);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    while(1) {
        int N; cin >> N;
        if (N == 0) break;
        test_case(N);
    }
}