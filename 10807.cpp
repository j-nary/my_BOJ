#include <iostream>

using namespace std;

int cnt[101];
int ncnt[101];
int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if (tmp >= 0)
            cnt[tmp]++;
        else
            ncnt[-tmp]++;
    }

    int v; cin >> v;
    if (v >= 0)
        cout << cnt[v] << endl;
    else
        cout << ncnt[-v] << endl;
}