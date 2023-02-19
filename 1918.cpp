//BOJ_1918 후위 표기식 [골드 2]
//https://www.acmicpc.net/problem/1918

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<char> v[2];
bool cmp(char pre, char now) {
    int preV = 0, nowV = 0;
    for (int i = 0; i < 2; i++) {
        if (find(v[i].begin(), v[i].end(), pre) != v[i].end()) {
            preV = i;
        }
        if (find(v[i].begin(), v[i].end(), now) != v[i].end()) {
            nowV = i;
        }
    }

    if (preV < nowV) return false;
    else return true;   //pop 해야하는 경우
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    v[0].push_back('+');
    v[0].push_back('-');
    v[1].push_back('*');
    v[1].push_back('/');

    stack<char> st;
    string input; cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (0 <= input[i] - 'A' && input[i] - 'A' <= 25) {
            cout << input[i];
        }
        else if (input[i] == '(') {
            st.push(input[i]);
        }
        else if (input[i] == ')') {
            while (1) {
                char tmp = st.top();
                st.pop();
                if (tmp == '(') break;
                cout << tmp;
            }
        }
        else {
            if (st.empty()) {
                st.push(input[i]);
                continue;
            }
            char preSt = st.top();

            if (preSt == '(') {
                st.push(input[i]);
                continue;
            }

            while(!st.empty() && cmp(preSt, input[i])) {
                cout << st.top();
                st.pop();
                if (st.empty()) break;
                preSt = st.top();
            }
            st.push(input[i]);
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout <<'\n';
}