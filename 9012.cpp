#include <iostream>
#include <stack>

using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        stack<char> s;
        string input;
        cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (!s.empty() && input[i] == ')' && s.top() == '(') s.pop();
            else s.push(input[i]);
        }
        if (s.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}