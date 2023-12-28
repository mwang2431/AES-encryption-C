#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generate_key.h"

////////////////////////////////////////////////
// Generate random characters
// ptr: 	contains random characters
// size: 	number of characters in ptr
////////////////////////////////////////////////

void generate_random_chars(unsigned char *ptr, int size)
{
	int		i;

	// Initialize random number generator
	srand((unsigned) time(NULL));

	// generate random characters and store in ptr
	for (i = 0; i < size; i++)
	{
		ptr[i] = rand() % 256;
	}
}
