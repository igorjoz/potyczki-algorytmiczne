#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<vector<long long>> nums, numsCopy;

	cin >> n;

	long long* sums = new long long[n];
	bool* isPossible = new bool[n];

	for (int i = 0; i < n; i++) {
		long long num;
		vector<long long> numVector;

		cin >> num;
		
		numVector.push_back(num);
		numVector.push_back(i);

		isPossible[i] = true;
		nums.push_back(numVector);

		//cerr << nums[i][0] << " " << nums[i][1] << "\t";
	}
	//cerr << "\n\n";

	numsCopy = nums;
	sort(nums.begin(), nums.end());

	/*for (int i = 0; i < n; i++) {
		cerr << nums[i][0] << " " << nums[i][1] << "\t";
	}
	cerr << "\n";*/

	sums[0] = nums[0][0];
	//cerr << sums[0] << " ";
	for (int i = 1; i < n; i++) {
		sums[i] = sums[i - 1] + nums[i][0];
		//cerr << sums[i] << " ";
	}
	//cerr << "\n";
	/*for (int i = 0; i < n; i++) {
		cerr << nums[i][0] << " ";
	}
	cerr << "\n\n";*/

	long long currentNum = nums[0][0];
	int currentIndex = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (sums[i] <= nums[i + 1][0]) {
			int notPossibleIndex = nums[currentIndex][1];
			isPossible[notPossibleIndex] = false;
			//cerr << "FALSE" << " " << currentNum << "\n";

			currentIndex++;
			currentNum = nums[currentIndex][0];
			i = currentIndex - 1;
		}
	}
	//cerr << "\n";

	nums = numsCopy;
	for (int i = 1; i < n; i++) {
		if (nums[i - 1][0] == nums[i][0] and isPossible[i - 1] == false) {
			isPossible[i] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		//cerr << isPossible[i] << " ";
		if (isPossible[i]) {
			cout << "T";
		}
		else {
			cout << "N";
		}
	}
	cout << "\n";

	return 0;
}
