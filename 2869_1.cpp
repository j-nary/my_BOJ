#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int A, B, V;
    cin >> A >> B >> V;
    int dalpaeng2 = 0;

    if (A == B) cout << 1 << '\n';
    double x = (double)(V - B) / (A - B);
    if ((int)(x * 10) % 10 != 0)
        cout << (int)x + 1 << '\n';
    else
        cout << (int)x << '\n';
}
    // Ax -B(x-1) = x(A-B) + B >= V
    // V-B / A-B
