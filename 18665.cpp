//BOJ_18665 IQ Test [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int N; 
set<int>::iterator iter;
set<int>::iterator it1;
set<int>::iterator it2;

vector<pair<int, int>> recur(set<int> v, vector<pair<int, int>> p, int cnt) {
    if (cnt >= 44) return p;
    set<int> nv = v;
    vector<pair<int, int>> np = p;
    // for (int i = 0; i < v.size() - 1; i++) {
    //     for (int j = i + 1; j < v.size(); j++) {
    for (int i : v) {
        for (int j : v) {
            int tmp = i * i - j;
            if (tmp >= 0) {
                iter = nv.find(tmp);
                if (iter == nv.end()) {
                    nv.insert(tmp);
                    np.push_back({i, j});
                    if (tmp == N) return np;
                    recur(nv, np, ++cnt);
                    iter = nv.find(tmp);
                    nv.erase(iter);
                    np.pop_back();
                }
            }
            else {
                tmp = j * j - i;
                if (tmp >= 0) {
                    iter = nv.find(tmp);
                    if (iter == nv.end()) {
                        nv.insert(tmp);
                        np.push_back({j, i});
                        if (tmp == N) return np;
                        recur(nv, np, ++cnt);
                        iter = nv.find(tmp);
                        nv.erase(iter);
                        np.pop_back();
                    }
                }
            }
        }
    }

    return p;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N;
    set<int> v;
    v.insert(0); v.insert(1); v.insert(2);
    vector<pair<int, int>> p;
    vector<pair<int, int>> ans = recur(v, p, 1);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}