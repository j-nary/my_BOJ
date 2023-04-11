//BOJ_2568 전깃줄 - 2 [플래티넘 5]
//PS 중간고사 대비 다시풀기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int v[500005];
vector<int> lis;
int path[500005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    int maxIdx = 0;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v[a] = b;
        maxIdx = max(maxIdx, a);
    }

    for (int i = 1; i <= maxIdx; i++) {
        if (!v[i]) continue;
        if (lis.size() == 0) {
            lis.push_back(v[i]);
            path[i] = 1;
        } else if (lis.back() < v[i]) {
            lis.push_back(v[i]);
            path[i] = lis.size();
        }
        else {
            int idx = upper_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
            path[i] = idx + 1;
        }
    }
    //최소 개수 출력
    cout << N - lis.size() << '\n';

    //제거해야하는 것 출력
    vector<int> ans;
    int tmp = lis.size();
    for (int i = maxIdx; i >= 1; i--) {
        if (!path[i]) continue;
        if (path[i] == tmp) tmp--;
        else ans.push_back(i);
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << '\n';
    }
}