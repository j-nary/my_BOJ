#include <iostream>
#include <algorithm>

using namespace std;

int input[1003];
int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    
    sort(input, input+N);

    for (int i = 0; i < N; i++)
        cout << input[i] << endl;
}