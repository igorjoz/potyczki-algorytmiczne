#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    int* t = new int[n];

    for (int i = 0; i < n; i++) cin >> t[i];

    for (int i = 1; i < n; i++) {
        //cout << "i: " << i << endl;
        for (int j = i / 2; i - j - 1 >= 0; j++) {
            //cout << "j: " << j << "  i-j-1: " << i - j - 1 << "\t\t";
            //cout << t[i] << " " << t[j] << " " << t[i - j - 1] << "\t\t" << (t[i] > t[j] + t[i - j - 1]) << endl;
            if (t[i] > t[j] + t[i - j - 1]) {
                //printf("i: %d j: %d t[i]: %d > t[j]: %d + t[i-j-1]: %d\n", i, j, t[i], t[j], t[i-j-1]);
                //cout << "i: " << i << " j: " << j << " t[i]: " << t[i] << " t[j]: " << t[j] << " t[i-j-1]: " << t[i - j - 1] << endl;
                cout << "NIE" << endl;
                return 0;
            }
        }
        //cout << endl;
    }

    cout << "TAK" << endl << n << endl << t[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << t[i] - t[i - 1];
    }
    cout << endl;
    return 0;
}