#include <iostream>
#define MAX 100000

using namespace std;

long long IdxSort[MAX + 5][2];
long long Rank[MAX + 5][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> IdxSort[i][0] >> IdxSort[i][1];
    }

    for (int i = 1; i <= N; i++) {
        int cnt = 1;
        for (int j = 1; j <= N; j++) {
            if (IdxSort[i][0] > IdxSort[j][0]) 
                cnt++;
            else if (IdxSort[i][0] == IdxSort[j][0] && IdxSort[i][1] > IdxSort[j][1])
                cnt++;
        }
        Rank[cnt][0] = IdxSort[i][0];
        Rank[cnt][1] = IdxSort[i][1];
    }

    for (int i = 1; i <= N; i++) {
        cout << Rank[i][0] << " " << Rank[i][1] << "\n";
    }
}