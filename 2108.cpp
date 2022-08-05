#include <iostream>
#include <algorithm>

using namespace std;

int Data[500005];
int Posi[4004];
int Neg[4004];
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
    if ((int)(Average * 10) % 10 >= 5)  //»ê¼úÆò±Õ
        cout << (int)Average + 1 << endl;
    else
        cout << (int)Average << endl;

    sort(Data, Data + N);    
    cout << Data[N / 2] << endl;    //Áß¾Ó°ª


    /**********ÃÖºó°ª**********/
    int *tmp = Posi;
    int *tmp2 = Neg;
    while(1) {
        sort(tmp, tmp + 4004, greater<>());
        sort(tmp2, tmp2 + 4004, greater<>());
        if (tmp[0] > tmp2[0] && tmp[0] == tmp[1]) {
            for (int i = 0; i < N; i++) {
                if (tmp[0] == Posi[i] || tmp[0] == Neg[i]) {
                    Posi[i] = 0;
                    Neg[i] = 0;
                }
            }
        }
        else if (tmp[0] < tmp2[0] && tmp2[0] == tmp2[1]) {
            for (int i = 0; i < N; i++) {
                if (tmp2[0] == Posi[i] || tmp2[0] == Neg[i]) {
                    Posi[i] = 0;
                    Neg[i] = 0;
                }
            }
        }
        else if (tmp[0] == tmp2[0]) {
            for (int i = 0; i < N; i++) {
                if (tmp[0] == Posi[i] || tmp[0] == Neg[i]) {
                    Posi[i] = 0;
                    Neg[i] = 0;
                }
            }        
        }
        else break;
    }
    int MaxValue = Data[0];
    int cnt = 0;
    for (int i = 0; i < 4004; i++) {
        if (cnt < Posi[i]) 
            MaxValue = i;
        if (cnt < Neg[i])
            MaxValue = -i;
    }    
    cout << MaxValue << endl;


    /**********¹üÀ§**********/
    int Max = Data[0];
    int Min = Data[0];
    for (int i = 1; i < N; i++) {
        Max = max(Max, Data[i]);
        Min = min(Min, Data[i]);
    }
    cout << Max - Min << endl;
}