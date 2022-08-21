#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<int> v;
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < T; i++) cout << v[i] << '\n';
}
