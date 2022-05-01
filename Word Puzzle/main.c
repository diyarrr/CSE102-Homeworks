#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROW 15
#define MAX_COL 15
#define NUMBER_OF_WORDS 50
#define LEN_OF_WORDS 10
#define N_PICKS 7

void Get_Words(char arr[][LEN_OF_WORDS]);

void Select_7_Words(char arr[][LEN_OF_WORDS], char arr1[][LEN_OF_WORDS]);

void Generate_7_Different_Number(int arr[N_PICKS]);

void Creating_The_Word_Grid(char arr[][MAX_COL], const char arr2[][LEN_OF_WORDS], int coordinates[][2]);

void Fill_Empty_Spaces(char arr[][MAX_COL]);

int Search_Word(char arr[][MAX_COL], char word[5], int index1, int index_2);


int main(){
	srand(time(NULL));
	char file_words[NUMBER_OF_WORDS][LEN_OF_WORDS]; // The words that i am gonna read from the file
	char grid[MAX_ROW][MAX_COL], buffer[20], word[5];
	char selected_words[N_PICKS][LEN_OF_WORDS]; //This array will store the 7 random words that rand function determine
	int first_index, second_index, coordinates[7][2], earn_point = 0, wrong_choice_point = 3, count = 0;
	/*Functions*/
	Get_Words(file_words);
	Select_7_Words(file_words, selected_words);
	Creating_The_Word_Grid(grid, selected_words, coordinates);
	Fill_Empty_Spaces(grid);
	printf("To terminate the game enter :q\n\n");
	
	printf("Selected words and their coordinates \n");
	for(int i = 0; i < N_PICKS; i++)
		printf("%s [%d, %d]\n", selected_words[i], coordinates[i][0], coordinates[i][1]);
	printf("\n");
	do
	{
		for(int i = 0; i < MAX_ROW; i++)
		{
			for(int j = 0; j < MAX_COL; j++)
				printf("%c ", grid[i][j]);
			printf("\n");
		}
		printf("Enter coordinates(x, y) and word(max 5 letters) : ");
		fgets(buffer, 20, stdin);

		sscanf(buffer, "%d %d %s", &first_index, &second_index, word);
		if(strncmp(buffer, ":q", 2) != 0)
		{
			if(Search_Word(grid, word, first_index, second_index) == 1)
			{
				earn_point += 2;
				if(earn_point == 2)
					printf("Founded! You got 2 points. Your total points : %d\n\n", earn_point);
				else
					printf("Founded! Your total points : %d\n\n", earn_point);
				count++;
			}
			else
			{
				wrong_choice_point--;
				if(wrong_choice_point == 0)
					break;
				if(wrong_choice_point == 2)
					printf("Wrong choice! You have only two left. Your total points : %d\n\n", wrong_choice_point);
				else
					printf("Wrong choice! Your total points : %d\n\n", wrong_choice_point);
			}
		}
		if(count == 7)
			break;
	}while(strncmp(buffer, ":q", 2) != 0);
	printf(" !! Game is finished !!\n");
	printf("TOTAL POINT : %d\n", earn_point);
}

/*Getting words from the wordlist.txt file*/
void Get_Words(char arr[][LEN_OF_WORDS]){
	FILE *ptr;
	int i = 0;
	char word[10];
	ptr = fopen("wordlist.txt", "r");
	if(ptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(1);
	}
	else
	{
		/*There are 50 words in the file and i will read every word line by line and copy them into my array*/
		while(fscanf(ptr, "%s", word) == 1 && i < 50)
		{
			strcpy(arr[i], word);
			i++;
		}
	}
	fclose(ptr);
}/*The end of the get_words*/

/*Determine the 7 words randomly*/
void Select_7_Words(char arr[][LEN_OF_WORDS], char selected_words[][LEN_OF_WORDS]){
	int index_array[7], flag, rand_value;
	for(int i = 0; i < N_PICKS; i++)
		index_array[i] = -1;
	for(int i = 0; i < N_PICKS; i++)
	{
		rand_value = rand() % 50;
		for(int j = 0; j  < N_PICKS; j++)
		{
			if(rand_value == index_array[j])
				flag = 1;
		}
		if(flag == 1)
			i--;
		else
		{
			index_array[i] = rand_value;
			strcpy(selected_words[i], arr[index_array[i]]);
		}
		flag = 0;
	}
}/*The end of the select_7_words*/

/*This will placed the words into the grid*/
void Creating_The_Word_Grid(char arr[][MAX_COL], const char words[][LEN_OF_WORDS], int coordinates[][2]){
	int starting_location[2], which_direction, j = 0, len, flag = 0, i;
	/*Initialization of grid with white spaces*/
	for(int i = 0; i < MAX_ROW; i++)
	{
		for(int j = 0; j < MAX_COL; j++)
			arr[i][j] = ' ';
	}
	i = 0;
	while(i < N_PICKS)
	{
		flag = 0;
		len = strlen(words[i]);
		which_direction = (rand() % 8) + 1;
		starting_location[0] = rand() % 15;
		starting_location[1] = rand() % 15;
		//printf("%d %d %d %d %d\n", i, len, which_direction, starting_location[0], starting_location[1]);
		switch(which_direction)
		{
			/*1 -> right to left
	  		  2 -> left to right
	  		  3 -> up to down
	  		  4 -> down to up
	  		  5 -> up to right and down
	  		  6 -> up to left and down
	  	      7 -> down to right and up
	  		  8 -> down to left and up*/	
			case 1:
			{
				if(starting_location[1] + len < 15)
				{
					for(int j = 0; j < len; j++)
					{
						/*Checking if the place that i am looking empty*/
						if(arr[starting_location[0]][starting_location[1] + j] != ' ')
							flag = 1;
						if(flag == 1)
							break;
					}
					/*If it is empty then i can place the letters into the grid*/
					if(flag == 0)
					{
						for(int j = 0; j < len; j++)
							arr[starting_location[0]][starting_location[1] + j] = words[i][j];
						coordinates[i][0] = starting_location[0];
						coordinates[i][1] = starting_location[1];
						i++; // When i find a suitable place for word then i can for second word
					}
				}
			}break;
			case 2:
			{
				if(starting_location[1] - len > 0)
				{
					for(int j = 0; j < len; j++)
					{
						/*Checking if the place that i am looking empty*/
						if(arr[starting_location[0]][starting_location[1] - j] != ' ')
							flag = 1;
						if(flag == 1)
							break;
					}
					/*If it is empty then i can place the letters into the grid*/
					if(flag == 0)
					{
						for(j = 0; j < len; j++)
							arr[starting_location[0]][starting_location[1] - j] = words[i][j];
						coordinates[i][0] = starting_location[0];
						coordinates[i][1] = starting_location[1];
						i++;
					}
				}
			}break;
			case 3:
			{
				if(starting_location[0] + len < 15)
				{
					for(int j = 0; j < len; j++)
					{
						/*Checking if the place that i am looking empty*/
						if(arr[starting_location[0] + j][starting_location[1]] != ' ')
							flag = 1;
						if(flag == 1)
							break;
					}
					/*If it is empty then i can place the letters into the grid*/
					if(flag == 0)
					{
						for(int j = 0; j < len; j++)
							arr[starting_location[0] + j][starting_location[1]] = words[i][j];
						coordinates[i][0] = starting_location[0];
						coordinates[i][1] = starting_location[1];
						i++;
					}

				}
			}break;
			case 4:
			{
				if(starting_location[0] - len > 0)
				{
					for(int j = 0; j < len; j++)
					{
						/*Checking if the place that i am looking empty*/
						if(arr[starting_location[0] - j][starting_location[1]] != ' ')
							flag = 1;
						if(flag == 1)
							break;
					}
					/*If it is empty then i can place the letters into the grid*/
					if(flag == 0)
					{
						for(int j = 0; j < len; j++)
							arr[starting_location[0] - j][starting_location[1]] = words[i][j];
						coordinates[i][0] = starting_location[0];
						coordinates[i][1] = starting_location[1];
						i++;
					}
				}
			}break;
			case 5:
			{
				if(starting_location[0] + len < 15 && starting_location[1] + len < 15)
				{
					for(int j = 0; j < len; j++)
					{
						/*Checking if the place that i am looking empty*/
						if(arr[starting_location[0] + j][starting_location[1] + j] != ' ')
							flag = 1;
						if(flag == 1)
							break;
					}
					/*If it is empty then i can place the letters into the grid*/
					if(flag == 0)
					{
						for(int j = 0; j < len; j++)
							arr[starting_location[0] + j][starting_location[1] + j] = words[i][j];
						coordinates[i][0] = starting_location[0];
						coordinates[i][1] = starting_location[1];
						i++;
					}
				}
			}break;
			case 6:
			{
				if(starting_location[0] + len < 15 && starting_location[1] - len > 0)
				{
					for(int j = 0; j < len; j++)
					{
						/*Checking if the place that i am looking empty*/
						if(arr[starting_location[0] + j][starting_location[1] - j] != ' ')
							flag = 1;
						if(flag == 1)
							break;
					}
					/*If it is empty then i can place the letters into the grid*/
					if(flag == 0)
					{
						for(int j = 0; j < len; j++)
							arr[starting_location[0] + j][starting_location[1] - j] = words[i][j];
						coordinates[i][0] = starting_location[0];
						coordinates[i][1] = starting_location[1];
						i++;
					}
				}
			}break;
			case 7:
			{
				if(starting_location[0] - len > 0 && starting_location[1] + len < 15)
				{
					for(int j = 0; j < len; j++)
					{
						/*Checking if the place that i am looking empty*/
						if(arr[starting_location[0] - j][starting_location[1] + j] != ' ')
							flag = 1;
						if(flag == 1)
							break;
					}
					/*If it is empty then i can place the letters into the grid*/
					if(flag == 0)
					{
						for(int j = 0; j < len; j++)
							arr[starting_location[0] - j][starting_location[1] + j] = words[i][j];
						coordinates[i][0] = starting_location[0];
						coordinates[i][1] = starting_location[1];
						i++;
					}
				}
			}break;
			case 8:
			{
				if(starting_location[0] - len > 0 && starting_location[1] - len > 0)
				{
					for(int j = 0; j < len; j++)
					{
						/*Checking if the place that i am looking empty*/
						if(arr[starting_location[0] - j][starting_location[1] - j] != ' ')
							flag = 1;
						if(flag == 1)
							break;
					}
					/*If it is empty then i can place the letters into the grid*/
					if(flag == 0)
					{
						for(int j = 0; j < len; j++)
							arr[starting_location[0] - j][starting_location[1] - j] = words[i][j];
						coordinates[i][0] = starting_location[0];
						coordinates[i][1] = starting_location[1];
						i++;
					}
				}
			}break;
		}
	    }
}/*The end of the Creating_The_Word_Grid*/

/*It will fill the empty spaces with letters*/
void Fill_Empty_Spaces(char arr[][MAX_COL]){
	char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
	char ch;
	for(int i = 0; i < MAX_ROW; i++)
	{
		for(int j = 0; j < MAX_COL; j++)
		{
			if(arr[i][j] == ' ' || arr[i][j] == '\0')
			{
				ch = (rand() % 26) + 97;
				arr[i][j] = ch; //Assigning a letter with the random ASCII value
			}
		}
	}
}

/*Return 1 if word is found otherwise it returns zero*/
int Search_Word(char arr[][MAX_COL], char word[5], int index1, int index_2){
	char temp[5]; // If i found a correct letter at correct place then i will store that letters in the temp
	int i = 1, len;
	len = strlen(word);
	if(arr[index1][index_2] == word[0])
	{
		temp[0] = word[0];
		while(i < len)
		{
			/* In case conditions are met, then i will replace the letters with 'x'*/
			if(arr[index1][index_2 + i] == word[i])
			{
				temp[i] = word[i];
				arr[index1][index_2 + i] = 'x';
			}
			else if(arr[index1][index_2 - i] == word[i])
			{
				temp[i] = word[i];
				arr[index1][index_2 - i] = 'x';
			}
			else if(arr[index1 + i][index_2] == word[i])
			{
				temp[i] = word[i];
				arr[index1 + i][index_2] = 'x';
			}
			else if(arr[index1 - i][index_2] == word[i])
			{
				temp[i] = word[i];
				arr[index1 - i][index_2] = 'x';
			}
			else if(arr[index1 + i][index_2 + i] == word[i])
			{
				temp[i] = word[i];
				arr[index1 + i][index_2 + i] = 'x';
			}
			else if(arr[index1 + i][index_2 - i] == word[i])
			{
				temp[i] = word[i];
				arr[index1 + i][index_2 - i] = 'x';
			}
			else if(arr[index1 - i][index_2 + i] == word[i])
			{
				temp[i] = word[i];
				arr[index1 - i][index_2 + i] = 'x';
			}
			else if(arr[index1 - i][index_2 - i] == word[i])
			{
				temp[i] = word[i];
				arr[index1 - i][index_2 - i] = 'x';
			}
			i++;
		}
		if(strcmp(temp, word) == 0) // Comparison between stored letters and the word, if they are the then it will return 1
		{
			arr[index1][index_2] = 'x';
			return 1;
		}
		else
			return 0;
	}
	/*If the first letter is not same*/
	else
		return 0;

}/*The end of the Search_Word*/






