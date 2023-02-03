#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int N;
	cin >> T;
	while (T--) {
		int cost;
		long long res = 0;
		cin >> N;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			cin >> cost;
			v.push_back(cost);
		}
		reverse(v.begin(), v.end());

		long long answer = 0;

		for (int i = 0; i < N; i++) {
			if (res < v[i])res = v[i];
			else answer += res - v[i];
		}
		printf("%lld\n", answer);
	}
	return 0;
}
