//BOJ_2576 홀수 [브론즈 3]

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int sum = 0;
    int minValue = 1000;
    for (int i = 0; i < 7; i++) {
        int input; cin >> input;
        if (input % 2) { 
            sum += input;
            minValue = min(minValue, input);
        }
    }
    if (!sum) {
        cout << -1 << endl;
        return 0;
    }
    cout << sum << endl << minValue << endl;
}