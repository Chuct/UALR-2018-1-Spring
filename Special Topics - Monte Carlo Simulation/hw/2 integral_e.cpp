#include <iostream>
#include <cstdlib>
using namespace std;

const int trials = 30000;
const double error = 0.000001;

void simulate();
double generateRandomX(double x);
double generateRandomY();
bool underCurve(double x, double y);

void main()
{
	simulate();
	system("pause");
}
void simulate()
{
	int count;
	double randX, randY, hitPercent, area;
	double leftEnd = 2, rightEnd = 4, mid;

	// Perform until sandwhich is < error
	while (rightEnd - leftEnd >= error)
	{
		// Initialize count & mid for upcoming trials
		count = 0;
		mid = (leftEnd + rightEnd) / 2;

		// Perform Trials
		for (int i = 0; i < trials; i++)
		{
			randX = generateRandomX(mid);
			randY = generateRandomY();
			if (underCurve(randX, randY))
				count++;
		}

		// Calcualte Area
		hitPercent = (double)count / trials;
		area = hitPercent * (mid - 1); // (mid - 1) = width of box above the curve

		// Adjust for next set
		if (area < 1)
			leftEnd = mid; // Area < 1 -> Bisect higher
		else
			rightEnd = mid; // Area > 1 -> Bisect lower
	}

	// Report
	cout.precision(15);
	cout << "The constant e has been approximated to be between: " << endl;
	cout << "Left End: " << leftEnd << endl;
	cout << "Right End: " << rightEnd << endl;
}
double generateRandomX(double x)
{
	// Generates and returns a random value, of type double, between 1 and x
	return (((double)rand() / RAND_MAX) * (x - 1)) + 1;
}
double generateRandomY()
{
	// Generates and returns a random value, of type double, between 0 & 1
	return (double)rand() / RAND_MAX;
}
bool underCurve(double x, double y)
{
	return y <= (1 / x);
}
