#include <iostream>
#include <set>

using namespace std;

struct Compare {
    bool operator() (const string &a, const string &b) const{
        if (a.size() == b.size())
            return a < b;
        else
            return a.size() < b.size();
    }
};

int main() {
    set<string, Compare> s;
    
    int T; cin >> T;
    string input;
    for (int i = 0; i < T; i++) {
        cin >> input;
        s.insert(input);
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << '\n';
    }
}