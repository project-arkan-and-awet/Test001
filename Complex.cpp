
// Awet Fikadu, cis25
//  main.cpp
//  Operator overloading assignment Submit Assignment Operator overloading assignment Submit Assignment Operator overloading assignment Submit Assignment Operator overloading assignment Submit Assignment Operator Overloading Assignment
//
//  Created by Awet Fikadu on 10/1/19.
//  Copyright © 2019 Awet Fikadu. All rights reserved.
//

/* Awet Fikadu, cis25
 * Defines a class representing complex numbers.
 * Version 2: overloads the equality operator, the + operator, and the
 * - operator.
 * */

#include "Complex.hpp"
#include <iostream>

using namespace std;

ComplexNumber::ComplexNumber(){
    realPart = 0;
    imaginaryPart = 0;
}

ComplexNumber::ComplexNumber(int realPart, int imaginaryPart){
    this->realPart  = realPart;
    this->imaginaryPart = imaginaryPart;
}

void ComplexNumber::print() const{
    cout << realPart << " + " << imaginaryPart << "i";
}

ComplexNumber ComplexNumber::add(const ComplexNumber& otherComplex) const{
    ComplexNumber result;
    result.realPart = realPart + otherComplex.realPart;
    result.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;
    return result;
}

ComplexNumber ComplexNumber::subtract(const ComplexNumber& otherComplex) const{
    ComplexNumber result;
    result.realPart = realPart - otherComplex.realPart;
    result.imaginaryPart = imaginaryPart - otherComplex.imaginaryPart;
    return result;
}

bool ComplexNumber::operator ==(const ComplexNumber& otherComplex) const{
    if (realPart == otherComplex.realPart &&
        imaginaryPart == otherComplex.imaginaryPart){
        return true;
    }
    return false;
}


// notice that we don't define this operator as part of the
// ComplexNumber class. See the header file for an explanation.
ostream& operator <<(ostream& output, const ComplexNumber& number){
    output << number.realPart;
    output    <<  "+" <<  number.imaginaryPart << "i";
    return output;
}


// these just use our private functions, since we already had them
// defined.
ComplexNumber ComplexNumber::operator -(const ComplexNumber& otherComplex) const {
    return subtract(otherComplex);
}

ComplexNumber ComplexNumber::operator +(const ComplexNumber& otherComplex) const {
    return add(otherComplex);
}


ComplexNumber ComplexNumber::operator *(const ComplexNumber& otherComplex) const{
    
    ComplexNumber result;
    
    result.realPart = (realPart * otherComplex.realPart) - (imaginaryPart * otherComplex.imaginaryPart);
    
    result.imaginaryPart = (realPart * otherComplex.imaginaryPart) + (imaginaryPart * otherComplex.realPart);
    return result;
    
}

ComplexNumber ComplexNumber::operator +(int integer){
    ComplexNumber result;
    result.realPart = realPart + integer;
    return  result;
}

ComplexNumber operator +(int integer, const ComplexNumber& complex){
    ComplexNumber result;
    
    //return (*complex) (complex.realPart + integer);
    result.realPart = integer + complex.realPart ;
    result.imaginaryPart = complex.imaginaryPart;
    return result;
}
//    return Cents(cents.m_cents + value);

//   friend void A::showB(B& x); // Friend function
//   void A::showB(B& x)
//   friend int LinkedList::search();
//   friend class LinkedList;
//   void Box::setBreadth( double bre ); //member function


