#include <bits/stdc++.h>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;
    stringstream ss(s);
    vector<int> tokens;
    string token;
    while(getline(ss, token, '/')) {
        tokens.push_back(stoi(token));
    }

    int ka = tokens[0] + tokens[2];
    if (ka < tokens[1] || tokens[1] == 0) {
        cout << "hasu\n";
    } else {
        cout << "gosu\n";
    }
}