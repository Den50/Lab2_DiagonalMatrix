//#include "complex.h"
//#include <iostream>
//#include <cmath>
//#include <limits>
//
//bool is_equal(double x, double y) {
//    return std::fabs(x - y) < 1E-10;
//}
//
//using namespace MAIN;
//
//// Constructors
//Complex::Complex(Complex* par) {
//    this->data.real = par->getReal();
//    this->data.imaginary = par->getIm();
//}
//Complex::Complex(double real, double imaginary) {
//    this->data.real = real;
//    this->data.imaginary = imaginary;
//}
//Complex::Complex() : Complex(0.0, 0.0) {}
//
//
//
//// Getters:
//double Complex::getReal() { return this->data.real; }
//double Complex::getIm() { return this->data.imaginary; }
//complex Complex::get() { return this->data; }
//
//// Setters:
//void Complex::set(double real, double imaginary) {
//    this->data.real = real;
//    this->data.imaginary = imaginary;
//}
//
//// functions
//Complex Complex::add(Complex operand) {
//    Complex summ;
//    summ.set(this->getReal() + operand.getReal(), this->getIm() + operand.getIm());
//    return summ;
//}
//
//Complex Complex::sub(Complex operand) {
//    Complex sub;
//    sub.set(this->getReal() - operand.getReal(), this->getIm() - operand.getIm());
//    return sub;
//}
//
//Complex Complex::multiply(Complex a) {
//    Complex c;
//    c.set(a.getReal() * this->getReal() - a.getIm() * this->getIm(), 
//        a.getIm() * this->getReal() + a.getIm() * this->getReal());
//    return c;
//}
//
//Complex Complex::multiplyOnAlpha(double alpha) {
//    Complex mult;
//    double real = alpha * this->getReal();
//    double imaginary = alpha * this->getIm();
//    mult.set(real, imaginary);
//    return mult;
//}
//
//bool Complex::isEqual(Complex operand) {
//    return is_equal(this->getReal(), operand.getReal()) && is_equal(this->getIm(), operand.getIm());
//}
//
//// overloading operators
//
//Complex Complex::operator+(Complex operand) { return this->add(operand); }
//Complex Complex::operator-(Complex operand) { return this->sub(operand); }
//
//Complex Complex::operator*(Complex operand) { return this->multiply(operand); }
//
//Complex Complex::operator*(double alpha) { return this->multiplyOnAlpha(alpha); }
//bool Complex::operator==(Complex operand) { return this->isEqual(operand); }
//bool Complex::operator!=(Complex operand) { return !this->isEqual(operand); }
//
//void Complex::print() {
//    std::cout << "cmplx(" << this->data.real << ", " << this->data.imaginary << "i)";
//}