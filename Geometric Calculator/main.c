#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14
int select_shape();
int select_calc();
int calculate(int(*select_shape)(), int(*select_calc)());
int calc_triangle(int option);
int calc_quadrilateral(int option);
int calc_circle(int option);
int calc_pyramid(int option);
int calc_cylinder(int option);

enum Shapes{Triangle = 1, Quadrilateral, Circle, Pyramid, Cylinder};
enum Calculators{Area = 1, Perimeter, Volume}; 

int main(){
	printf("Welcome to the geometric calculator!\n");
	int result_of_calculate; // to use in loop I declare a variable
	int flag = 0;
	while(flag == 0)
	{
		result_of_calculate = calculate(select_shape, select_calc); // if it is in loop then it will call calculate function until it exits
		if(result_of_calculate == -999)
			printf("Invalid option.\n\n");
		if(result_of_calculate == 0) // It is for exitting
			flag = 1;
	}
	printf("\nExitting...\n");
	
}

int select_shape(){
	/*I will take the values with enum type*/
	enum Shapes which_shape;
	int flag = 1;
	char ch; 
	printf("\nSelect a shape to calculate:\n"
		"-----------------------------------\n"
		"1. Triangle\n"
		"2. Quadrilateral\n"
		"3. Circle\n"
		"4. Pyramid\n"
		"5. Cylinder\n"
		"0. Exit\n"
		"------------------------------------\n"
		"Input : ");
	if(scanf("%u", &which_shape) != 1)
	{
		do
		{
			ch = getchar();
			if(ch == 10) // Until I press enter it will get character
				flag = 0;

		}while(flag == 1);
		return -999;
	}
	/*If it is not suitable value*/
	else if(which_shape > 5 || which_shape < 0) 
		return -999;
	return which_shape;
}/*The end of the select_shape*/

int select_calc(){
	/*I will take the values with enum type*/
	enum Calculators which_calc;
	int flag = 1;
	char ch;
	printf("Select Calculator\n"
		"---------------------------\n"
		"1. Area\n"
		"2. Perimeter\n"
		"3. Volume\n"
		"0. Exit\n"
		"---------------------------\n"
		"Input : ");
	if(scanf("%u", &which_calc) != 1){
		do
		{
			ch = getchar();
			if(ch == 10) // Until I press enter, it will get character
				flag = 0;
		}while(flag == 1);
		return -1;
	}
	/*If it is not suitable value*/
	else if(which_calc > 3 || which_calc < 0)
		return -1;
	return which_calc;
}/*The end of the select_calc*/

int calculate(int (*select_shape)(), int (*select_calc)()){
	enum Shapes result_of_select_shape;
	enum Calculators result_of_select_calc;
	result_of_select_shape = select_shape(); // I will declare it so i can use in switch-case
	switch(result_of_select_shape)
	{
		/*In each case select_calc is going to return 0 -1 1 2 3 */
		case 0:
			return 0; // In case exitting
		case -999:
			return -999; // In case invalid value
		case 1:
		{
			result_of_select_calc = select_calc();
			if(result_of_select_calc == 0)
				return 0;
			else if(result_of_select_calc == -1)
				return -999;
			else
				calc_triangle(result_of_select_calc);
		}break;
		case 2:
		{
			result_of_select_calc = select_calc();
			if(result_of_select_calc == 0)
				return 0;
			else if(result_of_select_calc == -1)
				return -999;
			else
				calc_quadrilateral(result_of_select_calc);
		}break;
		case 3:
		{
			result_of_select_calc = select_calc();
			if(result_of_select_calc == 0)
				return 0;
			else if(result_of_select_calc == -1)
				return -999;
			else
				calc_circle(result_of_select_calc);
		}break;
		case 4:
		{
			result_of_select_calc = select_calc();
			if(result_of_select_calc == 0)
				return 0;
			else if(result_of_select_calc == -1)
				return -999;
			else
				calc_pyramid(result_of_select_calc);
		}break;
		case 5:
		{
			result_of_select_calc = select_calc();
			if(result_of_select_calc == 0)
				return 0;
			else if(result_of_select_calc == -1)
				return -999;
			else
				calc_cylinder(result_of_select_calc);
		}break;	
	}

}/*The end of the calculate*/

int calc_triangle(int option){
	float s, result, semi_perimeter, side1, side2, side3; 
	int flag = 1;
	char ch;
	switch(option)
	{
		case 1:
		{
			printf("Please enter three sides of triangle :\n");
			while(1)
			{
				/*If we give unvalid value it will give error*/
				if(scanf("%f", &side1) != 1 || scanf("%f", &side2) != 1 || scanf("%f", &side3) != 1)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*Sides must be positive*/
				else if(side1 <= 0 || side2 <= 0 || side3 <= 0)
					printf("ERROR ! Please enter a valid entry\n");
				/*Sum of two different sides can not be less than the third one*/
				else if(side1 + side2 < side3 || side1 + side3 < side2 || side2 + side3 < side1)
					printf("ERROR ! Please enter a valid triangle.\n");
				/*If everything is correct*/
				else
					break;
			}
			/*Heron formula*/
			s = (side1 + side2 + side3)/2;
			result = s * (s - side1) * (s - side2) * (s - side3);
			result = sqrt(result);
			printf("Area of a triangle : %.2f\n", result);
		}break;
		case 2:
		{
			printf("Please enter three sides of triangle :\n");
			while(1)
			{
				/*If we give unvalid value , it will give an error*/
				if(scanf("%f", &side1) != 1 || scanf("%f", &side2) != 1 || scanf("%f", &side3) != 1)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*Sides must be positive*/
				else if(side1 <= 0 || side2 <= 0 || side3 <= 0)
					printf("ERROR ! Please enter a valid entry\n");	
				else
				{
					result = side1 + side2 + side3;
					semi_perimeter = result / 2;
					/*Semi perimeter can not be less than any side*/
					if(semi_perimeter < side1 || semi_perimeter < side2 || semi_perimeter < side3)
						printf("ERROR ! Please enter a valid triangle.\n");
					/*If everything is correct*/
					else
						break;
				}
				
			}
			printf("Perimeter of Triangle : %.2f\n", result);
		}break;
		case 3:
			printf("ERROR ! You cannot calculate volume of a triangle.Please try again.\n");break;
	}
}/*The end of the calc_triangle*/

int calc_quadrilateral(int option){
	float result, s, side1, side2, side3, side4;
	int flag = 1;
	char ch;
	switch(option)
	{
		case 1:
		{
			printf("Please enter four sides of quadrilateral :\n");
			while(1)
			{
				/*Values must be float. Otherwise it will give an error*/
				if(scanf("%f", &side1) != 1 || scanf("%f", &side2) != 1 || scanf("%f", &side3) != 1 || scanf("%f", &side4) != 1)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*Values must positive*/
				else if(side1 <= 0 || side2 <= 0 || side3 <= 0 || side4 <= 0)
					printf("ERROR ! Please enter a valid entry\n");
				else
				{
					/*Quadrilateral inequality*/
					if((side1 * side1 + side2 * side2 + side3 * side3) <= (side4 * side4)/3.0 ||
						(side4 * side4 + side2 * side2 + side3 * side3) <= (side1 * side1)/3.0 ||
						(side1 * side1 + side4 * side4 + side3 * side3) <= (side2 * side2)/3.0 ||
						(side1 * side1 + side2 * side2 + side4 * side4) <= (side3 * side3)/3.0)
						printf("ERROR ! Please enter a valid entry\n");
					/*If everything is correct*/
					else
						break;
				}
			}
			/*Brahmagupta′𝒔 Formula*/
			s = (side1 + side2 + side3 + side4) / 2;
			result = (s - side1) * (s - side2) * (s - side3) * (s - side4);
			result = sqrt(result);
			printf("Area of Quadrilateral : %.2f\n", result);
		}break;
		case 2:
		{
			printf("Please enter four sides of quadrilateral :\n");
			while(1)
			{
				/*Values must be float. Otherwise it will give an error*/
				if(scanf("%f", &side1) != 1 || scanf("%f", &side2) != 1 || scanf("%f", &side3) != 1 || scanf("%f", &side4) != 1)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*Sides must be positive*/
				else if(side1 <= 0 || side2 <= 0 || side3 <= 0 || side4 <= 0)
					printf("ERROR ! Please enter a valid entry\n");
				else
				{
					/*Quadrilateral inequality*/
					if((side1 * side1 + side2 * side2 + side3 * side3) <= (side4 * side4)/3.0 ||
						(side4 * side4 + side2 * side2 + side3 * side3) <= (side1 * side1)/3.0 ||
						(side1 * side1 + side4 * side4 + side3 * side3) <= (side2 * side2)/3.0 ||
						(side1 * side1 + side2 * side2 + side4 * side4) <= (side3 * side3)/3.0)
						printf("ERROR ! Please enter a valid entry\n");
					/*In case everything is right*/
					else
						break;
				}
			}
			result = side1 + side2 + side3 + side4;
			printf("Perimeter of Quadrilateral : %.2f\n", result);
		}break;
		case 3:
			printf("ERROR ! You cannot calculate volume of a quadrilateral. Please try again.\n"); break;
	}
}/*The end of the calc_quadrilateral*/

int calc_circle(int option){
	float result, radius;
	int flag = 1;
	char ch;
	switch(option)
	{
		case 1:
		{

			printf("Please enter radius of the Circle :\n");
			while(1)
			{
				/*Radius must be float and it must be positive. Otherwise it will give an error*/
				if(scanf("%f", &radius) != 1 || radius <= 0)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*In case everything is right*/
				else
					break;

			}
			result = PI * radius * radius;
			printf("Area of Circle : %.2f\n", result);
		}break;
		case 2:
		{
			printf("Please enter radius of the Circle :\n");
			while(1)
			{
				/*Radius must be float and it must be positive. Otherwise it will give an error*/
				if(scanf("%f", &radius) != 1 || radius <= 0)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*In case everything is right*/
				else
					break;
			}
			/*Circumference formula*/
			result = 2 * PI * radius;
			printf("Circumference of Circle : %.2f\n", result);
		}break;
		case 3:
			printf("ERROR ! You cannot calculate volume of a circle. Please try again.\n"); break;
	}
}/*The end of calc_circle*/

int calc_pyramid(int option){
	float result, base_side, slant_height, base_surface, lateral_surface, height_of_pyramid;
	int flag = 1;
	char ch;
	switch(option)
	{
		case 1:
		{
			printf("Please enter the base side and slant height of a Pyramid :\n");
			while(1)
			{
				/*The inputs must be float and positive. Otherwise it will give an error*/
				if(scanf("%f", &base_side) != 1 || scanf("%f", &slant_height) != 1 || base_side <= 0 || slant_height <= 0)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*In case everything is right*/
				else
					break;
			}
			/*Base surface and lateral surface formula*/
			base_surface = base_side * base_side;
			lateral_surface = 2 * base_side * slant_height;
			printf("Base Surface Area of a Pyramid : %.2f\n\n", base_surface);
			printf("Lateral Surface Area of a Pyramid : %.2f\n\n", lateral_surface);
			result = base_surface + lateral_surface;
			printf("Surface Area of a Pyramid : %.2f\n", result);
		}break;
		case 2:
		{
			printf("Please enter the base side and height of a Pyramid:\n");
			while(1)
			{
				/*The value must be float and positive. Otherwise it will give an error*/
				if(scanf("%f", &base_side) != 1 || scanf("%f", &height_of_pyramid) != 1 || base_side <= 0 || height_of_pyramid <= 0)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*If input is right*/
				else
					break;
			}
			/*Perimeter formula*/
			result = 4 * base_side;
			printf("Base Surface Perimeter of a Pyramid : %.2f\n", result);

		}break;
		case 3:
		{
			printf("Please enter the base side and height of a Pyramid :\n");
			while(1)
			{
				/*The inputs must be float and positive. Otherwise it will give an error*/
				if(scanf("%f", &base_side) != 1 || scanf("%f", &height_of_pyramid) != 1 || base_side <= 0 || height_of_pyramid <= 0)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*If inputs are right*/
				else
					break;
			}
			/*Volume formula*/
			result = (base_side * base_side * height_of_pyramid) / 3;
			printf("Volume of a Pyramid : %.2f\n", result);
		}break;

	}
}/*The end of calc_pyramid*/

int calc_cylinder(int option){
	float volume, radius, height, base_surface, lateral_surface, surface_area, perimeter;
	int flag = 1;
	char ch;
	switch(option)
	{
		case 1:
		{
			printf("Please enter the radius and height of a Cylinder :\n");
			while(1)
			{
				/*Inputs must be float and positive. Otherwise it will give an error*/
				if(scanf("%f", &radius) != 1 || scanf("%f", &height) != 1 || radius <= 0 || height <= 0)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*If inputs are correct*/
				else
					break;
			}
			/*Base surface, lateral surface and surface area formula*/
			base_surface = PI * radius *radius;
			lateral_surface = 2 * PI * radius * height;
			surface_area = 2 * PI * radius * (radius + height);
			printf("Base Surface Area of a Cylinder : %.2f\n\n", base_surface);
			printf("Lateral Surface Area of a Cylinder : %.2f\n\n", lateral_surface);
			printf("Surface Area of a Cylinder : %.2f\n", surface_area);
		}break;
		case 2:
		{
			printf("Please enter the radius and height of a Cylinder :\n");
			while(1)
			{
				/*Inputs must be float and positive. Otherwise it will give an error*/
				if(scanf("%f", &radius) != 1 || scanf("%f", &height) != 1 || radius <= 0 || height <= 0)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*If inputs are correct*/
				else
					break;
			}
			perimeter = 2 * PI * radius;
			printf("Base Surface Perimeter of a Cylinder : %.2f\n", perimeter);

		}break;
		case 3:
		{
			printf("Please enter the radius and height of a Cylinder :\n");
			while(1)
			{
				/*Inputs must be float and positive. Otherwise it will give an error*/
				if(scanf("%f", &radius) != 1 || scanf("%f", &height) != 1 || radius <= 0 || height <= 0)
				{
					do
					{
						ch = getchar();
						if(ch == 10) // In case pressing enter
							flag = 0;
					}while(flag == 1);
					printf("ERROR ! Please enter a valid entry\n");
					flag = 1;
				}
				/*If inputs are correct*/
				else
					break;
			}
			/*Volume formula*/
			volume = PI * radius * radius * height;
			printf("Volume of a Cylinder : %.2f\n", volume);
		}break;
	}
}/*The end of the calc_cylinder*/





