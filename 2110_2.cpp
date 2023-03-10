//BOJ_2110 공유기 설치 [골드 4]
//시간초과도 안 나는데 이분탐색을 사용하지 않아서 틀린건가 ?
//3개로 픽스해놓고 풀어서 그렇습니다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, C; cin >> N >> C;
    for (int i = 0; i < N; i++) {
        long long input; cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    long long s = v[0];
    long long e = v[v.size() - 1];

    long long m;
    long long dist = min(v[1] - s, e - v[1]);
    for (int i = 2; i < N - 1; i++) {
        m = v[i];
        long long tmp = min(e - m, m - s);
        dist = max(dist, tmp);
    }

    cout << dist << '\n';
}