#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;

        cout << lcm(a,b) << endl;
    }
}