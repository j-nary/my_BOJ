#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 1 || n == 0) return 1;
    else return n * factorial(n-1);
}
int main() {
    int N; cin >> N;
    string res = to_string(factorial(N));

    int cnt = 0;
    for (int i = res.length()-1; i >= 0; i--) {
        if (res[i] == '0') cnt++;
        else break;
    }

    cout << cnt << endl;
}