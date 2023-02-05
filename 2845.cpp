#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    int party = a * b;

    for (int i = 0; i < 5; i++) {
        int news; cin >> news;
        cout << news-party << " ";
    }
    cout << '\n';
}