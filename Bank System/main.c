#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Person
{
	char name[50], address[50], surname[50];
	int phone, customer_id;
};

union Loan
{
	float amount;
	float interestRate;
	int period;
};

typedef struct
{
	union Person Customer;
	union Loan Loans[3];
}BankAccount;

/*Utility functions*/
void menu();

void listCustomers();

int addCustomer();

void newLoan();

float calculateLoan(float amount, int period, float interestRate);

void getReport(int *d);

void Month_Installment(float loan, int period);


int main(){
	/*Checking if there is any file to read*/
	FILE *customer_ptr;
	char buffer[100];
	int file_id_arr[50], count = 0, max = 0;

	if(customer_ptr = fopen("customer.txt", "r"))
	{
		while(fgets(buffer, 100, customer_ptr))
		{
			sscanf(buffer, "%d %s", &file_id_arr[count], buffer);
			count++;
		}
		fclose(customer_ptr);
	}
	/*Finding the maximum ID in the file*/
	for(int i = 0; i < count; i++)
	{
		if(max < file_id_arr[i])
			max = file_id_arr[i];
	}
	max++;

	BankAccount account[50];
	int number_of_accounts = -1;

	int which_option;
	do
	{
		menu();
		scanf("%d", &which_option);
		if(which_option == 1)
			listCustomers(&account, &number_of_accounts);
		else if(which_option == 2)
		{
			if(addCustomer(&number_of_accounts, &account, &max) == 1)
				printf("\nCustomer is added successfully.\n");
			else
				printf("\nFailed while adding the new customer.\n");
		}
		else if(which_option == 3)
		{
			newLoan();
		}
		else if(which_option == 4)
			getReport(&max);
		else if(which_option > 5 || which_option < 0)
			printf("\nWrong operation. Please try again.\n\n");

	}while(which_option != 5);


}

/*Printing the menu when it is called in the main*/
void menu(){
	printf("==============================================\n"
		"Welcome to the Bank Management System\n"
		"==============================================\n"
		"	1. List All Customers\n"
		"	2. Add New Customer\n"
		"	3. New Loan Application\n"
		"	4. Report Menu\n"
		"	5. Exit System\n"
		"Option : ");
}/*The end of the menu*/

/*List the customers with structs*/
void listCustomers(BankAccount * account, int * number_of_accounts)
{
	int i;
	for(i = 0; i <= *number_of_accounts; i++)
		printf("Customer Name = %s\n", account[i].Customer.name);
	printf("\n");
	return;
}/*The end of the listCustomers*/

/*Add the customer file and also into the struct*/
int addCustomer(int * number_of_accounts, BankAccount * account, int * id)
{
	
	FILE *customer_ptr, *loan_ptr;
	char temp_name[50];
	customer_ptr = fopen("customer.txt", "aw");
	loan_ptr = fopen("loan.txt", "aw");
	(*number_of_accounts)++;
	if(*id > 50)
		printf("\nYou can not enter more than 50 account to the bank system\n");
	else
	{
		/*Incrementing the ID number for every account*/
		fprintf(customer_ptr, "%d ", *id);
		fprintf(loan_ptr, "%d %d\n", *id, 0);

		/*Getting the information for struct and also to write into the file*/
		printf("Customer Name = ");
		getchar();
		scanf("%[^\n]", account[*number_of_accounts].Customer.name);
		fprintf(customer_ptr, "%s ", account[*number_of_accounts].Customer.name);
		strcpy(temp_name, account[*number_of_accounts].Customer.name);

		printf("Customer Phone = ");
		scanf("%d", &account[*number_of_accounts].Customer.phone);
		fprintf(customer_ptr, "%d ", account[*number_of_accounts].Customer.phone);

		printf("Customer Address = ");
		getchar();
		scanf("%[^\n]", account[*number_of_accounts].Customer.address);
		fprintf(customer_ptr, "%s\n", account[*number_of_accounts].Customer.address);

		fclose(customer_ptr);
		fclose(loan_ptr);
		strcpy(account[*number_of_accounts].Customer.name, temp_name);
		(*id)++;
		return 1;
	}
}/*The end of the addCustomer*/

void newLoan()
{
	FILE *ptr;
	BankAccount account;
	float cal_loan;
	int id;
	/*Getting information for loans from the user*/
	printf("Enter the ID of the customer that will take the loan : ");
	scanf("%d", &id);
	printf("Enter the amount of loan : ");
	scanf("%f", &account.Loans[0].amount);
	printf("Enter the period : ");
	scanf("%d", &account.Loans[1].period);
	printf("Enter the Interest rate :"),
	scanf("%f", &account.Loans[2].interestRate);

	/*Calculating the loan*/
	cal_loan = calculateLoan(account.Loans[0].amount, account.Loans[1].period, account.Loans[2].interestRate);
	char buffer[50];
	int value, count = 0, i = 0, temp_count, index;
	int period_1, period_2, period_3;
	float loan1, loan2, loan3;
	ptr = fopen("loan.txt", "r");
	char temp[50][50];
	/*Reading the id and number of loans taken from the file and copy to the temp */
	while(fgets(buffer, 50, ptr))
	{
		strcpy(temp[count], buffer);
		count++;
	}
	fclose(ptr);
	/*Take the values from the temp and assign with integer values so I can compare them*/
	ptr = fopen("loan.txt", "w");
	while(i < count)
	{

		sscanf(temp[i], "%d %d %s", &value, &temp_count, buffer);
		if(value == id && temp_count == 3)
		{
			printf("\nSorry but no more loans for this id\n");
			fprintf(ptr, "%s", temp[i]);
		}
		/*If value is not matched with id buffer will copy the new file*/
		else if(value != id)
			fprintf(ptr, "%s", temp[i]);
		/*If value is matched, I will take the index of it*/
		else
			index = i;

		i++;
	}
	sscanf(temp[index], "%d %d %s", &value, &temp_count, buffer);
	
	if(temp_count < 3)
	{
		switch(temp_count)
		{
			case 0:
			{
				fprintf(ptr, "%d %d %.2f %d\n", value, temp_count + 1, cal_loan + account.Loans[0].amount, account.Loans[1].period);
				printf("\nLoan added on your account successfully!!\n");
			}break;
			case 1:
			{
				sscanf(temp[index], "%d %d %f %d", &value, &temp_count, &loan1, &period_1);
				fprintf(ptr, "%d %d %.2f %d %.2f %d\n", value, temp_count + 1, loan1, period_1, cal_loan + account.Loans[0].amount, account.Loans[1].period);
				printf("\nLoan added on your account successfully!!\n");
			}break;
			case 2:
			{
				sscanf(temp[index], "%d %d %f %d %f %d", &value, &temp_count, &loan1, &period_1, &loan2, &period_2);
				fprintf(ptr, "%d %d %.2f %d %.2f %d %.2f %d\n", value, temp_count + 1, loan1, period_1, loan2, period_2, cal_loan + account.Loans[0].amount, account.Loans[1].period);
				printf("\nLoan added on your account successfully!!\n");
			}break;
		}
	}
	fclose(ptr);
	
}/*the end of the newLoan*/

/*Calculating and printing the loan*/
float calculateLoan(float amount, int period, float interestRate)
{
	if(period > 0)
	{
		amount *= (1 + interestRate);
		calculateLoan(amount, period - 1, interestRate);
	}
	else
		return amount;

}/*The end of the calculateLoan*/

/*Reading the informations from the customer.txt file*/
void getReport(int * max)
{
	/*To get the information, I will use a single string for fgets*/
	char buffer[100], lines[*max][100];
	char name[50], address[50], surname[50], temp[50];
	int id, phone, count, value, which_credit, option, new_value, i = 0;
	int period_1, period_2, period_3;
	float loan1, loan2, loan3;

	FILE *ptr, *loan_ptr;

	printf("For all customer information press 1\n"
		"For specific credit and month installment press 2\n");
	scanf("%d", &option);

	loan_ptr = fopen("loan.txt", "r");
	/* To print correct id, i will take the lines from the loan.txt with indexes*/
	while(fgets(buffer, 100, loan_ptr))
	{
		strcpy(lines[i], buffer);
		i++;
	}
	fclose(loan_ptr);

	/* Printing the all information of customers*/
	if(option == 1)
	{
		ptr = fopen("customer.txt", "r");
		loan_ptr = fopen("loan.txt", "r");
		while(fgets(buffer, 100, ptr))
		{
			/*The line that I read from the file*/
			sscanf(buffer, "%d %s %s %d %[^\t\n]", &id, name, surname, &phone, address);
			printf("\nCustomer ID = %d\n", id);
			printf("Customer Name = %s %s\n", name, surname);
			printf("Customer Phone = %d\n", phone);
			printf("Customer Address = %s\n", address);
			/*Printing the all loan details with loan.txt*/
			for(int i = 0; i < *max - 1; i++)
			{
				sscanf(lines[i], "%d %d %s", &value, &count, temp);
				//printf("%s\n", buffer);
				/*If the given id is matched with the file id*/
				if(value == id)
				{
					switch(count)
					{
						/*In case an ID does not have any loan*/
						case 0:
							printf("There is no loan for this ID\n");break;
						/*For one loan*/
						case 1:
						{
							sscanf(lines[i], "%d %d %f %d", &value, &count, &loan1, &period_1);
							printf("Loans = [%.2f] => %.2f\n", loan1, loan1);
						}break;
						/*For two loan*/
						case 2:
						{
							sscanf(lines[i], "%d %d %f %d %f %d", &value, &count, &loan1, &period_1, &loan2, &period_2);
							printf("Loans = [%.2f + %.2f] => %.2f\n", loan1, loan2, loan1 + loan2);			
						}break;
						/*For three loan*/
						case 3:
						{
							sscanf(lines[i], "%d %d %f %d %f %d %f %d", &value, &count, &loan1, &period_1, &loan2, &period_2, &loan3, &period_3);
							printf("Loans = [%.2f + %.2f + %.2f] => %.2f\n", loan1, loan2, loan3, loan3 + loan2 + loan1);					
						}break;
					}
				}
				
				
			}
		}
		//fclose(loan_ptr);
		fclose(ptr);
	}

	else if(option == 2)
	{
		loan_ptr = fopen("loan.txt", "r");
		printf("Enter the ID and number of credit(like 1, 2 or 3) : ");
		scanf("%d %d", &id, &new_value);
		while(fgets(buffer, 100, loan_ptr))
		{
			sscanf(buffer, "%d %d %s", &value, &count, temp);
			if(value == id)
			{
				/*In case there are three loan for an ID*/
				if(count == 3)
				{
					/*I will find the specific loan that user wanted*/
					switch(new_value)
					{
						case 1:
						{
							sscanf(buffer, "%d %d %f %d", &value, &count, &loan1, &period_1);
							printf("Total Credit Value = %.3f\n", loan1);
							Month_Installment(loan1, period_1);
						}break;
						case 2:
						{
							sscanf(buffer, "%d %d %f %d %f %d", &value, &count, &loan1, &period_1, &loan2, &period_2);
							printf("Total Credit Value = %.3f\n", loan2);
							Month_Installment(loan2, period_2);

						}break;
						case 3:
						{
							sscanf(buffer, "%d %d %f %d %f %d %f %d", &value, &count, &loan1, &period_1, &loan2, &period_2, &loan3, &period_3);
							printf("Total Credit Value = %.3f\n", loan3);
							Month_Installment(loan3, period_3);
						}break;
					}
				}
				/*In case there are two loan for an ID*/
				else if(count == 2)
				{
					/*I will find the specific loan that user wanted*/
					switch(new_value)
					{
						case 1:
						{
							sscanf(buffer, "%d %d %f %d", &value, &count, &loan1, &period_1);
							printf("Total Credit Value = %.3f\n", loan1);
							Month_Installment(loan1, period_1);
						}break;
						case 2:
						{
							sscanf(buffer, "%d %d %f %d %f %d", &value, &count, &loan1, &period_1, &loan2, &period_2);
							printf("Total Credit Value = %.3f\n", loan2);
							Month_Installment(loan2, period_2);
						}break;
					}

				}
				/*In case there is one loan for an ID*/
				else if(count == 1)
				{
					/*I will find the specific loan that user wanted*/
					switch(new_value)
					{
						case 1:
						{
							sscanf(buffer, "%d %d %f %d", &value, &count, &loan1, &period_1);
							printf("Total Credit Value = %.3f\n", loan1);
							Month_Installment(loan1, period_1);
						}break;
					}

				}
				else
					printf("There is no loan for this ID\n");
			}
		}
	}

}/*The end of the getReport*/

/*Printing the amount of installment for every month*/
void Month_Installment(float loan, int period)
{
	int i;
	float installment;
	installment = loan / period;
	for(i = 0; i < period; i++)
		printf("%d. Month Installment = %.3f\n", i + 1, installment);

}/*The end of the Month_Installment*/


