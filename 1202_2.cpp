//BOJ_1202 보석 도둑 [골드 2]
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define value first
#define weight second

using namespace std;

vector<pair<int, int> > jewelry; //{value, weight}
vector<long long int> bag;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    } else {
        return a.first > b.first;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int M, V; cin >> M >> V;
        jewelry.push_back(make_pair(V, M));
    }

    for (int i = 0; i < K; i++) {
        int C; cin >> C;
        bag.push_back(C);
    }
    sort(jewelry.begin(), jewelry.end(), cmp);
    sort(bag.begin(), bag.end());

    long long int res = 0;
    for (int i = 0; i < N; i++) {
        int Vi = jewelry[i].value;
        int Wi = jewelry[i].weight;

        int idx = -1;
        for (int j = 0; j < bag.size(); j++) {
            if (bag[j] >= Wi) {
                idx = j;
                break;
            }
        }

        if (idx != -1) {
            bag.erase(bag.begin() + idx);
            res += Vi;
        }
    }
    cout << res << '\n';
}