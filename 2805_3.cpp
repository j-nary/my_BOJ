//BOJ_2805 나무 자르기 [실버 2]
//https://www.acmicpc.net/problem/2805
//6개월만의 재도전 -> 시간초과

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int N;
ll M; //나무의 수와 가져가려는 나무 길이
vector<ll> tree;
int res;

ll cal(int height) {
    ll have = 0;
    for (int i = 0; i < tree.size(); i++) {
        int stn = tree[i] - height;
        if (stn > 0) have += stn;
    }

    return have;
}

void binaryS(int low, int high) {
    if (low > high) return;
    int mid = (low + high) / 2;
    ll have = cal(mid);
    if (have >= M) res = max(mid, res);

    if (have > M) binaryS(mid + 1, high);
    else if (have < M) binaryS(low, mid - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int len; cin >> len;
        tree.push_back(len);
    }
    sort(tree.begin(), tree.end());
    binaryS(0, tree[tree.size() - 1]);
    cout << res << endl;
}