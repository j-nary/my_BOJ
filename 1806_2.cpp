//BOJ_1806 부분합 [골드 4]

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int pfxSum[1000006];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, S; cin >> N >> S;
    cin >> pfxSum[1];
    for (int i = 2; i <= N; i++) {
        cin >> pfxSum[i];
        pfxSum[i] += pfxSum[i - 1];
    }

    for (int d = 1; d < N; d++) {
        for (int sIdx = 0; sIdx < N; sIdx++) {
            int eIdx = sIdx + d;
            if (eIdx > N + 1) continue;
            int sum = pfxSum[eIdx] - pfxSum[sIdx];
            if (sum >= S) {
                cout << d << '\n';
                return 0;
            }
        }
    }

    cout << 0 << '\n';
}