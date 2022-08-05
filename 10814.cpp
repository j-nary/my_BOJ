#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first)
        return false;
    else
        return a.first < b.first;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<pair<int, string>> v;

    int age; string name;
    for (int i = 0; i < N; i++) {
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }
}