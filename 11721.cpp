//BOJ_11721 열 개씩 끊어 출력하기 [브론즈 3]
//Warming-up으로 푸는 브론즈 문제는 킹정이지 ~~

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string str;
    cin >> str;
    str = '0' + str;

    for (int i = 1; i < str.length(); i++) {
        cout << str[i];
        if (i > 0 && i % 10 == 0) cout << endl;
    }    
}