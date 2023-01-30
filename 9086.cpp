#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        string s; cin >> s;
        cout << s[0] << s[s.length() - 1] << endl;
    }
}