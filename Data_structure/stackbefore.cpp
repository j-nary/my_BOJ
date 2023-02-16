#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack {
    private:
        T* data;
        int capacity;
        int top;
    public:
        Stack() {
            capacity = 10;
            data = new T[capacity];
            top = 0;
        }
        void Push(T d) {
            if(top == capacity-1){
                T* tmp = data;
                capacity*=2;
                data = new T[capacity];
                for(int i = 0; i < capacity/2; i++)
                    data[i] = tmp[i];
            }
            data[top++] = d;
        }
        void Pop() {
            cout<< data[top];
            data[top--] = 0;
        }
        void AllPrint() {
            for (int i = 0; i <= top; i++) {
                if (i == top)
                    cout << "top : " << data[top]<<endl;
                else
                    cout<< i << "번째 원소 : " << data[i]<<endl;
            }
        }
        int OutCap() {
            return capacity;
        }
};

int main() {
    Stack<int>* jnary = new Stack<int>();
    for (int i = 10; i <= 100; i*=10) {
        jnary -> Push(i);
    }
    jnary->Pop();
    jnary->AllPrint();
}