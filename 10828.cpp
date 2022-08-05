#include <iostream>

using namespace std;

class MY_Stack {
    private:
        int *stack;
        int top;

    public:
        MY_Stack(int n) {
            top = -1;
            stack = new int[n];
        }

        void push (int input) {
            stack[++top] = input;
        }

        void pop() {
            if (top == -1) cout << -1 << endl;
            else cout << stack[top--]<<endl;
        }

        void size() {
            cout << top+1 << endl;
        }

        void empty() {
            if ( top == -1) cout << 1 << endl;
            else cout << 0 << endl;
        }

        void Top() {
            if (top == -1) cout << -1 << endl;
            else cout << stack[top] << endl;
        }
};

int main() {
    int n;
    cin >> n;
    MY_Stack sk(n);
    string menu;
    while (n--) {
        cin >> menu;
        if (menu == "push") {
            int input;
            cin >> input;
            sk.push(input);
        }
        else if (menu == "pop") sk.pop();
        else if (menu == "size") sk.size();
        else if (menu == "empty") sk.empty();
        else if (menu == "top") sk.Top();
    }    

    return 0;
}