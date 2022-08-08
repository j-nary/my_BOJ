#include <iostream>
#include <set>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;    //Q에 적용할 연산의 개수
        multiset<int> ms;

        while (k--) {
            char mode; cin >> mode;
            int input; cin >> input;

            if (mode == 'I') {
                ms.insert(input);
            }
            else if (!ms.empty()){
                if (input == 1) {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
                else 
                    ms.erase(ms.begin());
            }
        }

        if (ms.empty())
            cout << "EMPTY" << '\n';
        else {
            auto iter = ms.end();
            iter--;

            cout << *iter<< " " << *ms.begin() << '\n';
        }
    }
}