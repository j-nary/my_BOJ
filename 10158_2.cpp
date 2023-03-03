#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int w, h; cin >> w >> h;
    int p, q; cin >> p >> q;
    int t; cin >> t;

    bool ap = true, aq= true;
    int tmp;
    while(1) {
        if (ap) {
            if (aq) tmp = min(w-p, h-q);
            else tmp = min(w-p, q);
        } else {
            if (aq) tmp = min(p, h-q);
            else tmp = min(p, q);
        }

        t -= tmp;
        if (ap) p += tmp;
        else p -= tmp;

        if (aq) q += tmp;
        else q -= tmp;

        if (t == 0) break;

        if (p == 0 || p == w) ap = !ap;
        if (q == 0 || q == h) aq = !aq; 
    }

    cout << p << " " << q << '\n';
}