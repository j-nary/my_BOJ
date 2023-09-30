#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(1) {
        string input;
        getline(cin, input);

        if (input == "#") break;

        int ans = 0;
        for(int i = 0; i < input.size(); i++) {
            if (input[i]== 'a' || input[i]== 'e' || input[i]== 'i' || input[i]== 'o' || input[i]== 'u' || input[i]== 'A' || input[i]== 'E' || input[i]== 'I' || input[i]== 'O' || input[i]== 'U') ans++;
        }
        cout << ans << '\n';
    }
}