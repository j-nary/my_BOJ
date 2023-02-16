#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A, B;
vector<int> Atree;

void test_case() {
    cin >> A >> B;

    int tmp = A;
    Atree.clear();
    while(1) {
        Atree.push_back(tmp);
        tmp /= 2;
        if (tmp == 1) break;
    }

    tmp = B;
    int ans = 0;
    while(1) {
        for (int i = 0; i < Atree.size(); i++) {
            if (Atree[i] == tmp) {
                ans = tmp;
                break;
            }
        }
        if (ans) break;
        tmp /= 2;
    }

    cout << 10 * ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}