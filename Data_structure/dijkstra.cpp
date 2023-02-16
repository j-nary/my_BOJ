#include <iostream>
#include <vector>

using namespace std;

#define INF 999999

void dijkstra (int n, const int W[6][6], vector<pair<int, int> > &F) {
    int touch[6];
    int length[6];

    for (int i = 2; i <= n; i++) {
        touch[i] = 1;
        length[i] = W[1][i];
    }

    int vnear = 0;
    int k = n-1;
    while (k--) {
        int min = INF;
        for (int i = 2; i <= n; i++) {
            if (0 <= length[i] && length[i] <= min) {
                min = length[i];
                vnear = i;
            }
        }

    F.push_back(make_pair(touch[vnear], vnear));

        for (int i = 2; i <= n; i++) {
            if (length[vnear] + W[vnear][i] < length[i]) {
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        }
        length[vnear] = -1;
    }
}

int main() {
    vector<pair<int, int> > F;
    int W[6][6] = {{INF, INF, INF, INF, INF, INF},
                    {INF, 0, 7, 4, 6, 1},
                    {INF, INF, 0, INF, INF, INF},
                    {INF, INF, 2, 0, 5, INF},
                    {INF, INF, 3, INF, 0, INF},
                    {INF, INF, INF, INF, 1, 0}};
    dijkstra(5, W, F);

    cout << "교재의 입력데이터 Figure 4.8로 테스트" << endl;
    for (int i = 0; i < F.size(); i++) {
        cout << F[i].first << "-" << F[i].second << endl;
    }
}