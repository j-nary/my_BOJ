#include <iostream>

using namespace std;

int coin[11];
int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> coin[i];

    int cnt = 0;
    int idx = N - 1;
    while(K > 0) {
        cnt += (K / coin[idx]);
        K = K % coin[idx--];
    }

    cout << cnt << endl;
}