#include <iostream>

using namespace std;

int grade[52];
int dungchi[52][2];

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> dungchi[i][0] >> dungchi[i][1];
    }

    int rank = 1;
    int cnt = 0;
    while (rank <= T) {
        int bigx = 0;

        for (int i = 1; i <= T; i++) {
            if (grade[i] == 0 && dungchi[bigx][0] == dungchi[i][0] && dungchi[bigx][1] < dungchi[i][1])
                bigx = i;
            else if (grade[i] == 0 && dungchi[bigx][0] < dungchi[i][0])
                bigx = i;
        }

        grade[bigx] = rank;
        cnt++;

        
        for (int i = 1; i <= T; i++) {
            if (grade[i] == 0 && dungchi[bigx][1] < dungchi[i][1]) {
                grade[i] = rank;
                cnt++;
            }
        }

        rank = cnt + 1;
    }

    for (int i = 1; i <= T; i++) {
        cout << grade[i] << " ";
    }
    cout << endl;
}