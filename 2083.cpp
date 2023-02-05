#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    while(1) {
        string n;
        int a, w;
        cin >> n >> a >> w;
        if (n == "#" && a == 0 && w == 0) break;

        if (a > 17 || w >= 80) {
            cout << n << " Senior" << endl;
        }
        else cout << n << " Junior" << endl;
    }
}