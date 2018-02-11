#include <iostream>
#include <cstdlib>
using namespace std;

const int trials = 30000;

int getrandIndex(int);

void main()
{
	int deckSize = 52;
	int deck[52];
	for (int i = 0; i < deckSize; i++)
		deck[i] = i;
	int randIndex, temp, matches, trialMatches;

	for (int i = 0; i < trials; i++)
	{
		for(int j = 0; j < deckSize; j++)
		{
			randIndex = getrandIndex(deckSize);
			
			// Check for match
			if (deck[randIndex] == j) // If 
			{
				temp = deck[deckSize - 1];
				deck[deckSize - 1] = deck[randIndex];
				deck[randIndex] = temp;
				deckSize--;
				matches++;
				break;
			}
		}
	}
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
