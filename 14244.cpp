#include <iostream>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n;
    cin >> m;
    m--;

    int *check = new int[n];

    for (int i = n-1; i >= 0; i--) {
        if (m-- > 0)
            check[i] = 1;   //���������ϴ� ��
        else
            check[i] = 0;   //����X
    }
/*
    for (int i = 0; i < n; i++ ) {
        cout << check[i] << "   ";
    }
    cout << "test��" << endl;
*/
    int index = 0;
    while (1) {
        if ( index == n-1 ) break;
        if (check[index] == 0) {
            cout << index++ << " " << index << endl;
        }
        else {
            int std = index - 1;
            while(index != n-1) {
                cout << std << " " << ++index << endl;
            }
        }
    }

    delete check;
    return 0;
}