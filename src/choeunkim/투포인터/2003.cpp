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

	//투포인터 left, right, 합계 sum, 카운트 res
	int l = 0;
	int r = 0;
	int sum = arr[0];
	int res = 0;

	while (l<=r&&r<N) {
		if (sum <= M) {//sum이 더 커져야함, r이 오른쪽으로 가야함
			if (sum == M) { 
				res++;
			}
			sum += arr[++r];
		}
		else { //sum이 더 작아져야함, l이 오른쪽으로 가야함
			sum -= arr[l++];
			// 왼쪽 포인터가 오른쪽 포인터를 넘을 때
			if (l > r) {
				sum = arr[l];
				r = l;
			}
		}
		
	}
	cout << res;

	return 0;
}
