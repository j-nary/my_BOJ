#include <iostream>
#include <algorithm>
using namespace std;

// °³°°ÀÌ ¸ê¸ÁÇÑ ÄÚµå

int dungchi[52][2];
int grade[52];
int cnt[52];
int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> dungchi[i][0] >> dungchi[i][1];
    }

    int bigx = 0;
    for (int i = 1; i <= T; i++) {
        if (dungchi[bigx][0] < dungchi[i][0])
            bigx = i;
    }

    for (int i = 1; i <= T; i++) {
        if (dungchi[bigx][0] == dungchi[i][0] && dungchi[bigx][1] < dungchi[i][1]) {
            bigx = i;
        }
    }
    int flag = 1;
    grade[bigx] = 1; cnt[flag]++;
    for (int i = 0; i < T; i++) {
        if (dungchi[bigx][0] == dungchi[i][0] && dungchi[bigx][1] == dungchi[i][1]) {
            bigx = i;
            grade[bigx] = 1; cnt[flag]++;
        }
    }

    for (int k = 0; k < T; k++) {
        flag = flag + cnt[flag];
        bigx = 0;
        for (int j = 0; j < T; j++) {
            if (grade[j] == 0 && dungchi[bigx][0] < dungchi[j][0])
                bigx = j;
        }
        for (int i = 1; i <= T; i++) {
            if (dungchi[bigx][0] == dungchi[i][0] && dungchi[bigx][1] < dungchi[i][1]) {
                bigx = i;
            }
        }

        grade[bigx] = 1; cnt[flag]++;
        for (int i = 0; i < T; i++) {
            if (dungchi[bigx][0] == dungchi[i][0] && dungchi[bigx][1] == dungchi[i][1]) {
                bigx = i;
                grade[bigx] = 1; cnt[flag]++;
            }
        }

        for (int i = 0; i < T; i++) {
            if (grade[i] == 0 && dungchi[bigx][1] < dungchi[i][1]) {
                grade[i] = flag;
                cnt[flag]++;
            }
        }
    }

    for (int i = 1; i <= T; i++)
        cout << grade[i] << " ";
    
    cout << endl;
}