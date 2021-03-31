#include <iostream>

using namespace std;

struct colors {
    bool yellow = false;
    bool blue = false;
    bool red = false;
};

int main()
{
    int cansQuantity;
    int n;

    int greenCounter = 0;

    cin >> cansQuantity;
    colors* c = new colors[cansQuantity];

    cin >> n;

    for (int i = 0; i < n; i++) {
        int from, to, color;
        cin >> from >> to >> color;

        if (color == 1) {
            for (int j = from - 1; j < to; j++) {
                c[j].yellow = true;
            }
        } else if (color == 2) {
            for (int j = from - 1; j < to; j++) {
                c[j].blue = true;
            }
        } else {
            for (int j = from - 1; j < to; j++) {
                c[j].red = true;
            }
        }
    }

    for (int i = 0; i < cansQuantity; i++) {
        if (c[i].yellow && c[i].blue && !(c[i].red)) {
            greenCounter++;
        }
    }

    cout << greenCounter << "\n";
}