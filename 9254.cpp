#include <iostream>

using namespace std;

int arr[502][502];
int I_arr[502][502];
int main() {
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        I_arr[i][i] = 1;
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    }
    
    for (int i = 0; i < N-1; i++) {
        int k = i;
        for (int j = 1; j < N; j++) {
            arr[j][k++]
        }
    }
}