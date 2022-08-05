#include <iostream>

using namespace std;

int matA[101][101];
int matB[101][101];
int mul[101][101];
int main() {
    int N, M, K;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matA[i][j];
    cin >> M >> K;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> matA[i][j];
    
    for (int i = 0; i < N; i++) {
        int idx = 0;
        for (int j = 0; j < K; j++) {
            int sum = 0;
            for (int k = 0; k < 5; k++) {
                sum += matA[i][j] * matB[j][k];
            }
            mul[i][idx++] = sum;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cout << mul[i][j] << " ";
        }
        cout << '\n';
    }
}