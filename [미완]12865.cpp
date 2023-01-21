//BOJ_12865 평범한 배낭 [골드5]
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;  //물품의 수
int W;  //버틸 수 있는 무게
// int p[5] = {0, 40, 30, 50, 10}; //가치
// int w[5] = {0, 2, 5, 10, 5};    //무게
int p[102];
int w[102];
int maxprofit;
int include[102];
int bestset[102];

bool promising (int i, int profit, int weight) {
    int j, k;
    int totweight;
    float bound;

    if (weight >= W) return false;
    else {
        j = i + 1;
        bound = profit;
        totweight = weight;
        while ((j <= n) && (totweight + w[j] <= W)) {
            totweight = totweight + w[j];
            bound = bound + p[j];
            j++;
        }
        k = j;
        if (k <= n)
            bound = bound + (W - totweight) * p[k]/w[k];
        return bound > maxprofit;
    }
}
void knapsack (int i, int profit, int weight) {
    if (weight <= W && profit > maxprofit) {
        maxprofit = profit;

        for (int j = 0; j < 5; j++) {
            bestset[j] = 0;
        }
        copy(include, include + i + 1, bestset);
    }

    if (promising(i, profit, weight)) {
        include[i+1] = 1; //"YES"를 의미
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
        include[i+1] = 2; //"NO"를 의미
        knapsack(i + 1, profit, weight);
    }
}

bool compare(pair<int, int> a, pair<int, int> b) {
    return (float)a.second/a.first < (float)b.second/b.first;
}
int main() {
    cin >> n >> W;
    vector<pair<int, int> > input;
    for (int i = 0; i < n; i++) {
        int p, q; cin >> p >> q;
        input.push_back(make_pair(p, q));
    
    }
    sort(input.begin(), input.end(), compare);
    for (int i = 1; i <= n; i++) {
        w[i] = input[i].first;
        p[i] = input[i].second;
    }
    
    knapsack(0, 0, 0);
    cout << maxprofit << endl;
}