#include <iostream>

using namespace std;

void Permutations(char *a, const int H, const int T) {
    if ( H == T) {
        for (int i = 0; i <= T; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    else {
        for (int i = H; i <= T; i++) {
            swap(a[H], a[i]);
            Permutations(a, H+1, T);
            swap(a[H], a[i]);
        }
    }
    
    return;
}

int main() {
    char *arr = new char[5] {'a', 'b', 'd', 'e', 'c'};
    Permutations(arr, 0, 4);
    return 0;
}
