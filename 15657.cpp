//BOJ_15657 N과 M (8) [실버 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int value[10];
bool check[10];
int n, m;
vector<int> v[10];

void per (int start) {
    cout << start << " ";
    int idx = value[start];
    for (int i = 0; i < v[idx].size(); i++) {
        if (check[i]) continue;
        int k = v[idx][i];
        per(k);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    sort(value, value + n);

    for (int i = 0; i < n; i++) {
        int idx = value[i];
        for (int j = 0; j < n; j++) {
            v[idx].push_back(value[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        per(i);
        memset(check, 0, sizeof(check));
    }
}