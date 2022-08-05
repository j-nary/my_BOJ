#include <iostream>
#include <algorithm>

using namespace std;

int input[100005];
int main() {
    int N; cin >> N;
    int K; cin >> K;

    for (int i = 0; i < N; i++) cin >> input[i];

    int cnt = 0;
    for (int i = 0; i+K-1 < N; i++) {
        int sum = 0;
        for (int j = 0; j < K; j++) {
            sum += input[i+j];
        }
        cnt = max(cnt, sum);
    }

    cout << cnt << endl;
}