#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int input;
    for (int i = 0; i < 5; i++) {
        cin >> input;
        if (input < 40)
            sum += 40;
        else
            sum += input;
    }
    cout << sum / 5 << endl;
}