//BOJ_1100 하얀 칸 [브론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool Chs[10][10];   //0은 흰색 1은 검은색
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    bool flag = 0;
    for (int i = 0; i < 8; i++) {
        flag = 0;
        for (int j = 0; j < 8; j++) {
            Chs[i][j] = flag;
            flag = !flag;
        }

        i++; flag = 1;
        for (int j = 0; j < 8; j++) {
            Chs[i][j] = flag;
            flag = !flag;
        }
    }

    char input;
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> input;
            if (Chs[i][j] == 0 && input == 'F') ans++;
        }
    }

    cout << ans << '\n';
}