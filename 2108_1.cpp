#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Data[500005];
int Posi[4004];
int Neg[4004];

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main() {
    int sum = 0;

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Data[i];
        sum += Data[i];
        if (Data[i] >= 0)
            Posi[Data[i]]++;
        else
            Neg[-Data[i]]++;
    }
    
    double Average = (double) sum / N;
    if (Average >= 0) {
        if ((int)(Average * 10) % 10 >= 5)  //»ê¼úÆò±Õ
            cout << (int)Average + 1 << endl;
        else {
            cout << (int)Average << endl;
        }
    } else {
        if ((int)(-Average * 10) % 10 >= 5)  //»ê¼úÆò±Õ
            cout << (int)Average - 1 << endl;
        else {
            cout << (int)Average << endl;
    }
    }

    sort(Data, Data + N);    
    cout << Data[N / 2] << endl;    //Áß¾Ó°ª


    /**********ÃÖºó°ª**********/
    vector<pair<int, int>> v;
    int cnt = 0;
    for (int i = 0; i < 4004; i++) {
        if (Posi[i] != 0) {
            v.push_back(make_pair(Posi[i], i));
        }
        if (Neg[i] != 0) {
            v.push_back(make_pair(Neg[i], -i));
        }
    }
    sort(v.begin(), v.end(), compare);
    if (v[0].first == v[1].first)
        cout << v[1].second << endl;
    else
        cout << v[0].second << endl;
        
    /**********¹üÀ§**********/
    int Max = Data[0];
    int Min = Data[0];
    for (int i = 1; i < N; i++) {
        Max = max(Max, Data[i]);
        Min = min(Min, Data[i]);
    }
    cout << Max - Min << endl;
}