#include <stdio.h>
#include "util.h"


int main() {
    int num4, den4, num5, den5;  //These variables will contain value of the given numbers

    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 13/7 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");


    printf("-------------------------------------------------------------------\n");

    printf("First numerator:");
    scanf("%d",&num4);
    printf("First denominator(Enter any integer but 0):");  //number 0 makes fractional number undefined
    scanf("%d",&den4);
    printf("Second numerator:");
    scanf("%d",&num5);
    printf("Second denominator(Enter any integer but 0):"); //number 0 makes fractional number undefined
    scanf("%d",&den5);


    /*Addition of the given numbers*/
    printf("Addition: ");
    fraction_add(num4, den4, num5, den5, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*Subtraction of the given numbers*/
    printf("Subtraction: ");
    fraction_sub(num4, den4, num5, den5, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*Multiplication of the given numbers*/
    printf("Multiplication: ");
    fraction_mul(num4, den4, num5, den5, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*Division of the given numbers*/
    printf("Division: ");
    fraction_div(num4, den4, num5, den5, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    return(0);
}
