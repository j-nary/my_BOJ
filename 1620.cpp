#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

int main() {
    vector<pair<int, string>> v;

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string tmp; cin >> tmp;
        v.push_back(make_pair(i, tmp));
    }

    while(M--) { 
        string input;
        cin >> input;

        if (typeid(input).name() == "int")
            v[int]
    }
}