#include <iostream>

using namespace std;

class MY_Queue {
    private:
        int *queue;
        int front;
        int back;

    public:
        MY_Queue(int n) {
            front = 0;
            back = -1;
            queue = new int[n];
        }
        void push (int input) {
            queue[++back] = input;
        }
        void pop() {
            if (back == -1 || back < front) {
                cout<< -1 << endl;
                front = 0;
                back = -1;
            }
            else cout<< queue[front++] << endl;
        }
        void size() {
            cout << back-front+1 << endl;
        }
        void empty() {
            if ( back == -1 || back < front) cout << 1 << endl;
            else cout << 0 << endl;
        }

        void Front() {
            if (back == -1|| back < front) cout << -1 << endl;
            else cout << queue[front] << endl;
        }

        void Back() {
            if (back == -1|| back < front) cout << -1 << endl;
            else cout << queue[back] << endl;
        }
};

int main() {
    int n;
    cin >> n;
    MY_Queue mq(n);
    string menu;
    while(n--) {
        cin >> menu;
        if (menu == "push") {
            int input;
            cin >> input;
            mq.push(input);
        }
        else if (menu == "pop") mq.pop();
        else if (menu == "size") mq.size();
        else if (menu == "empty") mq.empty();
        else if (menu == "front") mq.Front();
        else if (menu == "back") mq.Back();
    }

    return 0;
}