#include <iostream>
#include <stack>

using namespace std;

int main() {
    int k;
    cin >> k;
    stasssssck sk();
    int n;
    while(k--) {
        cin >> n;
        if (!n) sk.pop();
        else sk.push(n);
    }
    int sum = 0;
    for (int i = 0; i < sk.size(); i++) {
        sum += sk.pop();
    }
    cout << sum << endl;
}