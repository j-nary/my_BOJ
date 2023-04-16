//BOJ_2512 예산 [실버 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    int M; cin >> M;

    long long left = 0; long long right = v[N - 1];
    long long ans = 0;
    while(left <= right) {
        long long mid = (left + right) / 2;

        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (v[i] > mid) {
                sum += mid;
            } else {
                sum += v[i];
            }
        }

        if (sum <= M) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << '\n';
}