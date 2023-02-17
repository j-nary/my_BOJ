#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int D, H, W; cin >> D >> H >> W;
    int rot = H*H + W*W;
    double a = D / sqrt(rot);
    cout << (int)(H*a) << " " << (int)(W*a) << endl;
}