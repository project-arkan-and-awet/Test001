//
//  Book.hpp
//  Book
//
//  Created by Awet Fikadu on 10/24/19.
//  Copyright © 2019 Awet Fikadu. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <vector>
#include <stdio.h>
#include "string"

using namespace std;

class Book
{
private:
    vector<string> headings;
    vector<string> author;
    string title;
    string publisher;
    int catalogNo;
    int pubYear;
    bool isCirculating;
    
public:
    Book();
    
    Book(vector<string> heading, vector<string> author, string title, string publisher, int catalogNo, int pubYear);
    
    string getPublisher();
    string getTitle();
    int getCatalogNo();
    int getPubYear();
    bool getIsCirculating();
    
    vector<string> getHeadings()
    {
        return headings;
    }
    vector<string> getAuthor()
    {
        return author;
    }
    
    
    /*
     The title
     § A list of authors
     § The Library of Congress catalog number
     § A list of subject headings
     § The publisher
     § The year of publication
     § Whether the book is circulating or non-circulating
     */
    
};






#endif /* Book_hpp */
