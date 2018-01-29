#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int seeds = 1000;
const int trials = 100000;

void simulate();

void main()
{
	simulate();
}

void simulate()
{
	int inCircle;
	double randX, randY, pi = 0;
	for (int i = 0; i < seeds; i++)
	{
		srand(i + 1);
		for (int i = 0; i < trials; i++)
		{
			randX = (double)rand() / RAND_MAX;
			randY = (double)rand() / RAND_MAX;
			if (((randX * randX) + (randY * randY)) <= 1)
				inCircle++;
		}
		pi = pi + ((double)(4 * inCircle) / trials);
		inCircle = 0;
	}
	pi = pi / seeds;
	cout << "Pi has been approximated to: " << pi << endl;
	system("pause");
}
