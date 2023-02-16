#include <iostream>

using namespace std;

template<class T>
class Stack {
    private:
        T *stack;       //스택 원소를 위한 배열
        int top;        //톱 원소의 위치
        int capacity;   //스택 배열의 크기
    
    public:
        Stack () {
            top = -1;
            capacity = 10;
            stack = new T[10];
        }

        void Push (T input) {   //원소 삽입하기
            if (top != capacity)
                stack[++top] = input;    
            else {                      //공간최적화를 위한 공간할당
                capacity *= 2;
                T *newterm = stack;
                stack = new T[capacity];
                stack = newterm;
                stack[++top] = input;
            }
        }

        void Pop() {            //top에 있는 원소 삭제하기
            top--;
        }
        T Peak() {              //삭제하지 않고 top에 있는 원소 뽑아오기
            return stack[top];
        }

        void allPrint() {
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << endl;
            }
        }
};

int main() {
    cout << "스택 활용 시작!============================" << endl;
    int menu = 0;
    Stack <int>myStack;
    int tmp;

    while(1) {
        cout << "메뉴 : Push(1번), Pop(2번), Peak(3번), 스택출력(4번), 끝내기(0번) >> ";
        cin >> menu;
        switch(menu) {
            case 0:
                return 0;
            case 1:
                cout << "Push할 정수값을 입력하세요 >>";
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