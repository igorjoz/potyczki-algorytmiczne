// based on Tomasz Czajka solution
// https://sio2.mimuw.edu.pl/c/pa-2020-1/s/415722/source/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	long long sum = 0;
	long long result = 0;

	cin >> n;
	vector<long long> waste;
	waste.reserve(n);

	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;

		sum += x;
		//cerr << sum << "\t";

		if (sum >= 0) {
			auto it = upper_bound(waste.begin(), waste.end(), sum);
			result = n - int(it - waste.begin() + 1);

			/*cerr << sum << " " << int(it - waste.begin() + 1) << " " << result << "\t";
			for (auto num : waste) {
				cerr << num << " ";
			}
			cerr << endl;*/

			if (it == waste.end()) {
				waste.push_back(sum);
			}
			else {
				*it = sum;
			}
		}
		else {
			result = -1;
		}
	}

	cout << result << "\n";
}