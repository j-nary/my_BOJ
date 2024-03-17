//BOJ_1431 시리얼 번호 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct cmp {
    bool operator() (string a, string b) {
        if (a.size() == b.size()) {
            int aSum = 0;
            for (int i = 0; i < a.size(); i++) {
                if (isdigit(a[i])) aSum += (a[i] - '0');
            }
            int bSum = 0;
            for (int i = 0; i < b.size(); i++) {
                if (isdigit(b[i])) bSum += (b[i] - '0');
            }

            if (aSum == bSum) return a < b;
            return aSum < bSum;
        }
        return a.size() < b.size();
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<string> v;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), cmp());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}