#include <iostream>

using namespace std;

int A[1000006];
int B[1000006];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    int aidx = 0, bidx = 0;
    while (N != 0 && M != 0) {
        if (A[aidx] <= B[bidx]) {
            cout << A[aidx++] << " ";
            N--;
        }
        else {
            cout << B[bidx++] << " ";
            M--;
        }
    }

    while (N != 0) {
        cout << A[aidx++] << " ";
        N--;
    }
    while (M != 0) {
        cout << B[bidx++] << " ";
        M--;
    }
}