#include <iostream>

using namespace std;

int BinarySearch(int *a, const int x, const int left, const int right) {
    if (left <= right) {
        int middle = (left + right) / 2;
        if (x < a[middle])
            return BinarySearch(a, x, left, middle-1);
        else if (x > a[middle])
            return BinarySearch(a, x, middle+1, right);
        else
            return middle;
    }

    return -1;
}

int main() {
    int *arr = new int[10]{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    //배열 이렇게 초기화해줘도 되는구나.
    cout << "x값을 입력하세요 : ";
    int x;
    cin >> x;
    int index = BinarySearch(arr, x, 0, 9);
    if (index == -1)
        cout << "배열에 해당 x값이 존재하지 않습니다." << endl;
    else {
        cout << "index : " << index << endl;
        cout << "arr[" << index << "] : " << arr[index] << endl;
    }
    return 0;
}

