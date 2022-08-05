#include <iostream>

using namespace std;

int input[1000006];
int main() {
    int T; cin >> T;
    for (int i = 0; i < T; i++) cin >> input[i];

    for (int i = 0; i < T; i++) {
        int flag = 0;
        for (int j = i; j < T; j++) {
            if (input[i] < input[j]) {
                cout << input[j] << " ";
                flag = 1;
                break;
            }
        }
        if (flag == 0) cout << -1 << " ";
    }
}