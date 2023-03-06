#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = N; i > 0; i--) {
        for (int k1 = 0; k1 < ((N*2 - 1)-(i*2 - 1))/2; k1++) {
            cout << " ";
        }
        for (int j = 0; j < i * 2 - 1; j++) {
            cout << '*';
        }
        cout <<'\n';
    }
}