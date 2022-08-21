#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int A, B, V;
    cin >> A >> B >> V;
    int dalpaeng2 = 0;
    int cnt = 0;
    while (1) {
        cnt++;
        dalpaeng2 += A;
        if (dalpaeng2 >= V) break;
        dalpaeng2 -= B;
        if (dalpaeng2 < 0) dalpaeng2 = 0;
    }

    cout << cnt << '\n';
}