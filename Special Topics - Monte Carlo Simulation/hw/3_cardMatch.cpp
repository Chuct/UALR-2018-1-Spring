#include <iostream>
#include <cstdlib>
using namespace std;

const int trials = 100000;

int getrandIndex(int);

void main()
{
	int deckSize = 52;
	int deck[52];
	for (int i = 0; i < deckSize; i++)
		deck[i] = i;
	int randIndex, temp, trialMatches = 0;

	for (int i = 0; i < trials; i++)
	{
		int deckOnePick = 0, matches = 0;
		deckSize = 52;
		while (deckSize > 0)
		{
			randIndex = getrandIndex(deckSize);
			
			// Check for match
			if (deck[randIndex] == deckOnePick) // If 
				matches++;
			temp = deck[randIndex];
			deck[randIndex] = deck[deckSize - 1];
			deck[deckSize - 1] = temp;
			deckSize--;
			deckOnePick++;
		}
		if (matches >= 1)
			trialMatches++;
	}
	cout << (double)trialMatches / trials;
}

int getrandIndex(int deckSize)
{
	// Returns a random number between 0 & (deckSize - 1), accounting for modulo bias
	int randIndex;
	do {
		randIndex = rand();
	} while (randIndex >= (RAND_MAX - (RAND_MAX % deckSize)));
	return randIndex % deckSize;
}
