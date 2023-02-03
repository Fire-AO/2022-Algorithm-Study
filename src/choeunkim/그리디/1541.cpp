#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string input; // 입력받을 값
	cin >> input;

	int res = 0;
	string num;
	bool isMinus = false; // - 가 나오는지 판별

	for (int i = 0; i <= input.size(); i++) {
        if (input[i] == '-' || input[i] == '+' || i == input.size()) {
            if (isMinus) {
                res -= stoi(num);
                num = "";
            }
            else {
                res += stoi(num);
                num = "";
            }
        }
        else {
            num += input[i];
        }

        if (input[i] == '-') {
            isMinus = true;
        }
	}
    cout << res;
}