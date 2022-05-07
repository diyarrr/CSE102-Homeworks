#include <stdio.h>
#include <stdlib.h>
#include "util.h"

#define NUM_OF_DIGIT 9

int main(){
	int first_element, len_of_sequence, looplen, *loop;
	/*Getting the sequence length and first element*/
	printf("Please enter the sequence length : ");
	scanf("%d", &len_of_sequence);
	printf("Please enter the first element : ");
	scanf("%d", &first_element);
	looplen = len_of_sequence / 2;

	/*Memory allocation for histogram array*/
	int *histogram = (int *)calloc(NUM_OF_DIGIT, sizeof(int));

	/*Calling the utility functions*/
	check_loop_iterative(generate_sequence, first_element, len_of_sequence, loop, &looplen);
	hist_of_firstdigits(generate_sequence, first_element, len_of_sequence, histogram, 1);

	/*Printing the loop*/
	if(looplen == 0)
		printf("No loop found.\n\n");
	else
	{
		/*Loop will be printed until it reach the looplen*/
		printf("Loop: {");
		for(int i = 0; i < looplen; i++){
			printf("%d", loop[i]);
			if(i != looplen - 1)
				printf(", ");
		}
		printf("}\n\n");
	}

	/*Printing the histogram values*/
	printf("Histogram of the sequence : {");
	for(int i = 0; i < NUM_OF_DIGIT; i++)
	{
		printf("%d", histogram[i]);
		if(i != 8)
			printf(", ");
	}
	printf("}\n");
}/*The end of the main*/

