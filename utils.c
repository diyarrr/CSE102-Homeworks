#include <stdio.h>
#include <string.h>
#include "utils.h"

													/*PART 1*/
int find_divisible(int x, int y, int z){
	int i;
	/*this will increment and when 'i' found a divisible number,the number is gonna be first divisible number*/
	for(i = x;i <= y;i++){
		if(i%z == 0){
			return i;
			break; //if it finds a divisible then there is no need to increment,so it will break
		}
	}
	return -1; // In case nothing returned, we should return something
}
/*end of find_divisible*/

int find_nth_divisible(int n, int f_I, int z){
	int i, count_until_n, temp;
	count_until_n = 0;
	temp = f_I; // i need f_I in two places so i assign value of the f_I to temp 

	/*In case n is 0 without while statement, it will find the first divisible number*/
	if(n == 0){
		for(i = temp; i <= i+z;i++){
			if(i%z == 0){
				return i;
				break;
		}
	}
}
	/*When n is other than 0, it will do the operations in this statement*/
	else{

		while(1){

			if(f_I%z != 0){
				f_I++; //i will increment f_I until it found a divisible number by z
		}
			/*when i found a divisible number i will add divisor to the number instead of incrementation*/
			else{
				f_I+= z;
				count_until_n++; 
		}	
			/**/
			if(count_until_n == n && count_until_n != 0){
				return f_I;

		}
	}
}

}
/*End of nth_find_divisible*/


														/*PART 2*/

int validate_identity_number(char identity_number[]){
	int i, sum_of_digit_13579, sum_of_digit_2468, sum_of_first_ten_digits, tenth_digit, eleventh_digit;;

	i = sum_of_digit_13579 = sum_of_digit_2468 = sum_of_first_ten_digits = 0;

	if(identity_number[0] == 0)
	{
		return 0;
	}
	/*Identity number must be 11 characters*/
	if(strlen(identity_number) != 11){
		return 0;
	}
	/*Adding numbers each other according to their places */
	while(i<9){
		if(i%2 == 0){
			sum_of_digit_13579+= identity_number[i] - 48;
		}
		else{
			sum_of_digit_2468+= identity_number[i] - 48;
		}
		i++;

	}
	/*Adding first ten digits*/
	for(i = 0;i < 10;i++){
		sum_of_first_ten_digits += identity_number[i] - 48;

	}

	tenth_digit = eleventh_digit = 0;

	/*Calculating tenth character*/
	tenth_digit = ((sum_of_digit_13579 * 7) - sum_of_digit_2468);
	tenth_digit = tenth_digit % 10;

	/*Calculating eleventh character*/
	eleventh_digit = sum_of_first_ten_digits % 10;

	/*If calculated digits are equal to given identity number's tenth and eleventh digits*/
	if((tenth_digit == (identity_number[9] - 48)) && (eleventh_digit == (identity_number[10] - 48)))
	{
		return 1;
	}
}
/*End of validate_identity_number*/


int create_customer(char identity_number[], int password){
	FILE *customer_info_printing;

	customer_info_printing = fopen("customeraccount.txt", "w");
	/*Writing informations to the file*/
	fprintf(customer_info_printing, "%s,%d", identity_number, password);
	/*This function will print everything into the file immediately,otherwise we can not scan until program terminated*/

	
	fclose(customer_info_printing);
	return 1;
}
/*End of create_customer*/


														/*PART 3 */

int check_login(char identity_number[], int password){
	FILE *customer_info_scanning;
	char file_identity_number[11];
	int i, file_password;
	char ch;
	i = 0;

	customer_info_scanning = fopen("customeraccount.txt", "r");
	
	/*There are 12 character and 1 integer in the file*/
	while(i < 13)
	{

		if(i < 11){
			/*Getting the identity number character by character*/
			fscanf(customer_info_scanning, "%c", &ch);
			file_identity_number[i] = ch;
		
		}

		else if(i == 11){
			/*This is just a statement for skip this ',' character */
			fscanf(customer_info_scanning, "%c", &ch);

		}
		else{
			/*Getting the integer from the file*/
			fscanf(customer_info_scanning, "%d", &file_password);
		}
		i++;
	}

	/*In case there is no validation*/
	if(validate_identity_number(file_identity_number) == 1 && (password == file_password)){
		return 1;
	}
	else{
		return 0;
	}

}
/*End of check_login*/

int withdrawable_amount(float cash_amount){

	int withdrawable_cash_amount, remainder_cash_amount;
	/*With this operation withdrawable_cash_amount will take the integer part of the cash_amount*/
	withdrawable_cash_amount = cash_amount;

	if(withdrawable_cash_amount%10 == 0){
		return withdrawable_cash_amount;
	}
	/*For example if number is 185 then we need to get rid of from 5 so i will use mod10 operation to achieve that*/
	else{
		remainder_cash_amount = withdrawable_cash_amount%10;

		withdrawable_cash_amount-= remainder_cash_amount;

		return withdrawable_cash_amount;
	}
}
/*End withdrawable_amount*/


