#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    string s;
    getline (cin, s);   //���� ������ ���ڿ� �Է¹ޱ�

    if (s.empty()) {
        cout << 0 << endl;
        return 0;
    }
    cnt++;

    if (s[0] == ' ') cnt--;
    if (s[s.length()-1] == ' ') cnt--;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') cnt++;
    }
    cout << cnt << endl;
}