//BOJ_17413 단어 뒤집기 2
//https://www.acmicpc.net/problem/17413

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector<char> v;

    string str;
    getline(cin, str);
    int TagFlag = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '>') {
            TagFlag = 0;
            cout << str[i];
        }
        else if (str[i] == '<') {
            if (!v.empty()) {
                reverse(v.begin(), v.end());
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i];
                }
                v.clear();
            }
            TagFlag = 1;
            cout << str[i];
        }
        else if (TagFlag == 1) cout << str[i];
        
        else if (str[i] == ' ') {
            reverse(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
            }
            v.clear();
            cout << str[i];
        }
        else if (TagFlag == 0) {
            v.push_back(str[i]);
        }

    }

    if (!v.empty()) {
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
        }
    }
    cout << endl;
}