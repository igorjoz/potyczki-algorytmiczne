#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned short int n;
unsigned long long int possibleCombinations = 0;

void check(unsigned short int packages[], unsigned short int index, unsigned long long int sum) {
    while (true) {
        if (index < n && packages[index] <= sum + 1) {

            if (index + 1 < n && packages[index + 1] <= sum + 1) {
                //cout << "rekurencja!" << endl << endl;
                check(packages, index + 1, sum);
            }

            sum += packages[index];
            possibleCombinations = (possibleCombinations + 1) % 1000000007;
            index++;

            //cout << "Suma po: " << sum << endl;
            //cout << "Kombinacje po: " << possibleCombinations << endl;
            //cout << "Index po: " << index << endl << endl;
        }
        else {
            //cout << "koniec tego!" << index << endl << endl;
            break;
        }
    }
}


int main()
{
    cin >> n;
    unsigned short int* packages = new unsigned short int[n];

    for (int i = 0; i < n; i++) {
        cin >> packages[i];
    }

    sort(packages, packages + n);

    if (packages[0] == 1) {
        check(packages, 0, 0);

        cout << possibleCombinations;
    }
    else {
        cout << 0;
    }
}