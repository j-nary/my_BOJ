#include <iostream>

using namespace std;

int main() {
    int arr[10] = {0};
    arr[1] = 1;
    arr[2] = arr[1] * (-1);
    cout << arr[2] << '\n';
}