#include <iostream>

using namespace std;

long long int k;

int main()
{
	cin >> k;

	if (k < 100) {
		cout << k + 1 << endl;
		for (int i = 1; i < k; i++) {
			cout << i + 1 << " " << k + 1 << "\n";
		}
		cout << k + 1 << " " << -1 << "\n";
		cout << -1 << " " << -1 << "\n";
	}
}
