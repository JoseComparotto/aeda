#include <stdio.h>
#include <math.h>

typedef struct
{
    float real;
    float imaginary;
} complex;

complex sqrt(float);
complex negative(complex);
complex sum(complex, complex);
complex sum(float, complex);
complex sum(complex, float);
complex subtract(complex, complex);
complex subtract(float, complex);
complex subtract(complex, float);
complex multiply(complex, complex);
complex multiply(float, complex);
complex multiply(complex, float);

int main(){

}
