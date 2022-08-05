#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    while(1) {
        int tri[3];
        cin >> tri[0] >> tri[1] >> tri[2];

        if (tri[0] == tri[1] && tri[1] == tri[2] && tri[1] == 0) break;

        sort(tri, tri+3);

        int cal = (tri[0] * tri[0]) + (tri[1] * tri[1]);

        if (cal == tri[2] * tri[2])
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
}