#include <iostream>
#include <cstring>
#define MAX 90

using namespace std;

long long dp[MAX+5];

long long pibo(int i) {
    if (dp[i] != -1) return dp[i];
    else return dp[i] = pibo(i-1) + pibo(i-2);
}
int main() {
    int N;
    cin >> N;
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 1;

    cout << pibo(N) << endl;
}