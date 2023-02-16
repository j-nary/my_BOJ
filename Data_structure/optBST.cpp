#include <iostream>

using namespace std;


void optsearchtree(int n, const float P[10], float& minavg, int R[10][10]) {
    float A[10][10] = {0};
    for (int i = 1; i <= n; i++) {
        A[i][i-1] = 0;
        A[i][i] = P[i];
        R[i][i] = i;
        R[i][i-1] = 0;
    }
    A[n + 1][n] = 0;
    R[n + 1][n] = 0;

    for (int diagonal = 1; diagonal <= n-1; diagonal++) {
        for (int i = 1; i <= n-diagonal; i++) {
            int j = i + diagonal;
            float sumP = 0;
            for (int m = i; m <= j; m++) 
                sumP += P[m];
            A[i][j] = A[i][i-1] + A[i+1][j] + sumP;
            R[i][j] = i;
            for (int k = i+1; k <= j; k++) {
                float tmp = A[i][k-1] + A[k+1][j] + sumP;
                if (A[i][j] > tmp) {
                    A[i][j] = tmp;
                    R[i][j] = k;
                }
            }
        }
    }

    minavg = A[1][n];
}

int main() {
    cout << "Example 3.9 테스트" << endl << endl;
    float P[10] = {0, 3.0/8, 3.0/8, 1.0/8, 1.0/8};
    float minavg = 0;
    int R[10][10] = {0};
    
    optsearchtree(4, P, minavg, R);

    cout << "minavg = " << minavg << endl << endl;

    cout << "R배열 출력" << endl;
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }

}