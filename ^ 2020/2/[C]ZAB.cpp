#include <iostream>

using namespace std;

int main() {
    int toys;
	string s1, s2;
    cin >> toys >> s1 >> s2;

    for (int i = 0; i < toys; i++) {

        bool isFine = false; // flag

        if (s1[i] == s2[i]) {
            isFine = true;
        }
		else {

            for (int j = i + 2; j < toys; j += 2) {
                if (s2[i] == s1[j]) {
                    //cout << "Da się: " << s1[i] << "[" << i << "]" << ", " << s1[j] << "[" << j << "]" << endl;

                    int requiredSwaps = (j - i) / 2;

                    //cout << "Przed: " << s1 << "  ----  ";
                    for (int k = 0; k < requiredSwaps; k++) {
                        char temp = s1[i + k];
                        s1[i + k] = s1[j - k];
                        s1[j - k] = temp;
                    }
                    //cout << "Po: " << s1 << endl;

                    isFine = true;

                    break;
                }

            }
        }  

        if (!isFine) {
            cout << "NIE";
            exit(0);
        }
    }

    cout << "TAK";
}