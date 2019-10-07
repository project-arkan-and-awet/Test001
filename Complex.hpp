//
//  Complex.hpp
//  Overloading
//
//  Created by Awet Fikadu on 10/3/19.
//  Copyright © 2019 Awet Fikadu. All rights reserved.
//



/* Awet Fikadu, cis26.  complex v2
 * -------------------- Declares a class representing complex
 *  numbers.  This version overloads =, <<, + and -
 *  */

// note use of "include guards." You should use these to wrap all of
// your .h files -- they ensure that there will never be multiple
// versions of your .h file included in your programs.  Give any
// (allcaps) identifier after the #ifndef and #define directives --
// generally you'll give a variation of the filename.

#ifndef Complex_H
#define Complex_H

#include <iostream>

//#endif /* _Complex_hpp */

using namespace std;

class ComplexNumber{
public:
    // constructors
    ComplexNumber();
    ComplexNumber(int realPart, int imaginaryPart);
    
    // accessor
    void print() const;
    
    // overloaded operators.
    // equality is generally easiest to write.
    bool operator ==(const ComplexNumber& otherComplex) const;
    
    
    // note that this operator returns an item of class Complex.
    // Think about how when you add two ints together, the result is
    // another int. Likewise, when you add two complex numbers
    // together, the result is another complex number.
    ComplexNumber operator +(const ComplexNumber& otherComplex) const;
    ComplexNumber operator -(const ComplexNumber& otherComplex) const;
    
    
    // THESE ARE THE OPERATORS YOU WILL IMPLEMENT. YOU ARE
    // REQUIRED
    ComplexNumber operator *(const ComplexNumber& otherComplex) const;
    ComplexNumber operator +(int integer);
    friend ComplexNumber operator +(int integer, const ComplexNumber& complex);

    
    // THE BELOW FUNCTION IS TRICKY. UNDERSTANDING THIS IS
    // CRUCIAL TO BEING ABLE TO FULLY REDEFINE THE + OPERATOR IN
    // THE IN-CLASS ASSIGNMENT.
    //
    // Overloaded operator functions that are NOT members of the
    // class must be friend functions of the class, because
    // overloaded operator functions always have to be members
    // of the class on the left hand side of the operation. in
    // this case, the element on the left hand side of:
    //
    // complexNumber number;
    // cout << number;
    //
    // is an ostream object (cout), not a ComplexNumber object.
    // Because we cannot declare this function as part of our
    // class, we declare it as a "friend" of the class -- a
    // non-class function that can nevertheless see the
    // internals of our class.
    //
    // NOTICE: when you define an operator function outside the
    // class, the FIRST parameter is the variable that appears
    // to the left of the operator, and the SECOND parameter is
    // the variable that appears to the right of the operator.
    friend ostream& operator <<(ostream& output, const
                                ComplexNumber& complex);
    //friend ComplexNumber operator +(int integer, const ComplexNumber& complex);
    
    ComplexNumber add(const ComplexNumber& otherComplex) const;
    ComplexNumber subtract(const ComplexNumber& otherComplex) const;
    
private:
    // this is now private, because clients can just use the ==
    // operator instead. I'm keeping it around as a private
    // function, though, since it's used internally by the ==
    // operator itself.
    bool isEquals(const ComplexNumber& otherComplex) const;
    
    int realPart;
    int imaginaryPart;
};


// this directive ends the #ifndef directive above.
#endif
