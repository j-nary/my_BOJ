//BOJ_1543 문서 검색 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string str; getline(cin, str);
    string q; getline(cin, q);
    int cnt = 0;
    int qSize = q.size();
    for (int i = 0; i < str.size(); i++) {
        string tmp = "";
        for (int j = 0; j < qSize; j++) {
            tmp.push_back(str[i + j]);
        }
        if (tmp == q) {
            cnt++;
            i += (qSize - 1);
        } 
    }
    cout << cnt << '\n';
}