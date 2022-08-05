#include <iostream>

using namespace std;

int main() {
    string A; string B;
    cin >> A >> B;

    int tmp;
    tmp = A[0];
    A[0] = A[2];
    A[2] = tmp;
    tmp = B[0];
    B[0] = B[2];
    B[2] = tmp;
    
    for (int i = 0; i < 3; i++) {
        if (A[i] > B[i]) {
            cout << A << endl;
            return 0;
        }
        else if (A[i] < B[i]) { 
            cout << B << endl;
            return 0;
        }
    }
}