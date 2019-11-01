//
//  Book.cpp
//  Book
//
//  Created by Awet Fikadu on 10/24/19.
//  Copyright © 2019 Awet Fikadu. All rights reserved.
//
#include <stdio.h>
#include "string"
#include "Book.hpp"
#include <iostream>
#include <vector>

Book::Book()
{
    catalogNo = 0;
    pubYear = 0;
}

string Book::getTitle()
{
    return title;
}

int Book::getCatalogNo()
{
    return catalogNo;
}

int Book::getPubYear()
{
    return pubYear;
}

bool Book::getIsCirculating()
{
    string input;
    cout<<"Is this book cirulate? Yes/No. \n";
    cin>>input;
    
    if(input == "Yes" || input == "yes" || input == "YES" ){
        isCirculating = true;
    }
    if(input == "No" || input == "no" || input == "NO")
    {
        isCirculating = false;
    }
    else
    {
        cout<<"Invaliad Entry! Please Enter Yes/No."<<endl;
    }
    
    return isCirculating;
}
