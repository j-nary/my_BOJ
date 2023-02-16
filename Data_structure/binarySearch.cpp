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
    //�迭 �̷��� �ʱ�ȭ���൵ �Ǵ±���.
    cout << "x���� �Է��ϼ��� : ";
    int x;
    cin >> x;
    int index = BinarySearch(arr, x, 0, 9);
    if (index == -1)
        cout << "�迭�� �ش� x���� �������� �ʽ��ϴ�." << endl;
    else {
        cout << "index : " << index << endl;
        cout << "arr[" << index << "] : " << arr[index] << endl;
    }
    return 0;
}

