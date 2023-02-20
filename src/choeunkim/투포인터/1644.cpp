#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 4000000;

long long minF[MAX];

vector<int> prime;



//�����佺�׳׽��� ü ����

void eratosthenes(void)

{
    minF[0] = minF[1] = -1;

    for (long long i = 2; i < MAX; i++) {
        minF[i] = i;
    }

    for (long long i = 2; i < MAX; i++) {

        if (minF[i] == i) {
            for (long long j = i * i; j < MAX; j += i) {
                if (minF[j] == j) {
                    minF[j] = i;
                }
            }
        }
    }

    for (int i = 2; i < MAX; i++) {
        if (minF[i] == i) {
            prime.push_back(i);
        }
    }

}



int main(void)

{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;

    cin >> N;

    eratosthenes(); // ü�� �Ҽ��� �Ÿ���

    int l = 0, r = 0;

    int sum = prime[0];

    int result = 0;

    //�� ������ �˰��� ����

    while (l <= r && r < prime.size() && prime[l] <= N)

    {

        if (sum < N) {
            sum += prime[++r];
        }
        else if (sum == N)

        {
            result++;
            sum += prime[++r];
        }

        else if (sum > N)

        {
            sum -= prime[l++];
            if (l > r && l < prime.size())
            {
                r = l;
                sum = prime[l];
            }
        }
    }

    cout << result << endl;

    return 0;

}