#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;

    int k = 665;
    while (N != 0) {
        k++;
        int tmp = k;
        while (1) {
            if (tmp % 1000 == 666) {
                N--;
                break;
            }
            tmp /= 10;
            if (tmp == 0) break;
        }
    }
    
    cout << k << endl;
}