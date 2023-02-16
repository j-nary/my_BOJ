#include <stdio.h>

void Sort(int arr[], int n) {
  int i, j;
  int D;

  for (i = 1; i < n; i++) {
    D = arr[i];

    for(j = i-1; j >=0; j--) {
      if (arr[j] > D)
        arr[j+1] = arr[j];
      else break;
    }

      for (int k = 0; k < 5; k++) {
    printf("%d  ", arr[k]);  
  }
  printf("\n");
      arr[j+1] = D;
  }
}

int main () {
  int arr[5] = {5 ,3, 2, 4, 1};
  int i;

  Sort(arr, sizeof(arr)/sizeof(int));

  for (i = 0; i < 5; i++) {
    printf("%d  ", arr[i]);  
  }
  printf("\n");
  return 0;
}