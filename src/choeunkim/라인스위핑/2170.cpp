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
	sort(line.begin(), line.end()); // 왼쪽부터 오른쪽으로 가기 위한 정렬
	int min = line[0].first;
	int max = line[0].second;
	int res = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i].second < max) {
			continue;
		}
		if (line[i].first > max) {
			//max 보다 뒤에 있을 때 == 새로운 선분의 시작
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
