#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//이중 우선순위 큐

int main() {
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;    //Q에 적용할 연산의 개수
        vector<int> v;

        while (k--) {
            char mode; cin >> mode;
            int input; cin >> input;
            if (mode == 'I') {
                v.push_back(input);
                sort(v.begin(), v.end());
            }
            else if (!v.empty()){
                if (input == 1)
                    v.erase(v.end()-1);
                else
                    v.erase(v.begin());
            }
        }

        if (v.empty())
            cout << "EMPTY" << '\n';
        else
            cout << v[v.size()]<< " " << v[0] << '\n';
    }
}