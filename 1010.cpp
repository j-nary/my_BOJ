#include <iostream>
using namespace std;

int combination(int m, int n) {
    double res = 1;
    for (int i = 0; i < n; i++) {
        //cout << "res *= " << m << "/" << n << "= " << m/n <<endl;
        res *= m--;
        res /= (i+1);
    }
    return res;
}
int main() {
    int T;
    cin >> T;
    unsigned long long N, M;
    unsigned long long res;
    while(T--) {
        cin >> N; cin >> M;
        int res = (int)combination(M, N);
        cout << res << endl;

    }

    return 0;
}