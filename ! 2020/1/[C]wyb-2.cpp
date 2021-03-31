#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n < 18) {
        cout << "NIE";
    }
    else {
        bool A[4]{}, B[4]{}, C[4]{};
        int A5 = 0, B5 = 0, C5 = 0;

        for (int i = 0; i < n; i++) {
            string set;
            cin >> set;

            int number = set[0] - '0';

            if (number != 5) {
                if (set[1] == 'A') A[number - 1] = true;
                else if (set[1] == 'B') B[number - 1] = true;
                else C[number - 1] = true;
            }
            else {
                if (set[1] == 'A') A5++;
                else if (set[1] == 'B') B5++;
                else C5++;
            }
        }

        bool allTasks = true; // flaga

        if (A5 < 2 || B5 < 2 || C5 < 2) {
            allTasks = false;
        }
        else {
            for (int i = 0; i < 4; i++) {
                if (!(A[i]) || !(B[i]) || !(C[i])) {
                    allTasks = false;
                }
            }
        }

        if (allTasks) {
            cout << "TAK";
        }
        else {
            cout << "NIE";
        }
    }
}