#include <iostream>

using namespace std;
int N;
int M;
int arr[10001];


int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//�������� left, right, �հ� sum, ī��Ʈ res
	int l = 0;
	int r = 0;
	int sum = arr[0];
	int res = 0;

	while (l<=r&&r<N) {
		if (sum <= M) {//sum�� �� Ŀ������, r�� ���������� ������
			if (sum == M) { 
				res++;
			}
			sum += arr[++r];
		}
		else { //sum�� �� �۾�������, l�� ���������� ������
			sum -= arr[l++];
			// ���� �����Ͱ� ������ �����͸� ���� ��
			if (l > r) {
				sum = arr[l];
				r = l;
			}
		}
		
	}
	cout << res;

	return 0;
}
