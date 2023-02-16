#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
void Adjust(T *a, const int root, const int n) {
    T e = a[root];      //e�� ���� ������ ��ġ Ž��
    int j;
    for (j = 2 * root; j <= n; j *= 2) {
        if (j < n && a[j] < a[j+1]) j++;    //j�� �θ��� �ִ� �ڽ�
        if (e >= a[j]) break;       //e�� j�� �θ�� ����
        a[j / 2] = a[j];    //j��° ���ڵ带 Ʈ�� ���� �̵�
    }   //leaf node���� �ݺ�
    a[j / 2] = e;
}

template <class T>
void HeapSort(T *a, const int n) {
    for (int i = n/2; i > 1; i--)   //������ ����
        Adjust(a, i ,n);
    
    for (int i = n-1; i >= 1; i--) {
        swap(a[1], a[i+1]);     //���� ���� ó���� ������ ��ȯ
        Adjust(a, 1, i);    
    }
}

int main() {
    int arr[5] = {5, 2, 1, 3, 4};
    HeapSort(arr, 5);

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}