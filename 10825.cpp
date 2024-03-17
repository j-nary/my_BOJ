//BOJ_10825 국영수 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node {
    string name;
    int kor, eng, mth;
    bool operator<(const node& n) const {
        if (this -> kor == n.kor) {
            if (this -> eng == n.eng) {
                if (this -> mth == n.mth) {
                    return this -> name < n.name;
                }
                return this -> mth > n.mth;
            }
            return this -> eng < n.eng;
        }
        return this -> kor > n.kor;
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<node> v;
    int N; cin >> N;
    string str; int k, e, m;
    for (int i = 0; i < N; i++) {
        cin >> str;
        cin >> k >> e >> m;
        v.push_back({str, k, e, m});
    }
    sort(v.begin(), v.end());
    for (auto a : v) {
        cout << a.name << '\n';
    }
}