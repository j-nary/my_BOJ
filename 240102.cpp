// 상혁이 문제
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string str;
    cin >> str;
    for (char &c : str) {
        c = tolower(c);
    }
    vector<string> startPatterns = {"http://", "https://"};
    vector<string> endPatterns = {".com", ".co.kr", ".org", ".net"};
    int cnt = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        for (const auto& start : startPatterns) {
            if (str.substr(i, start.length()) == start) {
                for (const auto& end : endPatterns) {
                    size_t endPos = str.find(end, i + start.length());
                    if (endPos != string::npos && endPos - i >= start.length() + 3) {
                        cnt++;
                        i = endPos + end.length() - 1; // Move the index to the end of the current URL
                        break;
                    }
                }
            }
        }
    }
    cout << cnt << "개\n";
}

