#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    string input;
    cin.ignore();
    for (int i = 1; i <= N; i++){
        getline(cin, input);
        cin.clear();
        cout << i << ". " << input << '\n';
    }
}