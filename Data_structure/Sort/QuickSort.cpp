#include <iostream>

using namespace std;

void QuickSort (int arr[], const int left, const int right) {
    if (left < right) {
        int low = left + 1;
        int high = right + 1;
        int pivot = arr[left];
        
        while (1) {
            do low++; while (arr[low] < pivot && low <=right);
            do high--; while (arr[high] > pivot && high >= left);
            if (low >= high) break;
            swap(arr[low], arr[high]);
        }

        swap(arr[left], arr[high]);

        QuickSort(arr, left, high - 1);
        QuickSort(arr, high + 1, right);
    }
}

int main() {
    int arr[9] = {5, 1, 3, 7, 9, 2, 4, 6, 8};
    QuickSort(arr, 0, 8);

    for (int i = 0; i < 9; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}
