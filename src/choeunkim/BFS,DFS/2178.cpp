#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define X first
#define Y second
#define MAX_ 101

int board[MAX_][MAX_];
int result = 0;
int vis[MAX_][MAX_]; //�湮Ȯ��

int N, M;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS(int x, int y) {
	vis[x][y] = 1;
	queue<pair<int, int>>Q;
	Q.push(pair<int, int>(x, y));
	//Q.push({ x,y });

	while (!Q.empty()) {
		//���� ���� ������
		pair<int, int> cur = Q.front();
		Q.pop();
		//�ֺ� Ȯ��
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if ((0 <= nx && nx < N) && (0 <= ny && ny < M)) { //���� �ȿ���
				if (vis[nx][ny] == -1 && board[nx][ny] == 1) { //�̵� ���� ������ �湮 ó�� �ȵǾ��� �� �湮���� ����
					vis[nx][ny] = vis[cur.X][cur.Y] + 1; // �Ÿ��� �����ϴ� �ǹ̸� ���� �� �𸣰���
					result++;// �̷��� �׳� 1�� ���� �� ���� ��... ���� ��� �ȶ�����, result �ʿ����
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void) {
	cin >> N >> M; // n���� ��, m���� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &board[i][j]);
			vis[i][j] = -1; //��� �� -1�� ����
		}
	}
	BFS(0, 0);
	cout << vis[N - 1][M - 1] << endl;
	return 0;
}