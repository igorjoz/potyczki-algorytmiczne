#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int* nums = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n, greater<int>());

    int counter = 1;
    int i = 0;
    while (i < n and (i + 1 < k or (i + 1 < n and nums[i] == nums[i + 1]))) {
        counter++;
        i++;
    }

    cout << counter << "\n";

    return 0;
}