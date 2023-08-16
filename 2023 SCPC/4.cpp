#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinimumParts(const string& R, const string& P) {
    int n = R.length();
    int m = P.length();

    vector<int> lastIdx(26, -1);
    vector<int> nextIdx(n, n);
    vector<int> parts(m, n);

    for (int i = n - 1; i >= 0; i--) {
        lastIdx[R[i] - 'a'] = i;
        nextIdx[i] = lastIdx[P.back() - 'a'];
    }

    for (int i = m - 1; i >= 0; i--) {
        int idx = n;
        for (int j = n - 1; j >= 0; j--) {
            if (R[j] == P[i]) {
                idx = j;
            }
            parts[i] = min(parts[i], nextIdx[j] - idx + parts[i + 1]);
        }
    }

    return parts[0] < n ? parts[0] + 1 : -1;
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        string R, P;
        cin >> R >> P;

        int result = findMinimumParts(R, P);

        cout << "Case #" << tc << endl;
        cout << result << endl;
    }

    return 0;
}
