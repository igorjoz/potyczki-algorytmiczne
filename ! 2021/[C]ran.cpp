#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int* nums = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	cout << "\n";

	return 0;
}
