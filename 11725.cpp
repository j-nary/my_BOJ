//시간초과

#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

ll parent[100005];
int main() {
ios::sync_with_stdio(0); cin.tie(0);
    ll N;
    cin >> N;
    memset(parent, -1, sizeof(parent));
    parent[1] = 0;

    ll idx1 = 0;
    ll idx2 = 0;
    for (ll i = 0; i < N-1; i++) {
        cin >> idx1 >> idx2;
        if (idx1 == 1) {
            parent[idx2] = 1;
        }
        else if (idx2 == 1) {
            parent[idx1] = 1;
        }

        else if (parent[idx1] != -1) {
            parent[idx2] = idx1;
        }
        else if (parent[idx2] != -1) {
            parent[idx1] = idx2;
        }
    }

    for (ll i = 2; i <= N; i++) {
        cout << parent[i] << endl;
    }
}