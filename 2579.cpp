#include <iostream>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;

    int *S = new int[cnt];     //스코어 입력 배열
    for (int i = 0; i < cnt; i++) cin >> S[i];

    int *D = new int[cnt];     //상태 입력 배열
    D[0] = S[0];
    D[1] = S[1];
    if (D[1] < S[0] + S[1]) {
        D[1] = S[0] + S[1];
    }
    D[2] = S[0] + S[2];
    if (D[2] < S[1] + S[2]) {
        D[2] = S[1] + S[2];
    }

    for (int i = 3; i < cnt; i++) {
        D[i] = D[i-3] + S[i] + S[i-1];
        if (D[i] < D[i-2] + S[i])
            D[i] = D[i-2] + S[i];
    }

    cout << D[cnt-1] << endl;
}