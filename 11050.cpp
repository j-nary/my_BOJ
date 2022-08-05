#include <iostream>

using namespace std;

int combi(int N, int K) {
    if (K == 1) return N;
    else if (K == 0) return 1;
    else if (N == K) return 1;
    return combi(N-1, K-1) + combi(N-1, K);
}
int main() {
    int N, K;
    cin >> N >> K;

    cout << combi(N, K) << endl;
}
