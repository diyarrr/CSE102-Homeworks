#include <stdio.h>

void menu();
void write_file(int a, int b, int c);
void draw_graph();
void draw_file();
int point_of_equation(int x, int y, int a, int b, int c);


int main(){
	int which_operation, a, b, c;

	while(which_operation != 4)
	{
		menu();
		scanf("%d", &which_operation);
		if(which_operation > 4 || which_operation < 1)
			printf("Undefined operation.\n");
		else
		{
			if(which_operation == 1)
			{
				/*If user enter one, i will take three values from the user for the equation*/
				printf("Please enter the coefficent for the following equation: x=a*(y*y) + b*y + c\n");
				printf("a: ");
				scanf("%d", &a);
				printf("b: ");
				scanf("%d", &b);
				printf("c: ");
				scanf("%d", &c);
				write_file(a, b, c);
			}
			else if(which_operation == 2)
				draw_graph();// This function will draw a graph on terminal
			else if(which_operation == 3)
				draw_file();// This function will draw a graph in file
		}
	}
	printf("\nExitting.\n");
}

void menu(){
	printf("Select an operation\n"
		"1 -> Enter the coefficents.\n"
		"2 -> Draw the graph.\n"
		"3 -> Print the graph into a .txt file\n"
		"4 -> Exit.\n\n"
		"Choice: ");
}/*The end of the menu*/
/*This function printing the three values into the coefficients.txt file*/
void write_file(int a, int b, int c){
	FILE *ptr;
	ptr = fopen("coefficents.txt", "w");
	fprintf(ptr, "%d\n%d\n%d\n", a, b, c);
	fclose(ptr);
	printf("coefficents.txt file has been created.\n\n");
}/*The end of the write_file*/

int point_of_equation(int x, int y, int a, int b, int c){

	if(x == a*(y*y) + b*y + c) /*If the given equation is equal to x, then it will return 1*/
		return 1;
	else
		return 0;
}/*The end of the point_of_equation*/

void draw_graph(){
	FILE *ptr;
	/*i = y, j = x*/
	int a, b, c, y_axis, x_axis;
	ptr = fopen("coefficents.txt", "r"); 
	/*In case file is not present*/
	if(fscanf(ptr, "%d %d %d", &a, &b, &c) == 0)
		printf("File is not present...");

	else
		fscanf(ptr, "%d %d %d", &a, &b, &c); // i will read three numbers from the file
	fclose(ptr);
	printf("Printing the graph of x = %d * (y * y) + %d * y + %d\n", a, b, c);


	for(y_axis = 16; y_axis >= -15; y_axis--) //y axis will start from the 16 so i can print '^' sign at the top
	{
		for(x_axis = -56; x_axis <= 56; x_axis++) // x axis will be -56 to 56 because it consist of '<' and '>' 
		{
			
			if(x_axis == -1) // i will print the number of y axis on this level
			{
				if(y_axis % 5 == 0 && y_axis != 0) // numbers that divided by 5 will be printed
				{
					if(y_axis >= 10) // since the numbers that equal and bigger than 10 are 2 characters,to locate them i will delete 2 characters
						printf("\b\b");
					else if(y_axis > 0 && y_axis < 10)// for 1 character, i will remove only one.
						printf("\b");
					else if(y_axis <= -10) // for 3 characters, i will remove 3 characters
						printf("\b\b\b");
					else if(y_axis < 0) // for 2 characters, i will remove 2
						printf("\b\b");
					/*Then it will print the number*/
					printf("\033[0;33m");
					printf("%d", y_axis);
					printf("\033[0m");
				}
			}
			else if(y_axis == -1) // i will print the number of x axis on this level
			{
				if(point_of_equation(x_axis, y_axis, a, b, c) == 0) //if it is not a point of equation
				{

					if(x_axis%10 == 0 && y_axis != 0) // numbers that divided by 10 will be printed
					{
						if(x_axis >= 10) // for 2 character, i will remove 2 character
						 	printf("\b\b");
						else if(x_axis <= -10) // for 3 character, i will remove 3 character
							printf("\b\b\b");
						else if(x_axis < 0) // for 2 character, i will remove 2
							printf("\b\b");
						else if(x_axis == 0) // for 0, it is only 1
							printf("\b");
						/*Then it will print the number*/
						printf("\033[0;36m");
						printf("%d", x_axis);
						printf("\033[0m");

					}
				}
			}
			
			if(point_of_equation(x_axis, y_axis, a, b, c) == 1) // if it is a point of equation
			{
				/*To locate '#' sign i will remove 1 character from the right side of the graph*/
				if(x_axis > 0 && y_axis == 0)
					printf("\b");
				printf("\033[0;34m");
				printf("#");
				printf("\033[0m");
			}

			else
			{	

				if(x_axis == 0)
				{
					if(y_axis == 16) 
						printf("^");
					else
						printf("|"); //y_axis will be on x = 0 level with '|' sign 
				}
				else if(y_axis != 0)
				{
					printf(" "); // In case y axis is not zero, it will be space
				}
				if(y_axis == 0)
				{
					if(x_axis == -56)
						printf("<");
					else if(x_axis == 56)
						printf(">");
					else
						printf("-");// x_axis will be on y = 0 level with '-' sign
				}
			}
		}
		printf("\n");
	}
}/*The end of draw_graph*/

void draw_file(){
	FILE *ptr, *p;
	int a, b, c, y_axis, x_axis;
	p = fopen("coefficents.txt", "r");
	/*In case file is not present*/
	if(fscanf(p, "%d %d %d", &a, &b, &c) == 0)
		printf("File is not present...\n");
	else
		fscanf(p, "%d %d %d", &a, &b, &c);
	fclose(p);
	printf("\nCoefficients has been read from the coefficents file.\n");

	ptr = fopen("graph.txt", "w");

	for(y_axis = 16; y_axis >= -15; y_axis--)//y axis will start from the 16 so i can print '^' sign at the top
	{
		for(x_axis = -56; x_axis <= 56; x_axis++)// x axis will be -56 to 56 because it consist of '<' and '>' 
		{
			if(point_of_equation(x_axis, y_axis, a, b, c) == 1 )// if it is a point of equation
			{
				fprintf(ptr, "#");
			}
			else
			{
				if(x_axis == 0)
				{
					if(y_axis == 16)
						fprintf(ptr, "^");
					else
						fprintf(ptr, "|");//y_axis will be on x = 0 level with '|' sign
				}
				else if(y_axis != 0)
					fprintf(ptr, " ");// In case y axis is not zero, it will be space
				if(y_axis == 0)
				{
					if(x_axis == -56)
						fprintf(ptr, "<");
					else if(x_axis == 56)
						fprintf(ptr, ">");
					else
					{
						if(x_axis != 0 && point_of_equation(x_axis, y_axis, a, b, c) == 0)
							fprintf(ptr, "-"); // x_axis will be on y = 0 level with '-' sign	
					}
				}
			}
		}
		fprintf(ptr, "\n");
	}
	fclose(ptr);
	printf("The graph of x= %d*(y*y) + %d*y + %d has been written to graph.txt file.\n\n", a, b, c);
}/*The end of draw_file*/

