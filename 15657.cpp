//BOJ_15657 N과 M (8) [실버 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
vector<int> value;
vector<int> tmp;

void per (int start) {
    if (tmp.size() == m) {
        for (int i = 0; i < m; i++) {
            cout << tmp[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (start > value[i]) continue;
        tmp.push_back(value[i]);
        per(value[i]);
        tmp.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int input; cin >> input;
        value.push_back(input);
    }
    sort(value.begin(), value.end());

    per(value[0]);
}