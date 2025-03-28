#include <iostream>

using namespace std;

// input
int cansQuantity;
int n; // actions quantity

// answer
int greenCounter = 0;

struct colors {
    bool yellow = false;
    bool blue = false;
    bool red = false;
};

int main()
{
    cin >> cansQuantity;
    colors* c = new colors[cansQuantity];

    cin >> n;

    for (int i = 0; i < n; i++) {
        int from, to, color;
        cin >> from >> to >> color;

        for (int j = from - 1; j < to; j++) {
            if (color == 1) {
                c[j].yellow = true;
            } else if (color == 2) {
                c[j].blue = true;
            } else if (color == 3) {
                c[j].red = true;
            }
        }
    }

    for (int i = 0; i < cansQuantity; i++) {
        if (c[i].yellow && c[i].blue && !(c[i].red)) {
            greenCounter++;
        }
    }

    cout << greenCounter;
}