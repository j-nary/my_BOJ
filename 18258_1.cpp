#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;

    int T; cin >> T;
    while(T--) {
        string menu;
        cin >> menu;

        if (menu == "push") {
            int num; cin >> num;
            q.push(num);
        }
        else if (menu == "pop")
            q.pop();
        else if (menu == "size")
            cout << q.size() << endl;
        else if (menu == "empty")
            cout << q.empty() << endl;
        else if (menu == "front")
            cout << q.front() << endl;
        else if (menu == "back")
            cout << q.back() << endl;
    }
}