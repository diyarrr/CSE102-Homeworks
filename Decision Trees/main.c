#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"


int main(){
    
    int which_problem;
    while(1){

        printf("\nPlease enter the problem that you want to solve(to quit press 0) : ");
        scanf("%d", &which_problem);

        if(which_problem == 1)
        { 
            double PL, PW;
        
            printf("Enter the PL:");
            scanf("%lf", &PL);
            printf("Enter the PW:");
            scanf("%lf", &PW);
            /*If two functions return same value then there will only one output*/
            if(dt1a(PL, PW) == dt1b(PL,PW))
            {
                if(dt1a(PL, PW) == 's')
                    printf("Setosa\n");
                else if(dt1a(PL, PW) == 'v')
                    printf("Virginica\n");
                else
                    printf("Versicolor\n");
            }
            /*If they are differ from each other both result will be reported*/
            else
            {   
                printf("\nResult of the first function is : ");
                if(dt1a(PL, PW) == 's')
                    printf("Setosa\n");
                else if(dt1a(PL, PW) == 'v')
                    printf("Virginica\n");
                else
                    printf("Versicolor\n");

                printf("Result of the second function is : ");
                if(dt1b(PL, PW) == 's')
                    printf("Setosa\n");
                else if(dt1a(PL, PW) == 'v')
                    printf("Virginica\n");
                else
                    printf("Versicolor\n");

            }

        }

        else if(which_problem == 2)
        {
            double x1, x2, x3; 
            int x4, x5;

            double output_of_first_func, output_of_second_func, average_of_outputs, value1, value2;


            printf("Enter the x1 : ");
            scanf("%lf", &x1);
            printf("Enter the x2 : ");
            scanf("%lf", &x2);
            printf("Enter the x3 : ");
            scanf("%lf", &x3);
            printf("Enter the x4(1 or 0) : ");
            scanf("%d", &x4);
            printf("Enter the x5(1 or 0) : ");
            scanf("%d", &x5);

            output_of_first_func = dt2a(x1, x2, x3, x4, x5);
            output_of_second_func = dt2b(x1, x2, x3, x4, x5);

            /*Calculating difference between the returned values */
            value1 = output_of_first_func - output_of_second_func;
            value2 = output_of_second_func - output_of_first_func;
       
            /*In case of same output from different function,it will return only one value*/
            if(output_of_first_func == output_of_second_func)
                printf("%lf", output_of_first_func);
            /*If values that returned are close enough then it will take the average of returns*/
            else if((value1 <= CLOSE_ENOUGH && value1>0) || (value2<=CLOSE_ENOUGH && value2>0))
            {
                average_of_outputs = (output_of_first_func + output_of_second_func)/2;
                printf("Average of outputs : %lf\n", average_of_outputs);
            }
            /*If they are differ from each other both result will be reported*/
            else
            {
                printf("Output of the first function is %lf\n", output_of_first_func);
                printf("Output of the second function is %lf\n", output_of_second_func);
            }

        }

        else if(which_problem == 3)
        {
            printf("\n----------- WHICH CAR CLASS IS SUITABLE FOR YOU -------------------\n");
            double your_age, weight_of_car;
            int personal_or_commercial, number_of_seats, horse_power, first_func_data, second_func_data;
            printf("Enter your age : ");
            scanf("%lf", &your_age);
            printf("Enter the weight of the car(in terms of Ib(pound)) : ");
            scanf("%lf", &weight_of_car);
            printf("Personal or Commercial(1:personal / 0:commercial) : ");
            scanf("%d", &personal_or_commercial);
            printf("Enter the number of seats : ");
            scanf("%d", &number_of_seats);
            printf("Enter the horse power of the car : ");
            scanf("%d", &horse_power);

            /*In case of using functions in many places*/
            first_func_data = dt3a(your_age, weight_of_car, personal_or_commercial, number_of_seats, horse_power);
            second_func_data = dt3b(your_age, weight_of_car, personal_or_commercial, number_of_seats, horse_power);
            /*If they are same,it will print one result*/
            
            if(first_func_data == second_func_data)
            {
                if(first_func_data == 0)
                    printf("\nNothing is suitable.\n");
                else
                    printf("Class %d\n", first_func_data);
            }
            /*Different result will be reported*/
            else
            {
                if(first_func_data == 0)
                {
                    printf("Nothing is suitable.\n");
                    printf("Class %d", second_func_data);
                }
                else if(second_func_data == 0)
                {
                    printf("\nClass %d\n", first_func_data);
                    printf("Nothing is suitable .\n");
                }
                else
                {
                    printf("\nClass %d\n", first_func_data);
                    printf("Class %d\n", second_func_data);
                }
            }


     
        }
        else if(which_problem == 0)
        {
            printf("\nquitting...\n");
            break;
        }
        else
        {
            printf("Undefined problem.\n");
            return 0;
        }
    }


    return 0;
        }
