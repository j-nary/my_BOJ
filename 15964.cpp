#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;
    cout << (a+b)*(a-b) << endl;
}