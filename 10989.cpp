#include <iostream>

using namespace std;

void Sort(short arr[], int n) {
  int i, j;
  int D;

  for (i = 1; i < n; i++) {
    D = arr[i];

    for(j = i-1; j >=0; j--) {
      if (arr[j] > D)
        arr[j+1] = arr[j];
      else break;
    }
    arr[j+1] = D;
  }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    short *input = new short[T];
    for (int i = 0; i < T; i++) cin >> input[i];

    Sort(input, T);
    for (int i = 0; i < T; i++) cout << input[i] << '\n';
}
