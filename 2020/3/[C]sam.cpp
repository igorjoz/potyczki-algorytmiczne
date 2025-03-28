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

	bool  fine = false; // flaga
	while (!fine) {

		fine = true;
		int maxAccidents = -1;
		int maxAccidentsIndex;
		int maxAccidentsType;

		for (int i = 0; i < d1.size(); i++) {
			for (int j = 0; j < d2.size(); j++) {
				if (d1[i].place + d2[j].startTime == d2[j].place + d1[i].startTime) {
					//cout << "Wypadek! (" << d1[i].place << ", " << d2[j].place << ")" << endl;

					d1[i].accidents++;
					d2[j].accidents++;
					fine = false;

					if (d1[i].accidents > maxAccidents) {
						maxAccidents = d1[i].accidents;
						maxAccidentsIndex = i;
						maxAccidentsType = 1;
					} else if (d2[j].accidents > maxAccidents) {
						maxAccidents = d2[j].accidents;
						maxAccidentsIndex = j;
						maxAccidentsType = 2;
					}
				}
			}
		}

		if (maxAccidents != -1) {
			if (maxAccidentsType == 1) {
				//cout << "Usunieto: " << d1[maxAccidentsIndex].place << " " << d1[maxAccidentsIndex].startTime << endl;
				d1.erase(d1.begin() + maxAccidentsIndex);
			} else {
				//cout << "Usunieto: " << d2[maxAccidentsIndex].place << " " << d2[maxAccidentsIndex].startTime << endl;
				d2.erase(d2.begin() + maxAccidentsIndex);
			}
			cancelledDeliveries++;
		}
	}

	cout << cancelledDeliveries;
}