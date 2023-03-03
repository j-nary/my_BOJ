#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int w, h; cin >> w >> h;
    int p, q; cin >> p >> q;
    int pt; cin >> pt;
    int qt = pt;
    bool ap = true, aq= true;
    int tmp;
    while(1) {
        if (ap) {
            tmp = w - p;
        } else {
            tmp = p;
        }

        if (tmp > pt) {
            if (ap) p += pt;
            else p -= pt;
            break;
        }

        if (ap) p += tmp;
        else p -= tmp;
        pt -= tmp;

        if (p == 0 || p == w) ap = !ap;
    }

    while(1) {
        if (aq) {
            tmp = h - q;
        } else {
            tmp = q;
        }

        if (tmp > qt) {
            if (aq) q += qt;
            else q -= qt;
            break;
        }

        if (aq) q += tmp;
        else q -= tmp;
        qt -= tmp;

        if (q == 0 || q == h) aq = !aq;
    }
    cout << p << " " << q << '\n';
}