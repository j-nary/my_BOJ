//BOJ_15654 N과 M(5) [실버 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int value[10];
bool check[10];
vector<int> v;

void per() {
    if (v.size() == m) {
        for (int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
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