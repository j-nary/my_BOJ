#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int input[100005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    stack<int> s;
    queue<char> output;

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> input[i];

    int cnt = 0;
    for (int i = 1; cnt < n; i++) {
        if (i == n+1 && input[cnt] != s.top()) {
            cout << "NO\n";
            return 0;
        }

        if (!s.empty() && s.top() == input[cnt]) {
            output.push('-');
            s.pop();
            cnt++; i--;
        }
        else {
            output.push('+');
            s.push(i);
        }
    }

    // cout << "Å©±â : " << output.size() << endl;

    int len = output.size();
    for (int i = 0; i < len; i++) {
        cout << output.front() << '\n';
        output.pop();
    }
}