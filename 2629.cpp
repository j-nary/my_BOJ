#include <iostream>
#include <vector>

using namespace std;

int chu[31];
int ghu[31][15003];
int c, g;

bool isPos(int depth, int weight) {
    if (weight > 15000) return false;

   // if (weight == 0) return true;
    if (depth == 0 && weight == chu[depth]) return true;
    else if (depth == 0) return false; 

    if (isPos(depth - 1, weight)) return true;
    if (isPos(depth - 1, weight + chu[depth])) return true;
    if (isPos(depth - 1, abs(weight - chu[depth]))) return true;
    
    return false;
}

int main() {
    vector<char> ans;

    cin >> c;
    for (int i = 0; i < c; i++) cin >> chu[i];

    cin >> g;
    for (int i = 0; i < g; i++) {
        int gram;
        cin >> gram;

        if (isPos(c - 1, gram))
            ans.push_back('Y');
        else
            ans.push_back('N');
    }

    for (int i = 0; i < g; i++) {
        cout << ans[i] << " ";
    }
}