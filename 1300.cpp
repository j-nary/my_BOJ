//BOJ_1300 K번째 수 [골드 2]
//이분 탐색 고난이도 버전 연습 ^___^
//문해 시험 잘 보게 해주세요 🙏

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long N, K;

long long cnt(long long stn) {
    long long ret = 0;
    for (long long i = 1; i <= N; i++) {
        if (i > stn) break;
        if (i * N < stn) {
            ret += N;
        } else {
            ret += (stn / i) ;
            if (stn % i == 0) ret--;
        }
    }

    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> K;
    long long left = 0, right = N * N;
    long long res = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;

        long long cntM = cnt(mid) + 1;
        if ((long long)K >= cntM) {
            left = mid + 1;
            res = max(res, mid);
        } else {
            right = mid - 1;
        }
    }

    cout << res << '\n';
}