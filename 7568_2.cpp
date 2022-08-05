#include <iostream>

using namespace std;

int grade[52];
int dungchi[52][2];

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> dungchi[i][0] >> dungchi[i][1];
    }

    for (int i = 1; i <= T; i++) {
        int cnt = 1;
        for (int j = 1; j <= T; j++) {
            if (dungchi[i][0] < dungchi[j][0] && dungchi[i][1] < dungchi[j][1]) 
                cnt++;
        }
        grade[i] = cnt;
    }

    for (int i = 1; i <= T; i++) 
        cout << grade[i] << " ";

    cout << endl;
}