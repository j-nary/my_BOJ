#include <iostream>

using namespace std;

int P[10][10];
//n은 10보다 작다고 가정

int minmult(int n, const int d[]) {
    int M[10][10];
    for (int i = 1; i <= n; i++)
        M[i][i] = 0;
    for (int diagonal = 1; diagonal <= n-1; diagonal++) {
        for (int i = 1; i <= n-diagonal; i++) {
            int j = i + diagonal;
            M[i][j] = M[i][i] + M[i+1][j] + (d[i-1]*d[i]*d[j]);
            P[i][j] = i;
            for (int k = i+1; k <= j-1; k++) {
                int tmp =  M[i][k] + M[k+1][j] + (d[i-1] * d[k] * d[j]);
                if (M[i][j] > tmp) {
                    M[i][j] = tmp;
                    P[i][j] = k;
                }
            }
        }
    }

    return M[1][n];
}

void order(int i, int j) {
    if (i == j) cout << "A" << i;
    else {
        int k = P[i][j];
        cout << "(";
        order(i, k);
        order(k + 1, j);
        cout << ")";
    }
}

int main() {
    cout << "n 입력 >> ";
    int n; cin >> n;
    cout << "0..n의 행렬 규모 입력 >> ";
    //교재 Example3.5의 데이터 : 5, 2, 3, 4, 6, 7, 8

    int d[10];
    for (int i = 0; i <= n; i++)
        cin >> d[i];

    int res = minmult(n, d);
    cout << "곱셈 횟수의 최소치 >> " << res << endl;
    cout << "곱셈 연산 순서 >> ";
    order(1, 6);
    cout << endl;
}