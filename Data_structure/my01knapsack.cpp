#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 4;
int W = 10;

int p[5] = {0, 14, 8, 21, 20};
int w[5] = {0, 2, 2, 7, 10};

int maxprofit;
int include[5];
int bestset[5];

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

int main() {
    knapsack(0, 0, 0);
    for (int i = 0; i < 5; i++) {
        if (bestset[i] == 1)
            cout << "YES" << " ";
        else if (bestset[i] == 2)
            cout << "NO" << " ";
    }
    cout << endl;
}