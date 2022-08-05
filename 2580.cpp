#include <iostream>
#include <vector>
using namespace std;

bool isVal(int r, int c, int val);
bool sudoku(int);

int map[10][10];
vector<pair<int, int>> v;
int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int data; cin >> data;
            map[i][j] = data;
            if (data == 0)
                v.push_back(make_pair(i, j));
        }
    }
    if (!v.empty())
        sudoku(0);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

bool sudoku(int depth) {
    if (depth == v.size())
        return true;

    int r = v[depth].first;
    int c = v[depth].second;

    for (int i = 1; i <= 9; i++) {
        if (isVal(r, c, i)) {
            map[r][c] = i;
            if (sudoku(depth + 1))
                return true;
            map[r][c] = 0;
        }
    }

    return false;
}

bool isVal(int r, int c, int val) {
    for (int i = 0; i < 9; i++) {
        if (i == c) continue;
        if (map[r][i] == val) return false;
    }

    for (int i = 0; i < 9; i++) {
        if (i == r) continue;
        if (map[i][c] == val) return false;
    }

    for (int i = r/3 * 3; i < r/3 * 3 + 3; i++) {
        for (int j = c/3 * 3; j < c/3 * 3 + 3; j++) {
            if (i == r && j == c) continue;
            if (map[i][j] == val) return false;
        }
    }

    return true;
}