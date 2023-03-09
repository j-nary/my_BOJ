//BOJ_2023 신기한 소수
//시간초과

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool sosu[9];
//소수이면 true

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    string sidx = "1";
    for (int i = 0; i < N-1; i++) {
        sidx.push_back('0');
    }
    string eidx = sidx;
    eidx.push_back('0');

    sosu[2] = true;
    sosu[3] = true;
    sosu[5] = true;
    sosu[7] = true;

    for (int i = 2237; i < stoi(eidx); i++) {
        string tmp = to_string(i);
        int len = tmp.length();

        bool flag = 1;
        //각각 하나하나 소수판정
        for (int k = 1; k <= len; k++) {
            string subTmp = "";
            for (int idx = 0; idx < k; idx++) {
                subTmp += tmp[idx];
            }
            for (int i = 2; i < stoi(subTmp); i++) {
                if (stoi(subTmp) % i == 0) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) break;
        }

        if (flag) {
            cout << tmp << '\n';
        }
    }
}