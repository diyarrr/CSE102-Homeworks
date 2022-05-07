#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void generate_sequence(int xs, int currentlen, int seqlen, int *seq){
	if(currentlen >= seqlen)
		return;
	else
	{
		/*In case if the first element is even*/
		if(xs % 2 == 0)
		{
			xs /= 2; 
			seq[currentlen] = xs; // The xs will be the next element of the sequence
			generate_sequence(xs, currentlen + 1, seqlen, seq); // Calling the function again so it can look next element
		}
		else
		{
			xs = 3 * xs + 1;
			seq[currentlen] = xs; // The xs will be the next element of the sequence
			generate_sequence(xs, currentlen + 1, seqlen, seq); // Calling the function again so it can look the next element
		}
	}
}/*The end of the generate_sequence*/

void check_loop_iterative(void (*generate_sequence)(int, int, int, int*), int xs, int seqlen, int *loop, int *looplen){
	int ls, le;
	/*Memory allocation for the sequence so I can use in the has_loop too*/
	int *seq = (int *)malloc(seqlen * sizeof(int));
	seq[0] = xs;
	generate_sequence(xs, 1, seqlen, seq);
	if(*looplen == seqlen / 2)
	{
		/*If it reached the sequnce length, then it will print the sequence*/
		printf("\nSequence : {");
		for(int i = 0; i < seqlen; ++i)
		{
			printf("%d", seq[i]);
			if(i != seqlen - 1)
				printf(", ");
		}
		printf("}\n\n");
	}
	/*Searching for a loop*/
	if(*looplen > 1)
	{
		printf("Checking if there is a loop of length %d...\n", *looplen);
		/*In case has_loop return 1, it tells that there is loop in the sequence*/
		if(has_loop(seq, seqlen, *looplen, &ls, &le) == 1)
		{
			printf("\n\nLoop detected with a length of %d\n", *looplen);
			printf("The indexes of the loop's first occurance : %d (first digit), %d (last digit)\n", ls, le);
			/*Assigning the loop numbers to the loop*/
			for(int i = 0; i < *looplen; i++)
				loop[i] = seq[ls + i];
			return;
		}
		else{
			/*Calling the function with the new looplen value*/
			*looplen = *looplen - 1;
			check_loop_iterative(generate_sequence, xs, seqlen, loop, looplen);
		}
	}
	/*If there is no loop then I will assign the looplen to 0*/
	if(*looplen < 2)
		*looplen = 0;

	return;
}/*The end of the check_loop_iterative*/

int has_loop(int *arr, int n, int looplen, int *ls, int *le){
	int count = 0, j;
	/*Starting from the first index, I am checking the if there is loop inside the sequence*/
	for(int i = 0; i < n; i++)
	{
		for(j = i; j < i + looplen; j++)
		{
			/*Comparing the numbers at the given range with the help of looplen*/
			if(arr[j] == arr[j + looplen])
				++count;
		}
		/*If they are the same, it tells that there is a loop in the sequence*/
		if(count == looplen){
			*ls = (j - looplen);
			*le = j;
			return 1;
		}
		count = 0;
	}
	/*In case there is no loop*/
	return 0;
}/*The end of the has_loop*/

void hist_of_firstdigits(void (*f)(int, int, int, int*), int xs, int seqlen, int *h, int digit){
	static int currentlen = 0; // I am using static so that value of currentlen can change for every function calling
	int *seq = (int *)malloc(seqlen * sizeof(int));
	seq[0] = xs;
	generate_sequence(xs, 1, seqlen, seq);
	/*Calculating the first digit of every number*/
	for(int i = 0; i < seqlen; i++)
	{
		while(seq[i] >= 10)
			seq[i] /= 10;
	}
	/* Determining the every histogram for every digit*/
	if(currentlen < 9)
	{
		for(int i = 0; i < seqlen; i++)
		{
			if(seq[i] == digit)
				++h[digit - 1];
		}
		currentlen++;
		hist_of_firstdigits(generate_sequence, xs, seqlen, h, digit+1); // Calling function again with incremented currentlen and digit value
	}
}/*The end of the hist_of_firstdigits*/

