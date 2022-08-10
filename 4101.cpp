#include <iostream>

using namespace std;

int main() {
    while(1){
        int a, b;
        cin >> a >> b;

        if (a == b && b== 0) return 0;

        if (a > b)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}