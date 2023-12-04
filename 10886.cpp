#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int c = 0, nc = 0;
    for (int i = 0; i < N; i++) {
        int ip; cin >> ip;
        if (ip) c++;
        else nc++;
    }

    if (c > nc) cout << "Junhee is cute!\n";
    else cout << "Junhee is not cute!\n";
}