#include <bits/stdc++.h>
#include <iostream>
#include <set> 
using namespace std;

vector<string> parseExp(string exp) {
    int idx = 0;
    string op1 = "";
    for (int i = idx; exp[i] != ' '; i++) {
        op1.push_back(exp[i]);
        idx = i;
    }
    string op = "";
    op.push_back(exp[++idx + 1]);
    string op2 = "";
    for (int i = idx + 3; exp[i] != ' '; i++) {
        op2.push_back(exp[i]);
        idx = i;
    }
    string res = "";
    for (int i = idx + 4; i < exp.size(); i++) res.push_back(exp[i]);
    
    return vector<string>{op1, op, op2, res};
}

int calculate(int op1, char op, int op2) {
    switch(op) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
    }
}

bool isPromisingDecimal(int dec, string op1, string op2, string res) {
    for (char o: op1) {
      if (o - '0' >= dec) return false;
    }
    for (char o: op2) {
      if (o - '0' >= dec) return false;
    }
    for (char o: res) {
      if (o - '0' >= dec) return false;
    }
    return true;
}

string toBaseN(int num, int dec) {
  if (num == 0) return "0";

  string baseN = "";
  while (num > 0) {
    baseN = to_string(num % dec) + baseN;
    num /= dec;
  }
  return baseN;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> questions;
    
    vector<bool> promising(10, true);
    
    for (string expression: expressions) {
        vector<string> exp = parseExp(expression);
        
        for (int dec = 2; dec <= 9; dec++) {
          if (!isPromisingDecimal(dec, exp[0], exp[2], "0")) promising[dec] = false;
        }
        
        if (exp[3] == "X") {
            questions.push_back(expression);
            continue;
        }
        
        vector<bool> tmp(10, false);
        for (int dec = 2; dec <= 9; dec++) {
            if (!isPromisingDecimal(dec, exp[0], exp[2], exp[3])) continue;
            int op1 = stoi(exp[0], 0, dec);
            int op2 = stoi(exp[2], 0, dec);
            int res = stoi(exp[3], 0, dec);
            if (calculate(op1, exp[1][0], op2) == res) tmp[dec] = true;
        }
        
        for (int dec = 2; dec <= 9; dec++) if (!tmp[dec]) promising[dec] = false;
    }
    
    vector<int> totalPromising;
    for (int dec = 2; dec <= 9; dec++) if (promising[dec]) totalPromising.push_back(dec);
    
    for (string q: questions) {
        vector<string> exp = parseExp(q);
        set<string> res;
        for (int dec: totalPromising) {
            if (!isPromisingDecimal(dec, exp[0], exp[2], "0")) continue;
            int op1 = stoi(exp[0], 0, dec);
            int op2 = stoi(exp[2], 0, dec);
            int calc = calculate(op1, exp[1][0], op2);
            res.insert(toBaseN(calc, dec));
        }
        q.pop_back();
        if (res.size() > 1) q.push_back('?');
        else {
            for (auto r: res) q += r;
        }
        answer.push_back(q);
    }
    return answer;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // vector<string> res = solution({"14 + 3 = 17", "13 - 6 = X", "51 - 5 = 44"});
  // vector<string> res = solution({"1 + 1 = 2", "1 + 3 = 4", "1 + 5 = X", "1 + 2 = X"});
  vector<string> res = solution({"2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "5 - 5 = X"});
  for (auto r: res) cout << r << '\n';
}