#pragma once
// this module contains struct and functions for work with complex numbers

// functions:
// add(a, b) -> (a_R + b_R) + (a_C + b_C)i
// minus(a, b) -> (a_R - b_R) + (a_C - b_C)i
// multiply(a, b) -> (a_R * b_C - a_C * b_R) - (a_C * b_C + a_R * b_R)i
// division(a, b) -> (a_R + b_R) + (a_C + b_C)i
// multiplyOnAlpha(a, alpha) -> (a_R + b_R) + (a_C + b_C)i


struct _Complex_ {
    double real;
    double imaginary;
};
typedef struct _Complex_ complex;

namespace MAIN {
    class Complex {
    private:
        complex data;
    public:
        // Constructors
        Complex(Complex* par);
        Complex(double real, double imaginary);
        Complex();

        // Getters:
        double getReal();
        double getIm();
        complex get();

        // Setters:
        void set(double real, double imaginary);

        // functions
        Complex add(Complex operand);
        Complex sub(Complex operand);
        Complex multiply(Complex a);
        Complex multiplyOnAlpha(double alpha);

        bool isEqual(Complex operand);

        // overloading operators
        Complex operator+(Complex operand);
        Complex operator-(Complex operand);
        Complex operator*(Complex a);
        Complex operator*(double alpha);
        bool operator==(Complex operand);
        bool operator!=(Complex operand);

        void print();

    };
}

