#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string input; // �Է¹��� ��
	cin >> input;

	int res = 0;
	string num;
	bool isMinus = false; // - �� �������� �Ǻ�

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