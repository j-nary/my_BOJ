//BOJ_15654 N과 M(5) [실버 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int value[10];
bool check[10];
vector<int> v;
vector<string> res;

void per() {
    if (v.size() == m) {
        string s;
        int flag = 0;
        for (int i = 0; i < m; i++) {
            s.push_back(v[i]);
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == s) {
                flag = 1;
                break;
            }
        }
        if (flag) return;

        for (int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        res.push_back(s);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        check[i] = 1;
        v.push_back(value[i]);
        per();
        v.pop_back();
        check[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    sort(value, value + n);
    per();
}