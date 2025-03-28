#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, length;
    string str;
    string outputString = "";

    cin >> n >> str;
    length = str.length();

    int zerosQuantity = 0, onesQuantity = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == '0') {
            zerosQuantity++;
        }
    }
    onesQuantity = length - zerosQuantity;
    //cerr << "zeros: " << zerosQuantity << "\n" << "ones: " << onesQuantity << "\n";

    if (onesQuantity < n * 3 or zerosQuantity < n * 2) {
        outputString = "NIE";
    }
    else {
        while (onesQuantity > 0 or zerosQuantity > 0) {
            if (onesQuantity >= 2 * zerosQuantity) {
                onesQuantity -= 6;
                zerosQuantity -= 2;
                outputString += "o";
            }
            else if (onesQuantity % 3 == 0 and zerosQuantity % 5 == 0 and onesQuantity / 3 == zerosQuantity / 5) {
                onesQuantity -= 3;
                zerosQuantity -= 5;
                outputString += "a";
            }
            else if (onesQuantity % 5 == 0 and zerosQuantity % 3 == 0 and onesQuantity / 5 == zerosQuantity / 3) {
                onesQuantity -= 5;
                zerosQuantity -= 3;
                outputString += "n";
            }
            else {
                onesQuantity -= 4;
                zerosQuantity -= 4;
                outputString += "c";
            }
            //cerr << "zeros: " << zerosQuantity << "\t" << "ones: " << onesQuantity << "\t" << outputString << "\n";
        }
    }

    cout << outputString << "\n";

    return 0;
}

// 'o' -> 2x 0, 6x 1
// 'n' -> 3x 0, 5x 1
// 'c' -> 4x 0, 4x 1
// 'a' -> 5x 0, 3x 1
