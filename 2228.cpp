#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

vector<int> v;
//�������� ���� ��������  �ִ�
int dp[102][52];
//dp[i][j] : i��°������ input�� j���� �������� ������ ���� ���� �ִ� 
int main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int N; cin >> N; int input; cin >> input;
	v.push_back(input);
	for (int i = 1; i < N; i++) {
		cin >> input;
		v[i] = v[i - 1] + input;
	}
	//�������� 3���̻����� ������ ����� �𸣰ڴ�... 
}
