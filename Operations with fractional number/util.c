#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - (n2*d1);
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2; 
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = n2*d1;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
    int i,gcd,temp1,temp2,small_number;
    /*These two variables used for negative numbers*/
    temp1=*n;
    temp2=*d;

    if(temp1<0){
        temp1*=-1; //to find gcd,number should be positive 
    }
    if(temp2<0){
        temp2*=-1; //to find gcd,number should be positive
    }

    /*These statements tell 'for loop' where to stop*/
    if(temp2<temp1){
        small_number=temp2;
    }
    else if(temp2==temp1){
        small_number=temp2;
    }
    else{
        small_number=temp1;
    }


    for(i=1;i<=small_number;i++){
        if(temp1%i==0 && temp2%i==0){
            gcd=i;
        }
    }
    *d/=gcd; //Simplifying the numerator
    *n/=gcd; //Simplifying the denominator

} /* end fraction_div */
