#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001


char dt1a(double PL, double PW);
char dt1b(double PL, double PW);

double dt2a(double x1, double x2, double x3, int x4, int x5);
double dt2b(double x1, double x2, double x3, int x4, int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */
int dt3a(double age, double weight, int personal_or_commercial, int number_of_person, int hp);
int dt3b(double age, double weight, int personal_or_commercial, int number_of_person, int hp);

#endif /* _UTIL_H_ */