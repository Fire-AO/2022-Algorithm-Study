#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 16

int N; // �����
int consult[MAX] = { 0, }; // �ɸ��� ����ϼ�
int money[MAX] = { 0, }; // ��� �� �޴� ��
int total_money = 0; // ���� ����

void solve(int day, int cost) { // ��¥�� �Ѿ�
	if (day >= N + 1) {
		total_money = max(total_money, cost);
		return;
	}
	if (day + consult[day] <= N + 1) { // �׳� ��� �� ����ϴµ� �ɸ��� �ð���ŭ �߰��� ���
		solve(day + consult[day], cost + money[day]);
	}
	if (day + 1 <= N + 1) { // �׳� ��� ���ϰ� �������� �Ѿ ���
		solve(day + 1, cost);
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> consult[i] >> money[i];
	}
	solve(1,0);
	cout << total_money << endl;
	return 0;

}
