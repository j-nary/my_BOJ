#include <iostream>
#include <algorithm>

using namespace std;

char draw[50][50];
int N, M;
int res;

void check(const int i, const int j) {
    char tmp_draw[8][8];

    int k = 0;
    for (int a = i; a < i + 8; a++, k++) {
        int l = 0;
        for (int b = j; b < j + 8; b++, l++) {
            tmp_draw[k][l] = draw[a][b];
        }
    }

    int cnt1 = 0;
    for (int a = 0; a < 8; a++) {
        for (int b = 1; b < 8; b++) {
            if (tmp_draw[a][b-1] == tmp_draw[a][b]) {
                cnt1++;
                if (tmp_draw[a][b-1] == 'W')
                    tmp_draw[a][b] = 'B';
                else
                    tmp_draw[a][b] = 'W';
            }
        }

        if(a+1 < 8 && tmp_draw[a][7] != tmp_draw[a+1][0]) {
            cnt1++;
            if (tmp_draw[a+1][0] == 'W')
                tmp_draw[a+1][0] = 'B';
            else
                tmp_draw[a+1][0] = 'W';            
        }
    }
/***********************************************************/
    k = 0;
    for (int a = i; a < i + 8; a++, k++) {
        int l = 0;
        for (int b = j; b < j + 8; b++, l++) {
            tmp_draw[k][l] = draw[a][b];
        }
    }

    int cnt2 = 1;
    if (tmp_draw[0][0] == 'W')
        tmp_draw[0][0] = 'B';
    else
        tmp_draw[0][0] = 'W';

    for (int a = 0; a < 8; a++) {
        for (int b = 1; b < 8; b++) {
            if (tmp_draw[a][b-1] == tmp_draw[a][b]) {
                cnt2++;
                if (tmp_draw[a][b-1] == 'W')
                    tmp_draw[a][b] = 'B';
                else
                    tmp_draw[a][b] = 'W';
            }
        }
        if(a+1 < 8 && tmp_draw[a][7] != tmp_draw[a+1][0]) {
            cnt2++;
            if (tmp_draw[a+1][0] == 'W')
                tmp_draw[a+1][0] = 'B';
            else
                tmp_draw[a+1][0] = 'W';            
        }
    }

    int cnt = min(cnt1, cnt2);
    res = min(res, cnt);
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> draw[i][j];
    
    res = 999;
    for (int i = 0; i <= N-8; i++) {
        for (int j = 0; j <= M-8; j++) {
            check(i, j);
        }
    }

    cout << res << endl;
}