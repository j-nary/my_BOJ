#include <iostream>
#include <string>
using namespace std;
int n;
void tree(string &arr) {
    if (arr.length() == (unsigned)n) {
        cout << arr << endl;
        return;
    }
    tree(arr+='a');
    arr.pop_back();
    tree(arr+='b');
    arr.pop_back();
}
int main () {
    cin >> n;
    string a = "";
    tree(a);
}


/*
#include <iostream> 

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = n - 1; j >= 0; j?) printf("%c", 'a' + !!(i & (1 << j)));
        printf("\n");
    }
}
*/