#include <iostream>

using namespace std;

int dp[1003];
int main() {
    int N;
    cin >> N;

    if (N%2 == 0) cout << "CY" << endl;
    else cout << "SK" << endl;

    return 0;    
}