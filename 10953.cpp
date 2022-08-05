#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << s[0]-48+s[2]-48 << endl;
    }
}