#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> card;
vector<int> lis;

int main(void){
    cin >> n;
    int temp_card;
    for (int i = 0; i < n; i++) {
        cin >> temp_card;
        card.push_back(temp_card);
    }
    lis.push_back(card[0]);
    for (int i = 1; i < n; i++) {
        if(lis.back() < card[i]) lis.push_back(card[i]);
        else{
            lis[lower_bound(lis.begin(),lis.end(),card[i]) - lis.begin()] = card[i];
        }
    }
    cout << lis.size() << endl;
}