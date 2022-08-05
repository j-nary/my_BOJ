#include <iostream>

using namespace std;

int dp[4003][4003];
int main() {
    string A; string B;
    cin >> A >> B;
    A = "8" + A;
    B = "2" + B;

    int max = 0;
    for (int i = 1; i < A.length(); i++) {
        for (int j = 1; j < B.length(); j++) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (max < dp[i][j]) max = dp[i][j];
            }
        }
    }

    cout << max << endl;
}