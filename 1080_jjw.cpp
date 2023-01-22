#include <iostream>

using namespace std;
    int N,M;
    int A[51][51];
    int B[51][51];

void changer(int n, int m){
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
        if(A[n+j][m+i]==0) A[n+j][m+i]=1;
        else A[n+j][m+i]=0;
        }
    }
    
}
//3*3 만큼을 뒤집어주는 함수. 
//예를들어 n,m이 들어오면 이걸 기준으로 3*3만큼 뒤집어줌

int main(){
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%1d",&A[i][j]);
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%1d",&B[i][j]);
        }
    }
// 1개씩 입력받음

    if( N < 3 || M < 3){
        for(int i = 0; i < N; i ++){
            for( int j = 0; j < M; j ++){
                if(A[i][j]!=B[i][j]){
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
//N이나 M이 3 미만이면 못뒤집는데 처음부터 A랑B가 같은 배열이면
//안뒤집어도 되므로 SUM 그대로 COUT
    int sum = 0;
    int cnt = 0;
    bool flag = true;
    while(flag&&cnt<N-2){
        for (int i = 0; i < M-2; i++){
            if(A[cnt][i]==B[cnt][i]){
                continue;
            }
            else{
                changer(cnt,i);
                sum ++;
            }
        }
//배열 A의 왼쪽 맨 위부터 하나씩 B와 비교 시작.
//B와 배열의 값이 같으면 그대로 두고 다르면 CHANGER 함수를 돌린 후
//SUM의 값 1 증가( 한번 뒤집어 준 것이므로)

        if(A[cnt][M-2]==B[cnt][M-2]&&A[cnt][M-1]==B[cnt][M-1]){
            cnt ++;
            continue;
        }
        else{
            flag = false;
        }
    }
//이를 배열에 싹 다 반복

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j ++){
            if(A[i][j]!=B[i][j]){
                flag =false;
                break;
            }
        }
    }
//그렇게 B랑 맞췄는데 예외사항 있을 수 있음. 예를들어 맨 아래 행에는 바뀌지
//A와 B가 다른데 FLAG는 TRUE로 처리돼 있을 수 있음. 따라서 배열 싹 돌면서
//A랑 B 틀린거 있는지 확인하고 있으면 FLAG를 FALSE로 바꿈

    if(flag==true) cout << sum;
    else cout << "-1";
    

}