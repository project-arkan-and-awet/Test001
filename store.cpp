//
//  Store.cpp
//  BookStore
//
//  Created by Arkan Tesfay Mekonen on 4/4/19.
//  Copyright © 2019 Arkan Tesfay Mekonen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "BookType.cpp"
#include "MemberType.cpp"
using namespace std;

class Store : public BookType, public MemberType
{
public: string name;
public: bool store_Member;
public: int yearly_membership_fee;
public: double store_discount;
public: int number_of_books_purchased;
public: double total_amount_spent;
public: double book_price_after_discount;
public: int eleventh_book;
    
public: Store(BookType book,MemberType member,bool store_member): BookType("","","","","",0.0,0,0), MemberType("","","",0,0){
    name=member.get_First_Name()+" "+member.get_Last_Name();
    store_Member=store_member;
    if (store_member==true) {
        yearly_membership_fee=10.0;
        store_discount=0.05;
        
        for (int j=0; j<sizeof(member.get_Amount_Spent()); j++) {
            total_amount_spent+=j;
        }
        for (int i=0; i<sizeof(member.get_Order()); i++) {
            number_of_books_purchased+=i;
            eleventh_book=number_of_books_purchased%10;
            eleventh_book=total_amount_spent/10;
            if () {
                
            }
        
        }
        
        book_price_after_discount=book.get_Price()-(book.get_Price()*store_discount);
    }
    
    }
    
    
};
