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
        bool A[4];
        bool B[4];
        bool C[4];

        for (int i = 0; i < 4; i++) {
            A[i] = false;
            B[i] = false;
            C[i] = false;
        }

        int A5Counter = 0;
        int B5Counter = 0;
        int C5Counter = 0;

        for (int i = 0; i < n; i++) {
            string set;
            cin >> set;

            int number = set[0] - '0';

            if (set[1] == 'A' && number != 5) {
                A[number - 1] = true;
            } else if (set[1] == 'B' && number != 5) {
                B[number - 1] = true;
            } else if (set[1] == 'C' && number != 5) {
                C[number - 1] = true;
            } else if (set[1] == 'A' && number == 5) {
                A5Counter++;
            } else if (set[1] == 'B' && number == 5) {
                B5Counter++;
            } else if (set[1] == 'C' && number == 5) {
                C5Counter++;
            }
        }

        bool allTasks = true; // flaga

        if (A5Counter < 2 || B5Counter < 2 || C5Counter < 2) {
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