#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int check[30];

int main() {
    string word;
    cin >> word;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] >= 97)
            word[i] -= 32;
    }

    for (int i = 0; i < word.length(); i++) {
        check[word[i]-65]++;
    }

    // cout << "word : " << word << endl;
    // cout << "check : ";

    int max = -1;
    int index = 0;
    for (int i = 0; i < 30; i++) {
        if (max < check[i]) {
            max = check[i];
            index = i;
        }
        else if (max == check[i]) {
            index = -1;
        }
    }

    if (index == -1) {
        cout << "?" << endl;
        return 0;
    }

    printf("%c\n", index+65);
}