#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            cout << '*';
        }
        cout <<'\n';
    }
}