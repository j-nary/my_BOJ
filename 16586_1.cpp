#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    list<int> lt(N);
    for (int i = 1, j = 0; i <= N; i++, j++)
        lt.push_back(i);

    vector<pair<int, int>> v;
    int a, b;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    list<int>::iterator iter = lt.begin();
    for (int i = 0; i < Q; i++) {
        int tgt = v[i].second;  //1
        int mov = v[i].first;   //4

        int tidx, midx;
        for (iter = lt.begin(); iter != lt.end(); iter++) {
            if (*iter == tgt)
                tidx = *iter;   //0
            if (*iter == mov)
                midx = *iter;   //3
        }
        
        iter = lt.begin();
        for (int i = 0; i < tidx + 1; i++)
            iter++;
        lt.insert(iter, mov);

        if (tidx < midx) {
            iter = lt.begin();
            for (int i = 0; i < midx + 1; i++)
                iter++;
            lt.erase(iter);
            cout << tidx - midx + 1 << '\n';
        }
        else {                    
            iter = lt.begin();
            for (int i = 0; i < midx; i++)
                iter++;
            lt.erase(iter);
            cout << tidx - midx << '\n';
        }
    }

    for (auto i = lt.begin(); i != lt.end(); i++) {
        cout << *i << " ";
    }
    cout << '\n';
}