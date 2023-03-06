//BOJ_10994 별찍기 - 19 [실버 4]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    //1 5 9 13 <- 4씩 증가
    //2 4 6
    // 1 + 4(n-1) = 4n - 3
    // - cnt * 4
    
    int cnt = 0;
    for (int k = 0; k < N; k++) {
        if (k) {
            for (int i = 0; i < cnt; i++) {
                cout << "* ";
            }
            for (int j = 0; j < (4 * N - 3) - cnt * 4; j++) {
                cout << ' ';
            }
            for (int i = 0; i < cnt; i++) {
                cout << " *";
            }
            cout << '\n';
        }

        for (int i = 0; i < cnt; i++) {
            cout << "* ";
        }
        for (int j = 0; j < (4 * N - 3) - cnt * 4; j++) {
            cout << '*';
        }
        for (int i = 0; i < cnt; i++) {
            cout << " *";
        }
        cnt++;
        cout << '\n';
    }

    cnt--;
    for (int k = 0; k < N ; k++) {
        if (k) {
            for (int i = 0; i < cnt; i++) {
                cout << "* ";
            }
            for (int j = 0; j < (4 * N - 3) - cnt * 4; j++) {
                cout << '*';
            }
            for (int i = 0; i < cnt; i++) {
                cout << " *";
            }
            cout << '\n';
        }

        if (cnt == 0) break;

        for (int i = 0; i < cnt; i++) {
            cout << "* ";
        }
        for (int j = 0; j < (4 * N - 3) - cnt * 4; j++) {
            cout << ' ';
        }
        for (int i = 0; i < cnt; i++) {
            cout << " *";
        }
        cout << '\n';

        cnt--;
    }

}