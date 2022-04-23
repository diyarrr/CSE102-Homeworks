#include <stdio.h>
#include <math.h>

/*Utility functions*/
void menu(); /*This will show the menu*/
int sum(int n1, int n2, int flag);
int multi(int n1, int n2, int flag);
int isprime(int a);
void write_file(int number);
void sort_file();
void print_file();
/*These functions will write the numbers that we found to the temporary.txt file*/
void write_temporary_file(int a);
int write_three_numbers_temporary_file(int a); 
void temporary_to_result(); /*This will copy the temporary.txt to result.txt*/

int main(){
	int i, which_operation, sum_or_multi, n1, n2, flag, prime_or_not;
	do{
		menu();
		scanf("%d", &which_operation);
	
		switch(which_operation)
		{
			case 1:
			{
				printf("Please enter '0' for sum, '1' for multiplication\n");
				scanf("%d", &sum_or_multi);
				printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n");
				scanf("%d", &flag);
				/*Flag must be either 0 or 1 */
				if(sum_or_multi >= 0 && sum_or_multi <= 1 && flag >= 0 && flag <= 1) 
				{
					printf("Please enter two different number:\n");
					printf("Number 1 : ");
					scanf("%d", &n1);
					printf("Number 2 : ");
					scanf("%d", &n2);
					/*In case user give negative number*/
					if(n1 < 0 || n2 < 0)
						printf("Please enter only positive number.\n");
					else
					{	
						/*This statement is for sum*/
						if(sum_or_multi == 0)
						{
							printf("Result \n");
							write_file(sum(n1, n2, flag));
			    		}
			    		/*This is for multiplication*/
			    		else
			    		{
			    			printf("Result \n");
			    			write_file(multi(n1, n2, flag));
			    		}
					}
				}
				/*In case flags are not 0 or 1*/
				else
					printf("Use just 0 or 1 for flags.\n");
			} break;
			case 2:
			{

				printf("Please enter an integer : ");
				scanf("%d", &prime_or_not);
				for(i = 2;i < prime_or_not; i++)
				{
					/*In case number is prime ,function will return 1*/
					if(isprime(i) == 1)
						printf("%d is a prime number.\n", i);
					/*If it is not prime, it will return 0*/
					else
						printf("%d is not a prime number.It is dividible by %d\n", i, isprime(i));
				}

			} break;

			case 3:
			{
				printf("Result: \n");
				/*This will show the numbers that file contains*/
				print_file();
				printf("\n");
			}break;
			case 4:
			{
				/*This will sort the numbers 3 by 3 and it will store the numbers in temporary.txt*/
				sort_file();
				printf("\n");
			}break;
			case 0:
				printf("Exitting...\n");break;
			default:
				printf("Undefined operation.\n");
		
		}
	}while(which_operation != 0);
}

void menu(){
	printf("\nSelect operation\n"
		"1. Calculate sum / multiplication between two numbers\n"
		"2. Calculate prime numbers\n"
		"3. Show number sequence in file\n"
		"4. Sort number sequence in file\n"
		"For exit, press 0\n"
		"----------------------------------------------------\n");
}/*The end of the menu*/

int sum(int n1, int n2, int flag){
	int i, sum, temp;
	sum = 0;
	/*If the first number is bigger than second number then they will be swapped. */
	if(n1 > n2)
	{
		temp = n2;
		n2 = n1;
		n1 = temp;
	}
	/*This will give the summation of numbers between n1 and n2*/
	for(i = n1;i<n2;i++){
		if(flag == 0)
		{
			if(i%2 == 0)
			{
				printf("%d", i);
				if(n2%2 == 0)
				{
					if(i < n2 - 2)
						printf(" + ");
					else
						printf(" = ");
				}
				else
				{
					if(i < n2 - 1)
						printf(" + ");
					else
						printf(" = ");
				}
				sum+= i;
			}
		}
		else
		{
			if(i%2 != 0)
			{
				printf("%d", i);
				if(n2%2 == 0)
				{
					if(i < n2 - 1)
						printf(" + ");
					else
						printf(" = ");
				}
				else
				{
					if(i < n2 - 2)
						printf(" + ");
					else
						printf(" = ");
				}
				sum+= i;
			}
		}
	}
	printf("%d", sum);
	return sum;
}/*The end of the sum*/

int multi(int n1, int n2, int flag){
	int i, multi_result, temp;
	multi_result = 1;
	if(n1 > n2)
	{
		temp = n2;
		n1 = n2;
		n1 = temp;
	}
	for(i = n1;i <n2; i++)
	{
		if(flag == 0)
		{
			if(i%2 == 0)
			{
				printf("%d", i);
				if(n2%2 == 0)
				{
					if(i < n2 - 2)
						printf(" * ");
					else
						printf(" = ");
				}
				else
				{
					if(i < n2 - 1)
						printf(" * ");
					else
						printf(" = ");
				}

				multi_result*=i;
			}
		}
		else
		{
			if(i%2 != 0)
			{
				printf("%d", i);
				if(n2%2 == 0)
				{
					if(i < n2 - 1)
						printf(" * ");
					else
						printf(" = ");
				}
				else
				{
					if(i < n2 - 2)
						printf(" * ");
					else
						printf(" = ");
				}
				multi_result*=i;
			}
		}
	}
	printf("%d", multi_result);
	return multi_result;
}/*The end of the multi*/

int isprime(int a){
	int i, least_divisor, flag;
	/*I will check 2 and 3 by with this because sqrt of them are not bigger or equal to 2*/
	if(a == 2 || a == 3)
	{
		flag = 1;
	}

	for(i = 2;i <= sqrt(a); i++)
	{
		/*If a has a divisor then it is not a prime number */
		if(a%i == 0)
		{
			least_divisor = i;
			flag = 0;
			break;	
		}
		else
			flag = 1;
	}
	if(flag == 1)
		return 1;
	else
		return least_divisor;
}/*The end of the isprime*/

void write_file(int number){
	FILE *ptr;
	ptr = fopen("result.txt", "aw");
	fprintf(ptr, "%d ", number);
	fclose(ptr);
	printf("\nThe result is written to the result.txt file\n");
}/*The end of the write_file*/

void print_file(){
	FILE *ptr;
	int num;
	ptr = fopen("result.txt", "r");
	while(fscanf(ptr, "%d ", &num) == 1)
	{
		printf("%d ", num);
	}
	fclose(ptr);
}/*The end of the print_file*/

void write_temporary_file(int a){
	/*It will write integers one by one to the temporary.txt*/
	FILE *p;
	p = fopen("temporary.txt", "aw");
	fprintf(p, "%d ", a);
	fclose(p);
}/*The end of the write_temporary_file*/

/*After determining the first 3 min numbers i will call this function, it will determine the other three mins*/
int write_three_numbers_temporary_file(int a){
	FILE *ptr;
	int i, number_from_file, min1, min2, min3, max_int;
	min1 = min2 = min3 = max_int = 2147483647;  //INT_MAX

	for(i = 0;i < 3; i++)
	{
		/*File will open and close at every for loop cycle because i need to get numbers from the beginning*/
		ptr = fopen("result.txt","r");
		if(i == 0)
		{
			while(fscanf(ptr, "%d ", &number_from_file) == 1)
			{
				if(number_from_file > a && min1 > number_from_file)
					min1 = number_from_file;
			}
		}
		else if(i == 1)
		{
			while(fscanf(ptr, "%d ", &number_from_file) ==1)
			{
				if(number_from_file > min1 && min2 > number_from_file)
					min2 = number_from_file;
			}
		}
		else
		{
			while(fscanf(ptr, "%d ", &number_from_file) == 1)
			{
				if(number_from_file > min2 && number_from_file > min1 && min3 > number_from_file)
					min3 = number_from_file;
			}
		}

		fclose(ptr);
	}
	if(min1 < max_int)
			write_temporary_file(min1);
	if(min2 < max_int)
			write_temporary_file(min2);
	if (min3 < max_int)
			write_temporary_file(min3);
	return min3;

}/*The end of the write_three_numbers_temporary_file*/

void temporary_to_result(){
	/*This will take the integers from temporary.txt and print to result.txt at last*/
	FILE *temp_ptr, *result_ptr;
	int number;
	temp_ptr = fopen("temporary.txt", "r");
	result_ptr = fopen("result.txt", "w");
	while(fscanf(temp_ptr, "%d ", &number) == 1)
	{
		fprintf(result_ptr, "%d ", number);

	}
	fclose(temp_ptr);
	fclose(result_ptr);
}/*The end of the temporary_to_result*/

void sort_file(){
	FILE *ptr;
	int i, j, counter, min1, min2, min3, number_from_file, max_int, number_of_loop, temp_min3;
	min1 = min2 = min3 = max_int =2147483647;  //This is the INT_MAX
	counter = 0;
	ptr = fopen("result.txt", "r");
	/*It will count the number of integers in the result.txt file*/
	while(fscanf(ptr, "%d ", &number_from_file) == 1)
		counter++;
	fclose(ptr);

	/*To find first 3 min numbers i use this for loop*/
	for(i = 0;i < 3; i++)
	{
		ptr = fopen("result.txt", "r");
		if(i == 0)
		{
			while(fscanf(ptr, "%d ", &number_from_file) == 1)
			{
				if(min1 > number_from_file)
					min1 = number_from_file;
			}
		}	
		else if(i == 1)
		{
			while(fscanf(ptr, "%d ", &number_from_file) == 1)
			{
				if(number_from_file > min1 && min2 > number_from_file)
					min2 = number_from_file;
			}		
		}
		else
		{
			while(fscanf(ptr, "%d ", &number_from_file) == 1)
			{
				if(number_from_file > min2 && number_from_file > min1 && min3 > number_from_file)
					min3 = number_from_file;
			}	
		}
		fclose(ptr);	
	}
	/*If min1, min2, min3 is same with or bigger than max_int they will not be written to the file*/
	if(min1 < max_int)
			write_temporary_file(min1);
	if(min2 < max_int)
			write_temporary_file(min2);
	if (min3 < max_int)
			write_temporary_file(min3);

	temp_min3 = min3; // The reason i do this it is because the numbers that come after first three number must be bigger than first min3
	number_of_loop = counter / 3; //For loop will stop when it gets this number  
	for(i = 0; i < number_of_loop; i++)
	{
		/*The function will take temp_min3 as a parameter ,so it can compare the numbers with temp_min3 */
		temp_min3 = write_three_numbers_temporary_file(temp_min3);
	}
	temporary_to_result();
	printf("Sorting is complete.\n");
	printf("Result:\n");
	print_file();
}/*The end of the sort_file*/





