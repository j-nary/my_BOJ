#include <iostream>

using namespace std;

int matrix[101][101];
int main() {
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            int tmp; cin >> tmp;
            matrix[i][j] += tmp;
        }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }

}