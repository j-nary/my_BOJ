#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T; cin >> T;
    stack<int> s;

    int input;
    while(T--) {
        cin >> input;
        if (input == 0) 
            s.pop();
        else
            s.push(input);
    }
    // cout << "size : " << s.size() << endl;
    if (s.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    int sum = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        sum += s.top();
        s.pop();
    }

    cout << sum << endl;

}