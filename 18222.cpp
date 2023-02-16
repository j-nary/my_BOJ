//BOJ_1032 명령 프롬프트 [브론즈 1]

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    vector<string> v;

    string s; cin >> s;
    v.push_back(s);
    int max = s.length();
    int min = s.length();

    for (int i = 1; i < N; i++) {
        cin >> s;
        v.push_back(s);
    }

    string res;
    for (int i = 0; i < min; i++) {
        bool flag = 0;
        char cmp = v[0][i];

        for (int j = 1; j < v.size(); j++) {
            if (cmp != v[j][i]) {
                flag = 1;
                break;
            }
        }

        if (!flag) res.push_back(cmp);
        else res.push_back('?');
    }

    for(int i = 0; i < res.length(); i++) {
        if (0 <= res[i] - 'a' && res[i]-'a' <= 26) {
            cout << res[i];
        }
        else if (res[i] == '.') {
            cout << res[i];
        }
        else {
            cout << '?';
        }
    }

    if (max > res.length()) {
        for (int i = res.length(); i < max; i++) {
            cout << '?';
        }
    }
    cout <<'\n';
}