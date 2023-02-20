#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>line;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;
	while (n--) {
		int st;
		int en;
		cin >> st >> en;
		line.push_back({ st,en });
	}
	sort(line.begin(), line.end()); // ���ʺ��� ���������� ���� ���� ����
	int min = line[0].first;
	int max = line[0].second;
	int res = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i].second < max) {
			continue;
		}
		if (line[i].first > max) {
			//max ���� �ڿ� ���� �� == ���ο� ������ ����
			res += max - min;
			min = line[i].first;
			max = line[i].second;
		}
		else {
			max = line[i].second;
		}
	}

	res += max - min;
	cout << res;
	return 0;


}
