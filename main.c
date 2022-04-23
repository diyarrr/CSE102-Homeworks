#include <stdio.h>
#include "utils.h"
#include <string.h>


int main(){
	int x, y, z, n, customer_password, customer_password_for_login;
	char identity_number[100];
	char identity_number_for_login[11];
	float cash_amount;

	/*Getting integers and divisor from the user*/
	printf("Enter the first integer : ");
	scanf("%d", &x);
	printf("Enter the second integer : ");
	scanf("%d", &y);
	printf("Enter the divisor : ");
	scanf("%d", &z);


	/*Finding divisible number*/
	if(find_divisible(x, y, z) == -1){
		printf("There is not any integer between %d and %d can be divided by %d\n", x, y, z);
	}
	else{
		printf("The first integer between %d and %d divided by %d is %d\n", x, y, z, find_divisible(x, y, z));
		
		printf("Enter the number how many next : ");
		scanf("%d", &n);

		/*In case nth divisible number bigger than second integer*/
		if(find_nth_divisible(n, x, z) > y){
			printf("No possible to find Nth divisible between %d and %d divided by %d\n", x, y, z);
		}

		else{
			printf("The %dth integer between %d and %d divided by %d is %d\n", n, x, y, z, find_nth_divisible(n, x, z));
		}
}
	/*Getting identity number and password from the user for writing the file*/
	printf("\nEnter your identity number : ");
	scanf("%s", identity_number);

	printf("Enter your password : ");
	scanf("%d", &customer_password);

	/*Writing to a file*/
	create_customer(identity_number, customer_password);

	printf("------------------------------lOGIN-----------------------------------\n");
	/*I will take this values so that i can compare with file*/
	printf("Enter your identity number : ");
	scanf("%s", identity_number_for_login);
	printf("Enter your password : ");
	scanf("%d", &customer_password_for_login);

	/*Reading from the file and checking if informations are valid or not*/
	if(check_login(identity_number_for_login, customer_password_for_login) == 1){
		printf("\nLogin Successful.\n");
		/*Getting the withdraw amount and returning the withdrawable amount*/
		printf("\nEnter your withdraw amount : ");
		scanf("%f", &cash_amount);
		printf("Withdrawable amount : %d\n", withdrawable_amount(cash_amount));
	}
	else{
		printf("\nInvalid identity number or password.\n");
		return 0;

	}

}

