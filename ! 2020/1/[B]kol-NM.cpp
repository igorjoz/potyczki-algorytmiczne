#include <iostream>

using namespace std;

const int N = 1e6 + 7;

int cansQuantity, operations;
int cans[N][3];

int main() {
	cin >> cansQuantity >> operations;

	for (int i = 0; i < operations; i++) {
		int left, right, color;
		cin >> left >> right >> color;

		cans[left][color - 1]++;
		cans[right + 1][color - 1]--;
	}

	int answer = 0;
	for (int i = 1; i <= cansQuantity; i++) {

		cans[i][0] += cans[i - 1][0];
		cans[i][1] += cans[i - 1][1];
		cans[i][2] += cans[i - 1][2];

		if (cans[i][0] > 0 && cans[i][1] > 0 && cans[i][2] == 0) {
			answer++;
		}
	}

	cout << answer;
	return 0;
}