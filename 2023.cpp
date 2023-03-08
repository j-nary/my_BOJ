//BOJ_2023 신기한 소수

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool sosu[10000007];
//소수이면 false

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    sosu[1] = true;

    for (int i = 2; i*i < 10000007; i++) {
        if (sosu[i] == true) continue;
        else {
            for (int j = i + 1; j < 10000007; j++) {
                if (j % i == 0 && sosu[j] == false) {
                    sosu[j] = true;
                }
            }
        }
    }
    string sidx = "1";
    for (int i = 0; i < N-1; i++) {
        sidx.push_back('0');
    }
    string eidx = sidx;
    eidx.push_back('0');

    for (int i = stoi(sidx); i < stoi(eidx); i++) {
        if (sosu[i] == true) continue;
        string tmp = to_string(i);
        int len = tmp.length();
        bool flag = 1;
        for (int j = 0; j < tmp.length(); j++) {
            if (sosu[tmp[j]-'0'] == true) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            cout << tmp << '\n';
        }
    }
}