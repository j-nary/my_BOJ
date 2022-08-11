#include <iostream>
#include <vector>

using namespace std;

int node, edge;     //변수 이름 좀 간지나는 듯
int infected[101];
int cnt;
vector<pair<int, int>> v;

void virus(int std) {
    for (int i = 0; i < edge; i++) {
        if (v[i].first == std && infected[v[i].second] == 0) {
            infected[v[i].second] = 1;
            cnt++;
            virus(v[i].second);
        }
        if (v[i].second == std && infected[v[i].first] == 0) {
            infected[v[i].first] = 1;
            cnt++;
            virus(v[i].first);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> node >> edge;

    for (int i = 0; i < edge; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    infected[1] = 1;
    virus(1);

    cout << cnt << '\n';
}