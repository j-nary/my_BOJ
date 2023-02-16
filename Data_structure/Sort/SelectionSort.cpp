#include <iostream>
using std::cin;
using std::cout;

template <class T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
    return;
}
void SelectionSort(int *ip, const int cnt) {
    for (int i = 0; i < cnt; i++) {
        int j = i;

        for (int k = i+1; k < cnt; k++)
            if (ip[k] < ip[j]) j = k;
        
        swap(ip[i], ip[j]);
    }
}

int main() {
    int *ap = new int[5];
    for (int i = 0; i < 5; i++) {
        cin >> ap[i];
    }
    SelectionSort(ap, 5);
    for (int i = 0; i < 5; i++)
        cout << ap[i] << " ";
}

