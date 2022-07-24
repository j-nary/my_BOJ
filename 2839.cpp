#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tmp = n/5+1;
    if (n%5 == 0) tmp--;
    while (tmp <= n/3) {
        int i = 0;
        for(int j = 0; j <= tmp; j++) {
            if(n == tmp*5-i++*2) {
                cout << tmp << endl;
                return 0;
            }
        }
        tmp++;
    }

    cout << -1 << endl;
}