#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int A, B, V;
    cin >> A >> B >> V;
    int dalpaeng2 = 0;

    if (A == B) cout << 1 << '\n';
    int x = (int)ceil((double)(V - B) / (A - B));
    cout << x << '\n';
}
    // Ax -B(x-1) = x(A-B) + B >= V
    // V-B / A-B
