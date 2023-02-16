//BOJ_3584 가장 가까운 공통 조상 [골드 4]
//https://www.acmicpc.net/problem/3584

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int parent[10004];

void test_case() {
    vector<int> v[N + 1];
    cin >> N;

    int p, q;
    for (int i = 0; i <= N; i++) {
        cin >> p >> q;
        v[p].push_back(q);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}