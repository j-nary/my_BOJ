#include <iostream>
#include <stack>

using namespace std;

int main() {
    while(1) {
        string s; 
        getline(cin, s);

        if (s == ".") break;

        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[')
                st.push(s[i]);
            else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else st.push(s[i]);
            }
            else if (s[i] == ']') {
                if (!st.empty() && st.top() == '[') st.pop();
                else st.push(s[i]);
            }
        }

        if (st.size() == 0) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}