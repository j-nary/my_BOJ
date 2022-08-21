#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sang[10000007];
bool nsang[10000007];
int geun[500005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp = 0;
        cin >> tmp;
        if (tmp >= 0) sang[tmp] = true;
        else nsang[-tmp] = true;
    }
    cin >> M;
    for (int i = 0; i < M; i++) cin >> geun[i];

    for (int i = 0; i < M; i++) {
        if (geun[i] >= 0 && sang[geun[i]] == true) cout << 1 << " ";
        else if (geun[i] < 0 && nsang[-geun[i]] == true) cout << 1 << " ";
        else cout << 0 << " ";
    }

    cout << '\n';
}