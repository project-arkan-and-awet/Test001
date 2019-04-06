//
//  main.cpp
//  Lab 2 - C Submit Assignment Lab 2 - C Submit Assignment Lab 2 - C Submit Assignment Lab - 2 A
//
//  Created by Awet Fikadu on 3/21/19.
//  Copyright © 2019 Awet Fikadu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "BookType.cpp"
#include "MemberType.cpp"
using namespace std;

class BookType
{
public: string Title;
public: static string author_one,author_two,author_three,author_four;
public: string heading_one,heading_two,heading_three,heading_four,heading_five,heading_six;
public: string ISBN;
public: string Publisher;
public: double Price;
public: int Year_of_publication;
public: int Number_of_copies;
public: int Number_of_authors;
public: int Number_of_headings;
    
public: BookType(string title,string heading,string isbn,string publisher,double price,int YearOFPublication,int NumberOFCopies)
    {
        Title=title;
        heading_one=heading;
        ISBN=isbn;
        Publisher=publisher;
        Price=price;
        Year_of_publication=YearOFPublication;
        Number_of_copies=NumberOFCopies;
        
    }
    
public: string get_Title()
    {
        return  Title;
    }
public: void set_Title(string T)
    {
        Title=T;
        
    }
public: string check_Title(string T)
    {
        if (Title==T) {
            return "Title is Right";
        }else
            return  "Title is not Right";       //change made here (else)
        
    }
public: int get_Number_of_Copies()
    {
        return Number_of_copies;
    }
public: void set_Number_of_Copies(int copies)
    {
        Number_of_copies=copies;
    }
public: int Update_Number_of_Copies(int newNOC)     // changes (new argument passed)
    {
        return Number_of_copies += newNOC;
        
    }
public: string get_Publisher()
    {
        return Publisher;
    }
public: void set_Publisher(string Pub)
    {
        Publisher=Pub;
        
    }
public: double get_Price()
    {
        return Price;
        
    }
public: void set_Price(double newPrice)
    {
        Price=newPrice;
    }
public: string get_ISBN()
    {
        return ISBN;
    }
public: void set_ISBN(string new_ISBN)
    {
        ISBN=new_ISBN;
    }
public: void set_Author(string Author_one,string Author_two,string Author_three,string Author_four)
    {
        author_one=Author_one;
        author_two=Author_two;
        author_three=Author_three;
        author_four=Author_four;
    }
public: void set_Author(string Author_one,string Author_two)
    {
        author_one=Author_one;
        author_two=Author_two;
    }
public: void set_Author(string Author_one)
    {
        author_one=Author_one;
        
    }
    
public: string get_Authors()
    {
        return author_one+" "+author_two+" "+author_three+" "+author_four;
    }
    
    
};
//*************MemberType Class***************
class MemberType
{
    public : string First_Name;
    public : string Last_Name;
    public : string Member_id;
    public : int Orders;
    public : int Amount_spent;
    
public:  MemberType(string FN, string LN,string member_id,int orders,int amount_spent)
    {
        First_Name=FN;
        Last_Name=LN;
        Member_id=member_id;
        Orders=orders;
        Amount_spent=amount_spent;
    }
public: string get_First_Name()
    {
        return First_Name;
    }
public: string get_Last_Name()
    {
        return Last_Name;
    }
public: string get_Member_id()
    {
        return Member_id;
    }
public: int get_Order()
    {
        return Orders;
    }
public: int  get_Amount_Spent()
    {
        return Amount_spent;
    }
public: void set_First_Name(string first)
    {
        First_Name=first;
    }
public: void set_Last_Name(string last)
    {
        Last_Name=last;
    }
public: void set_Member_id(string id)
    {
        Member_id=id;
    }
public: void set_Order(int orders)
    {
        Orders = orders;
    }
public: int update_Orders(int orders)
    {
        return Orders + orders;
    }
public: void set_Amount_Spent(int amount_spent)
    {
        Amount_spent = amount_spent;
    }
public: double update_Amout_Spent(double newAmount)
    {
        return Amount_spent += newAmount;
    }
    //public: bool operation_test()
    //    {
    //        if(
    //    return
    //    }
public: void show()
    {
        cout<<"Member's first name: "<<get_First_Name()<<endl;
        cout<<"Member's last name: "<<get_Last_Name()<<endl;
        cout<<"Member's member ID: "<<get_Member_id()<<endl;
        cout<<"Number of books bought: "<<get_Order()<<endl;
        cout<<"Member's amount spent: "<<get_Amount_Spent()<<endl;
    }
    
};

//**********************Store Class**********************
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
            
            }
            
        }
        
        book_price_after_discount=book.get_Price()-(book.get_Price()*store_discount);
    }
    
}
    
    
};
int main() {

    
    return 0;
}
