#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
void Adjust(T *a, const int root, const int n) {
    T e = a[root];      //e에 대한 적절한 위치 탐색
    int j;
    for (j = 2 * root; j <= n; j *= 2) {
        if (j < n && a[j] < a[j+1]) j++;    //j는 부모의 최대 자식
        if (e >= a[j]) break;       //e는 j의 부모로 삽입
        a[j / 2] = a[j];    //j번째 레코드를 트리 위로 이동
    }   //leaf node까지 반복
    a[j / 2] = e;
}

template <class T>
void HeapSort(T *a, const int n) {
    for (int i = n/2; i > 1; i--)   //힙으로 조정
        Adjust(a, i ,n);
    
    for (int i = n-1; i >= 1; i--) {
        swap(a[1], a[i+1]);     //현재 힙의 처음과 마지막 교환
        Adjust(a, 1, i);    
    }
}

int main() {
    int arr[5] = {5, 2, 1, 3, 4};
    HeapSort(arr, 5);

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}