#include <iostream>

using namespace std;

int res[1000006];
int main() {
    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        res[i] = i + (i % 10) + (i % 100) / 10 + (i % 1000) / 100 + (i % 10000) / 1000 + (i % 100000) / 10000 + (i % 1000000) / 100000 + (i % 10000000) / 1000000; 
        if (res[i] == N) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}