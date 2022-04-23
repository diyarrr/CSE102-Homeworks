#include <stdio.h>
#include "util.h"
#include <math.h>

char dt1a(double PL, double PW){
    /*According to entered numbers, it will return a character*/
    if(PL<2.45)
    {
        return 's'; /*For Setosa*/
    }
    else if(PL>=2.45 && PW>=1.75)
    {
        return 'v'; /*For Virginica*/
    }
    else if(PL>=2.45 && PW<1.75 && PL>=4.95)
    {
        return 'v'; /*For Virginica*/
    }
    else if(PL>=2.45 && PW<1.75 && PL<4.95 && PW>=1.65)
    {
        return 'v'; /*For Virginica*/
    }
    else
    {
        return 'V'; /*For Versicolor*/
    }
    
}/*End of the dt1a*/

char dt1b(double PL, double PW){
    /*According to given numbers it will return a character*/
    if(PL<2.55)
    {
        return 's'; /*For Setosa*/

    }
    else if(PL>=2.55 && PW>=1.69)
    {
        return 'v'; /*For Virginica*/
    }
    else if(PL>=2.55 && PW<1.69 && PL>=4.85)
    {
        return 'v'; /*For Virginica*/
    }
    else{
        return 'V'; /*For Versicolor*/
    }

}/*End of the dt1b*/

double dt2a(double x1, double x2, double x3, int x4, int x5){
    /*Returning a real number with given numbers*/
    if(x1<31.5 && x2>-2.5)
        return 5.0;

    else if(x1<31.5 && x2<=-2.5)
    {
        if(x2-0.1<=x1 && x2+0.1>=x1)
            return 2.1;
        else
            return -1.1;
    }
    if(x1>=31.5 && x3>=-1 && x3<=2)
        return 1.4;
    else if(x1>=31.5 && x3<-1 && x3>2 && ((x4 && x5)== 1))
        return -2.23;
    else
        return 11.0;

}/*End of the dt2a*/


double dt2b(double x1, double x2, double x3, int x4, int x5){
    /*Returning a real number with given numbers*/
    if(x1>12 && x1<22 && x3>(double)5/3)
        return -2.0;

    else if(x1>12 && x1<22 && x3<=(double)5/3)
    {
        if(x1-0.1<=x3 && x3<=x1+0.1)
            return 1.01;
        else
            return -8;
    }

    if((x1>=22 || x1<=12) && ((x4 && x5) == 1))
        return -1;
    else if((x1>=22 || x1<=12) && ((x4 && x5) == 0))
        {
            if(x2>=-1 && x2<=2)
                return (double)-1/7;
            else
                return (double)sqrt(2)/3;

        }

}/*End of the dt2b*/


int dt3a(double age, double weight, int personal_or_commercial, int number_of_person, int hp){
    /*Returning a car class with given inputs*/
    if(age<18)
        return 0;
    else if(age>=18 && weight<=10000 && (personal_or_commercial == 1) && (1<=number_of_person && number_of_person<=4))
        return 1;
    else if(age>=18 && weight<=10000 && (personal_or_commercial ==1) && (number_of_person>4))
    {
        if(number_of_person>4 && number_of_person<=8)
            return 3;
        else
            return 0;
    }
    if(age>=18 && weight<=10000 && (personal_or_commercial == 0) && (hp>=240 && hp<=400))
        return 3;
    else if(age>=18 && weight<=10000 && (personal_or_commercial == 0) && (hp>=130 && hp<=170))
        return 2;
    else if(age>=18 && weight<=10000 && (personal_or_commercial == 0))
    {
        if(hp>=130 && hp<=170)
            return 1;
        else
            return 0;
    }
    if(age>=18 && weight>10000)
    {
        if(weight>=10001 && weight<=14000)
            return 3;
        else if(weight>=14001 && weight<=16000)
            return 4;
        else if(weight>=16001 && weight<=19500)
            return 5;
        else if(weight>=19501 && weight<=26000)
            return 6;
        else if(weight>=26001 && weight<=33000)
            return 7;   
        else
            return 8;
    }

}/*End of the dt3a*/

int dt3b(double age, double weight, int personal_or_commercial, int number_of_person, int hp){
    /*Returning a car class with given inputs*/
    if(number_of_person<2)
        return 0;
    else if((number_of_person>=2 && number_of_person<=4) && (age>=18 && age<=40) && (hp>=240 && hp<=400))
        return 3;

    else if((number_of_person>=2 && number_of_person<=4) && (age>=18 && age<=40))
    {
        if(hp<240 && hp>50)
            return 2;
        else
            return 0;
    }
    else if((number_of_person>=2 && number_of_person<=4) && (age>40 || age<18))
    {
        if(personal_or_commercial == 1)
            return 1;
        else
            return 4;
    }
    if(number_of_person>4 && ((personal_or_commercial) == 1))
    {
        if(number_of_person<=8)
            return 3;
        else
            return 7;
    }
    else if(number_of_person>4 && (personal_or_commercial == 0) && (weight>=26001 && weight<33000))
        return 7;
    else if(number_of_person>4 && (personal_or_commercial == 0) && (weight>=19501 && weight<=26000))
        return 6;
    else if(number_of_person>4 && (personal_or_commercial == 0))
    {
        if(weight>=16001 && weight<=19500)
            return 5;
        else
            return 0;
    }

}/*End of the dt3b*/
    
