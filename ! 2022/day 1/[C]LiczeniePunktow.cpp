#include <iostream>

using namespace std;

int main()
{
    int testsQuantity, groupSize;
    int totalScore = 0;
    string testsResultString;
	bool areGroupTestsPassed = true;
    
	cin >> testsQuantity >> testsResultString;
	groupSize = testsQuantity / 10;

    for (int i = 0; i < testsQuantity; i++) {
        if (testsResultString[i] == 'N') {
            areGroupTestsPassed = false;
        }

		if (((i + 1) % groupSize == 0 and i != 0) or groupSize == 1)
		{
			if (areGroupTestsPassed)
			{
				totalScore++;
			}
            
			areGroupTestsPassed = true;
		}
    }

	cout << totalScore << '\n';

    return 0;
}
