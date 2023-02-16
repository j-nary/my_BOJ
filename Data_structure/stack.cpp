#include <iostream>

using namespace std;

template<class T>
class Stack {
    private:
        T *stack;       //���� ���Ҹ� ���� �迭
        int top;        //�� ������ ��ġ
        int capacity;   //���� �迭�� ũ��
    
    public:
        Stack () {
            top = -1;
            capacity = 10;
            stack = new T[10];
        }

        void Push (T input) {   //���� �����ϱ�
            if (top != capacity)
                stack[++top] = input;    
            else {                      //��������ȭ�� ���� �����Ҵ�
                capacity *= 2;
                T *newterm = stack;
                stack = new T[capacity];
                stack = newterm;
                stack[++top] = input;
            }
        }

        void Pop() {            //top�� �ִ� ���� �����ϱ�
            top--;
        }
        T Peak() {              //�������� �ʰ� top�� �ִ� ���� �̾ƿ���
            return stack[top];
        }

        void allPrint() {
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << endl;
            }
        }
};

int main() {
    cout << "���� Ȱ�� ����!============================" << endl;
    int menu = 0;
    Stack <int>myStack;
    int tmp;

    while(1) {
        cout << "�޴� : Push(1��), Pop(2��), Peak(3��), �������(4��), ������(0��) >> ";
        cin >> menu;
        switch(menu) {
            case 0:
                return 0;
            case 1:
                cout << "Push�� �������� �Է��ϼ��� >>";
                cin >> tmp;
                myStack.Push(tmp);
                break;
            case 2:
                myStack.Pop();
                break;
            case 3:
                cout << myStack.Peak() << endl;
                break;
            case 4:
                myStack.allPrint();
                break;
        }
    }
}