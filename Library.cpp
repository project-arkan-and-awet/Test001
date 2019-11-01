//
//  Library.cpp
//  Book
//
//  Created by Awet Fikadu on 10/25/19.
//  Copyright © 2019 Awet Fikadu. All rights reserved.
//

#include "Library.hpp"
#include "Book.hpp"
#include <iostream>

void searchBySubject(string subject)
{
    
    //What this does is iterate through the vector of books and return the iterator of the book matching the
    //condition specified by the lambda function.This lambda function is given as the third argument.
    
    auto itr = std::find_if(books.begin(),books.end(),[&](Book aBook)
                            {
                                
                                //Inside lambda function
                                
                                //std::any_of is another algorithmic function which iterates through the vector of headings and
                                
                                //return true if the condition given by the lambda function given as the third parameter in the std::any_of satisfy
                                
                                //atleast once.
                                bool b = any_of(aBook.getHeadings().begin(),aBook.getHeadings().end(),[&](string sub)
                                                {
                                                    
                                                    //this is the condition
                                                    return sub == subject;
                                                });
                                
                                return b;
                            });
    
    if(itr != books.end())
    {
        cout << "\n Book Found :";
        cout << "\n Details :";
        cout << "\n Book Title : "<<itr->getTitle();
        cout << "\n Author Name :" << itr->getAuthors()[0];
        cout << "\n Catalog Number :" << itr->getCatalogNo();
    }
}

