#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int toys;
    string s1, s2;
    cin >> toys >> s1 >> s2;

    for (int i = 0; i < toys; i++) {

        bool isFine = false; // flaga

        if (s1[i] == s2[i]) {
            isFine = true;
        }
        else {
            for (int j = i + 2; j < toys; j += 2) {
                if (s2[i] == s1[j]) {
                    //cout << "Da sie: " << s1[i] << "[" << i << "]" << ", " << s1[j] << "[" << j << "]" << "\t" << "Przed: " << s1 << endl;
                    int requiredSwaps = (j - i) / 2;

                    for (int k = 0; k < requiredSwaps; k++) {
                        char temp = s1[i + k];
                        s1[i + k] = s1[j - k];
                        s1[j - k] = temp;
                    }

                    isFine = true;
                    break;
                }

            }
        }

        if (!isFine) {
            cout << "NIE\n";
            return 0;
        }
    }

    cout << "TAK\n";
    return 0;
}