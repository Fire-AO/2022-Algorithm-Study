#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> input{};
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num = 0;
		cin >> num;
		input.push_back(num);
	}

	sort(input.begin(), input.end());

	int sum = 0;
	int res = 0;
	for (int i = 0; i < input.size(); i++) {
		sum += input[i];
		res += sum;
	}
	cout << res;
	return 0;
}