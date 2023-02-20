//BOJ_1024 수열의 합 [실버 2]
//https://www.acmicpc.net/problem/1024

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    long long N, L; cin >> N >> L;

    while(1) {
        if (L > 100) {
            cout << -1 << '\n';
            break;
        }

        float mid = (float)N / L;

        if ((long long)(mid * 100) % 10 != 0) {
            L++;
            continue;
        }
        else if ((long long)(mid * 10) % 10 == 0 && L % 2 == 1) {
            if ((long long)mid - L/2 < 0) {
                L++;
                continue;
            }
            for (long long i = L / 2; i > 0; i--) {
                cout << (long long)mid - i << " ";
            }
            cout << (long long)mid << " ";
            for (long long i = 1; i <= L / 2; i++) {
                cout << (long long)mid + i << " ";
            }
            cout << '\n';
            break;
        }
        else if ((long long)(mid * 10) % 10 == 5 && L % 2 == 0) {
            if ((long long)mid - L/2 + 1 < 0) {
                L++;
                continue;
            }
            for (long long i = L/2 - 1; i > 0; i--) {
                cout << (long long)mid - i << " ";
            }
            cout << (long long)mid << " ";
            for (long long i = 1; i <= L/2; i++) {
                cout << (long long)mid + i << " ";
            }
            cout << '\n';
            break;
        }
        L++;
    }
}