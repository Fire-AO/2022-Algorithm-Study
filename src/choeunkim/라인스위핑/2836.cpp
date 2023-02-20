#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int, int>> car;
	
	int n;
	int m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int from, to; // �����, ������
		cin >> from >> to;
		if (from > to) {
			car.push_back(pair<int, int>(to, from));
		}
	}
	sort(car.begin(), car.end()); // �������� ����

	long long result = m;
	int left = -1;
	int right = -1;

	for (int i = 0; i < car.size(); i++) {
		if (car[i].first > right) {
			result += (right - left) * 2; // ���������� ���ٰ� ���������� ���ư���
			left = car[i].first;
			right = car[i].second;
		}
		else {
			right = max(right, car[i].second); 
		}
	}

	result += (right - left) * 2;
	cout << result;
	return 0;
}