#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_ 100
#define X first
#define Y second

//�ܼ��ϰ� ����� ���� ã�� �����̹Ƿ� DFS�� BFS ��� ��� ����.
//��ǻ�ͳ��� ������ �ȴٸ� ��������� ����� ��
//1,2 �� ���� �ƴٸ� 2,1�� ��������� ��

int board[MAX_][MAX_];
int vis[MAX_];
int result = -1; //1�� ��ǻ�� ����  

void DFS(int n, int com) {
	vis[com] = 1; //���� Ȯ��
	result++;
	for (int i = 1; i < n+1 ; i++) {
		if (vis[i] == 1) { // �̹� ���� Ȯ�� ��
			continue;
		}
		if (board[com][i] == 0) { //���� �ȵ��� ���� �ѱ�
			continue;
		}
		DFS(n, i); //��ǻ�� ������ �Ȱ���, ������ ��ǻ�Ͱ� ����
	}
} 

int main(void) {
	int n;
	int con;
	int a, b;
	scanf("%d", &n);
	scanf("%d", &con);
	for (int i = 0; i < con; i++) {
		scanf("%d %d", &a, &b);
		board[a][b] = 1; // ����
		board[b][a] = 1;
	}
	DFS(n, 1);
	cout << result << endl;
	return 0;
}

