//
//  Library.hpp
//  Book
//
//  Created by Awet Fikadu on 10/25/19.
//  Copyright © 2019 Awet Fikadu. All rights reserved.
//

#ifndef Library_hpp
#define Library_hpp
#include <vector>
#include <stdio.h>
#include "string"
#include "Book.hpp"

using namespace std;

class Library
{
private:
    vector<Book> books;
    
public:
    void searchBySubject(string subject);
    
};

#endif /* Library_hpp */
/*
 Create a Library class that contains a vector of books. Include a member function SearchBySubject that takes as parameter a subject string. For each book in the library that lists the subject string as one of its headings, SearchBySubject should display the title, the name of the author, and the Library of Congress catalog number of the book.
 */
