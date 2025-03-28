#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n, requiredUnique;
	int totalTime = 0;
	set<int> uniqueNums;
	cin >> n >> requiredUnique;

	int* nums = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int replaceIndex = 1, replaceIndexNum = nums[1];
	uniqueNums.insert(nums[0]);

	for (int i = 1; i < n; i++) {
		if (uniqueNums.size() >= requiredUnique) {
			break;
		}
		
		auto position = uniqueNums.find(nums[i]);

		//cerr << "replaceIndex: " << replaceIndex << "\t";
		if (position == uniqueNums.end()) {
			//cerr << "Not in set -> " << nums[i] << "\t";
			totalTime += i - replaceIndex;
			replaceIndex++;
			replaceIndexNum = nums[replaceIndex];
			uniqueNums.insert(nums[i]);
		}
		//cerr << "size: " << uniqueNums.size() << "\t totalTime: " << totalTime << "\n";
	}

	if (uniqueNums.size() < requiredUnique) {
		cout << -1 << "\n";
	}
	else {
		cout << totalTime << "\n";
	}

	return 0;
}
