#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    int n; cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        A.push_back(tmp);
    }
    int m; cin >> m;
    vector<int> B;
    for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        B.push_back(tmp);
    }

    vector<int> ASum;
    for (int i = 0; i < n; i++) {
        ASum.push_back(A[i]);
        int sum = A[i];
        for (int j = i + 1; j < n; j++) {
            sum += A[j];
            ASum.push_back(sum);
        }
    }
    vector<int> BSum;
    for (int i = 0; i < m; i++) {
        BSum.push_back(B[i]);
        int sum = B[i];
        for (int j = i + 1; j < m; j++) {
            sum += B[j];
            BSum.push_back(sum);
        }
    }

    sort(BSum.begin(), BSum.end());

    ll cnt = 0;
    for (int i = 0; i < ASum.size(); i++) {
        int idx = T - ASum[i];
        int lo = lower_bound(BSum.begin(), BSum.end(), idx) - BSum.begin();
        int hi = upper_bound(BSum.begin(), BSum.end(), idx) - BSum.begin();
        cnt += (hi - lo);
    }

    cout << cnt << endl;
}