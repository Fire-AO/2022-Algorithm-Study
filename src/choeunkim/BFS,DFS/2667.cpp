#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define MAX_SIZE 25

int s; //���� ũ��
int numHouse[MAX_SIZE*MAX_SIZE] = { 0, };
int number = 0;
int guide[MAX_SIZE][MAX_SIZE]; //����
int house[MAX_SIZE][MAX_SIZE]; //���� �ִ� ��
int dx[4] = { 1,0,-1,0 }; //��, �Ʒ�, ������, ��, ���� ����
int dy[4] = { 0,1,0,-1 }; //��

void BFS(int x, int y) {
	queue<pair<int, int>>Q; 
	house[x][y] = 1;
	Q.push(pair<int, int>(x, y));
	numHouse[number]++;
	while (!Q.empty()) {
		//���� ���� ������
		pair<int, int> cur = Q.front();
		Q.pop();
		//�ֺ� Ȯ��
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			//������ ����� �ʰ�
			if (0 <= nx && nx < s && 0 <= ny && ny < s) {
				//�������� �湮���� �ʾҴٸ� �湮���� ��ȯ
				if (guide[nx][ny] == 1 && house[nx][ny]==0) {
					house[nx][ny] = 1;
					Q.push(pair<int, int>(nx, ny)); //ť�� �߰�
					numHouse[number]++; //������ ������ �߰�
				}
			}
		}

	}

}
int main(void) {
	scanf("%d", &s); 
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			scanf("%1d", &guide[i][j]);
		}
	}
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (guide[i][j] == 1 && house[i][j] == 0) {
				number++;
				BFS(i, j); //BFS Ž�� -> �ʺ� �켱 Ž��
			}
		}
	}
	sort(numHouse + 1, numHouse + number + 1);
	printf("%d\n", number);
	for (int i = 1; i <= number; i++) {
		printf("%d\n", numHouse[i]);
	}
	return 0;
}
//#include <bits/stdc++.h> ��� ��Ŭ��� Ÿ���� ���� �ʾƵ� ��, �뷮 ���̰� ����
//ios::sync_with_stdio(0); cpp�� iostream�� c�� stdio�� ����ȭ, ���� �ӵ��� ������


