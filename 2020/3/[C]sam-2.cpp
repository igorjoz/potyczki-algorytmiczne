#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct delivery {
	int place;
	int startTime;
	int accidents = 0;
	vector<int> accidentsWith;
};

int main()
{
	int n;
	cin >> n;

	int primalAccidentsSum = 0;
	vector<int> accidents;
	vector <delivery> d1, d2;

	int cancelledDeliveries = 0;

	for (int i = 0; i < n; i++) {
		int type, place, startTime;

		cin >> type >> place >> startTime;

		if (type == 1) {
			d1.push_back({ place, startTime });
		}
		else {
			d2.push_back({ place, startTime });
		}
	}


	for (int i = 0; i < d1.size(); i++) {
		for (int j = 0; j < d2.size(); j++) {
			if (d1[i].place + d2[j].startTime == d2[j].place + d1[i].startTime) {
				//cout << "Wypadek! (" << d1[i].place << ", " << d2[j].place << ")" << endl;

				d1[i].accidents++;
				d2[j].accidents++;
				primalAccidentsSum += 2;
			}
		}
	}

	for (int i = 0; i < d1.size(); i++) {
		if (d1[i].accidents > 0) {
			accidents.push_back(d1[i].accidents);
			//cout << d1[i].accidents << endl;
		}
	}

	for (int i = 0; i < d2.size(); i++) {
		if (d2[i].accidents > 0) {
			accidents.push_back(d2[i].accidents);
			//cout << d2[i].accidents << endl;
		}
	}

	sort(accidents.begin(), accidents.end(), greater<int>());
	/*for (int i = 0; i < accidents.size(); i++) {
		cout << "w: " << accidents[i] << endl;
	}*/

	int currentAccidentsSum = primalAccidentsSum;

	while (currentAccidentsSum > (primalAccidentsSum / 2)) {
		//cout << "! " << currentAccidentsSum << endl;
		currentAccidentsSum -= accidents[cancelledDeliveries];
		cancelledDeliveries++;
	}

	cout << cancelledDeliveries;
}