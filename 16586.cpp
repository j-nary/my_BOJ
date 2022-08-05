#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> arr;
    for (int i = 1, j = 0; i <= N; i++, j++)
        arr.push_back(i);

    vector<pair<int, int>> v;
    int a, b;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    for (int i = 0; i < Q; i++) {
        int tgt = v[i].second;  //1
        int mov = v[i].first;   //4

        int tidx, midx;
        for (int i = 0; i < N; i++) {
            if (arr[i] == tgt)
                tidx = i;   //0
            if (arr[i] == mov)
                midx = i;   //3
        }
        arr.insert(arr.begin() + tidx + 1, mov);
        if (tidx < midx) {
            arr.erase(arr.begin() + midx + 1);
            cout << tidx - midx + 1 << '\n';
        }
        else {
            arr.erase(arr.begin() + midx);
            cout << tidx - midx << '\n';
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}