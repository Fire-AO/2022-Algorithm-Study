#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 31

int N; // �� ȸ���� ��
int M; // ġŲ ������ ��
int prefer[MAX][MAX];
vector <int> chicken(3);
int answer = 0;

// ���� ����̹Ƿ� 30C3=4060 �� ����� ��
// �� 3���� ġŲ�� N�� Ž���ؼ� �������� �ִ밡 �ǵ��� �ؾ��Ѵ�
void combination(int count, int next) {
	if (count == 3) {
		int total = 0;
		for (int i = 1; i <= N; i++) {
			int max = 0;
			for (int chic : chicken) {
				if (max < prefer[i][chic]) {
					max = prefer[i][chic];
				}
			}
			total += max;
		}
		if (answer < total) {
			answer = total;
		}
		return;
	}
	for (int i = next; i <= M; i++) {
		chicken[count] = i;
		combination(count + 1, i + 1);
	}
	
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> prefer[i][j];
		}
	}
	combination(0, 1);
	cout << answer << endl;
	return 0;
}