#include <stdio.h>

#include "mylib.h"




void f(double x){

double d;
double b;
double c;
int xn=(int)x;
c =   sub(add(exp( xn), pow(x ,2) ) , 2);
b=  add(mul(3 , x) , mul( 2, pow(x,2)));
d=  div( mul(4 , pow( x ,3)), sub(5 ,mul(2,x)))  ;


 printf("The value of f(x) = e^x + x^3 − 2 at the point %0.4f is:%0.4f",x,c);
printf("The value of f(x) = 3x + 2X^2 at the point %0.4f is:%0.4f",x,b);

printf("The value of f(x) = (4x^3)/5 -2x at the point %0.4f is:%0.4f",x,d);


}



void main() {

            double a;

            printf("Please inset a real number");

scanf("%lf", &a);

f(a);

}
