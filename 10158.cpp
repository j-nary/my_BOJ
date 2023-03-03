#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int w, h; cin >> w >> h;
    int p, q; cin >> p >> q;
    int t; cin >> t;

    bool ap = true, aq= true;
    while(t--) {
        if (ap) p++;
        else p--;

        if (aq) q++;
        else q--;

        if (p == 0 || p == w) ap = !ap;
        if (q == 0 || q == h) aq = !aq; 
    }

    cout << p << " " << q << '\n';
}