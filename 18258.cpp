#include <iostream>

using namespace std;

template<class T>
class q {
    private:
        T *que;       //���� ���Ҹ� ���� �迭
        int front;
        int end;
        int capacity;

    public:
        q () {
            que = new T[10];
            capacity = 10;
            front = 0;
            end = -1;
        }

        void Push (T input) {   //���� �����ϱ�
            if (end != capacity)
                que[++end] = input;    
            else {                      //��������ȭ�� ���� �����Ҵ�
                capacity *= 2;
                T *newterm = que;
                que = new T[capacity];
                que = newterm;
                que[++end] = input;
            }
        }

        int Pop() {            //top�� �ִ� ���� �����ϱ�
            if (end == front) return -1;
            return que[front++];
        }

        int Size() {
            return end+1;
        }

        int Empty() {
            if (end == front) return -1;
            return 0;
        }

        int Front() {
            if (end == front) return -1;
            return que[front];
        }

        int Back() {
            if (end == front) return -1;
            return que[end];
        }
};

int main() {
    q <int>myStack;

    int T; cin >> T;
    while(T--) {
        string menu;
        cin >> menu;

        if (menu == "push") {
            int num; cin >> num;
            myStack.Push(num);
        }
        else if (menu == "pop")
            myStack.Pop();
        else if (menu == "size")
            cout << myStack.Size() << endl;
        else if (menu == "empty")
            cout << myStack.Empty() << endl;
        else if (menu == "front")
            cout << myStack.Front() << endl;
        else if (menu == "back")
            cout << myStack.Back() << endl;
    }
}