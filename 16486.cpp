#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int d1, d2; cin >> d1 >> d2;

    printf("%f\n", d1*2 + d2*2*3.141592);
}