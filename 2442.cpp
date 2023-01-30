//BOJ_2442 별찍기-5 [브론즈 3]

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    int box = N - 1;
    int tmp = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N-i; j++) {
            cout << ' ';
        }
        for (int k = 0; k < i * 2 -1; k++) {
            cout << '*';
        }
        cout << '\n';
    }
}