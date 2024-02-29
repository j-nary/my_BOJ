//BOJ_2504 괄호의 값 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

bool isNumber(string s) {
	if (s.empty()) return false;
    for (char c : s) {
            if (!isdigit(c)) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string str;
    cin >> str;

    stack<string> s;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ')') {
            if (!s.empty() && s.top() == "(") {
                s.pop();
                s.push("2");
            } else if (!s.empty() && s.top() == ")" || !s.empty() && s.top() == "]") {
                s.push(""s + str[i]);
            } else if (s.empty() || !s.empty() && s.top() == "[") {
                cout << 0 << '\n';
                return 0;
            } else {
                int tmp = 0;
                while(1) {
                    if (s.empty() || !s.empty() && (s.top() == "[" || s.top() == ")" || s.top() == "]")) {
                        cout << 0 << '\n';
                        return 0;
                    } else if (!s.empty() && s.top() == "(") {
                        s.pop();
                        break;
                    }
                    tmp += stoi(s.top());
                    s.pop();
                }
                tmp *= 2;
                s.push(to_string(tmp));
            }
        } else if (str[i] == ']') {
            if (!s.empty() && s.top() == "[") {
                s.pop();
                s.push("3");
            } else if (!s.empty() && s.top() == ")" || !s.empty() && s.top() == "]") {
                s.push(""s + str[i]);
            } else if (!s.empty() && s.top() == "(") {
                cout << 0 << '\n';
                return 0;
            } else {
                int tmp = 0;
                while(1) {
                    if (s.empty() || !s.empty() && (s.top() == "(" || s.top() == ")" || s.top() == "]")) {
                        cout << 0 << '\n';
                        return 0;
                    } else if (!s.empty() && s.top() == "[") {
                        s.pop();
                        break;
                    }
                    
                    tmp += stoi(s.top());
                    s.pop();
                }
                tmp *= 3;
                s.push(to_string(tmp));
            }
        } else {
            s.push(""s + str[i]);
        }
    }
    int ans = 0;
    while(!s.empty()) {
        if (!isNumber(s.top())) {
            cout << 0 << '\n';
            return 0;
        }
        ans += stoi(s.top());
        s.pop();
    }
    cout << ans << '\n';
}

// 22 6