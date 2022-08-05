#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> input;
void WordSort(const int cnt) {
    for (int i = 0; i < cnt; i++) {
        int j = i;

        for (int k = i+1; k < cnt; k++)
            if (input[k].length() < input[j].length()) j = k;
            else if (input[k].length() == input[j].length()) {
                int tmp = max(input[k].length(), input[j].length());
                for (int v = 0; v < tmp; v++) {
                    if (input[k][v] < input[j][v]) {
                        j = k; break;
                    }
                    else if (input[k][v] > input[j][v]) break;
                }
            }
        
        swap(input[i], input[j]);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        input.push_back(s);
    }
    
    WordSort(N);
    input.erase(unique(input.begin(), input.end()), input.end());


    for (auto it = input.begin(); it != input.end(); it++)
        cout << *it << '\n';
}