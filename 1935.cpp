//BOJ_1935 후위 표기식2 [실버 3]
#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;

bool isOperator(char c) {
  return c == '*' || c == '+' || c == '/' || c == '-';
}

double calc(double op1, char c, double op2) {
  switch(c) {
    case '*':
      return op1 * op2;
    case '+':
      return op1 + op2;
    case '/':
      return op1 / op2;
    case '-':
      return op1 - op2;
  };
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  string statement; cin >> statement;
  vector<double> val(N);
  for (int i = 0; i < N; i++) cin >> val[i];

  stack<double> st;
  for (int i = 0; i < statement.length(); i++) {
    if (isOperator(statement[i])) {
      double op2 = st.top(); st.pop();
      double op1 = st.top(); st.pop();
      st.push(calc(op1, statement[i], op2));
    } else {
      st.push(val[statement[i] - 'A']);
    }
  }

  cout << fixed << setprecision(2) << st.top() << '\n';
}