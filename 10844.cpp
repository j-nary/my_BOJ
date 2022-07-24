#include <iostream>

using namespace std;

int dp[102];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        dp[i] = i;
    }

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < N; j++) {
            if (i-(2j-1) < 0) dp[2j]
        }
    }

}