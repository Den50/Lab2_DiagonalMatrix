#pragma once
// this module contain struct and functions for work with complex numbers

// functions:
// add(a, b) -> (a_R + b_R) + (a_C + b_C)i
// minus(a, b) -> (a_R - b_R) + (a_C - b_C)i
// multiply(a, b) -> (a_R * b_C - a_C * b_R) - (a_C * b_C + a_R * b_R)i
// division(a, b) -> (a_R + b_R) + (a_C + b_C)i
// multiplyOnAlpha(a, alpha) -> (a_R + b_R) + (a_C + b_C)i


struct Complex {
    double real;
    double im;
};
typedef struct Complex complex;

//signatures
complex createComplex(double real, double im, complex* container);
complex complex_summ(complex a, complex b);
complex complex_minus(complex a, complex b);
complex complex_multiply(complex a, complex b);
complex complex_division(complex a, complex b);
complex complex_multiplyOnAlpha(complex a, double alpha);
void complex_print(complex* a);
