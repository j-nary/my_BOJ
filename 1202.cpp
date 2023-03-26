//BOJ_1202 보석 도둑 [골드 2]
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define weight first
#define value second

using namespace std;

vector<pair<int, int> > jewelry; //{value, weight}
vector<long long int> bag;
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int M, V; cin >> M >> V;
        jewelry.push_back(make_pair(M, V));
    }

    for (int i = 0; i < K; i++) {
        int C; cin >> C;
        bag.push_back(C);
    }

    sort(jewelry.begin(), jewelry.end());
    sort(bag.begin(), bag.end());

    long long int res = 0;
    for (int i = 0, j = 0; i < K; i++) {
        while (j < N && jewelry[j].weight <= bag[i]) {
            pq.push(jewelry[j++].value);
        }

        if (pq.empty()) continue;
        res += pq.top();
        pq.pop();
    }
    cout << res << '\n';
}