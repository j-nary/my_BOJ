#include <iostream>

using namespace std;

int card[102];  //카드에는 양의 정수만
int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> card[i];

    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            for (int k = j+1; k < N; k++) {
                int sum = card[i] + card[j] + card[k];
                if (sum <= M && sum > res)
                    res = sum;
            }
    
    cout << res << endl;
}