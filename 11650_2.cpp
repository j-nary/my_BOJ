#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> v;

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(pair<int, int> (a, b));
    }

    sort(v.begin(), v.end());   //��������
    // sort(v.begin(), v.end(), greater<>());   //��������

    for (int i = 0; i < T; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}