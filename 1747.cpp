#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sosu[1004000];
//소수이면 false

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    sosu[1] = true;
    int cnt = 0;

    for (int i = 2; i*i <= 1004000; i++) {
        if (sosu[i] == true) continue;
        else {
            for (int j = i + 1; j < 1004000; j++) {
                if (j % i == 0 && sosu[j] == false) {
                    sosu[j] = true;
                }
            }
        }
    }

    for (int i = N;; i++) {
        if (sosu[i] == true) continue;
        string tmp = to_string(i);
        int len = tmp.length();
        bool flag = 1;
        if (len == 1) {
            cout << tmp << '\n';
            return 0;
        }
        for (int i = 0; i < len/2; i++) {
            if (tmp[i] != tmp[len-1-i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << tmp << '\n';
            return 0;
        }
    }
}