#include <iostream>
#include <algorithm>

using namespace std;

char word[11];
char res[11];
int idx;
int cnt;

void Permutations(const int H, const int T) {
    if ( H == T) {
        cnt++;
        if (idx == cnt) {
            for (int i = 0; i <= T; i++)
                cout << word[i];
            cout << " " << idx << " = ";
            for (int i = 0; i <= T; i++)
                cout << res[i];
            cout << endl;
        }
    }
    else {
        for (int i = H; i <= T; i++) {
            swap(res[H], res[i]);
            Permutations(H+1, T);
            swap(res[H], res[i]);
        }
    }
    
    return;
}

int main() {
    while(1) {
        string s;
        cin >> s;
        if ( s == "\n") break;
        cin >> idx;
        for (int i = 0; i < s.length(); i++) {
            word[i] = s[i];
            res[i] = s[i];
        }
        Permutations(0, s.length()-1);
    }
}
