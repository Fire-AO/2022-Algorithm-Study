#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001

int N; // DNA�� ��
int M; // ���ڿ��� ����
string DNA[MAX];
int result=0;
string res;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> DNA[i];
	}

	for (int i = 0; i < M; i++) {
		int dnaCount[4] = { 0, };
		for (int j = 0; j < N; j++) {
			switch (DNA[j][i]) {
			case 'A':
				dnaCount[0]++;
				break;
			case 'C':
				dnaCount[1]++;
				break;
			case 'G':
				dnaCount[2]++;
				break;
			case'T':
				dnaCount[3]++;
				break;
			}
		}

		int max = 0;
		// ���� ���� ������ ACGT ��
		for (int k = 0; k < 4; k++) {
			if (max < dnaCount[k]) max = dnaCount[k];
		}
		// ������ ��� (for loop �ȿ� ����)
		result += (N - max);

		// ���ĺ� ������ �� �� ��Ʈ���� ����
		if (dnaCount[0] == max) {
			res += 'A';
			continue;
		}
		if (dnaCount[1] == max) {
			res += 'C';
			continue;
		}
		if (dnaCount[2] == max) {
			res += 'G';
			continue;
		}
		if (dnaCount[3] == max) {
			res += 'T';
			continue;
		}

		
		
	}
	cout << res << endl;
	cout << result;
	
	return 0;
}
