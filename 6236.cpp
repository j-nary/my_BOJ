//BOJ_6236 용돈 관리 [실버 2]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> w;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }

    //최소 인출 금액은 용돈 중 최대값
    int minOut = *max_element(v.begin(), v.end());
    //최대 인출 금액은 용돈의 총합
    int maxOut = 0;
    for (int i = 0; i < N; i++) {
        maxOut += v[i];
    }

    int ans = 0;

    while(minOut <= maxOut) {
        int mid = (minOut + maxOut) / 2;
        int cnt = 1;
        int had = mid;
        for (int i = 0; i < N; i++) {
            had -= v[i];
            if (had < 0) {
                cnt++;
                had = mid - v[i];
            }
        }
        if (cnt <= M) {
            ans = mid;
            maxOut = mid - 1;
        }
        else {
            minOut = mid + 1;
        }
    }

    cout << ans << '\n';
}