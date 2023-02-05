#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s, d;
    cin >> s >> d;
    if (s.length() >= d.length()) cout << "go" << endl;
    else cout << "no" << endl;
}