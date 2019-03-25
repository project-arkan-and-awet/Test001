//
//  Account.cpp
//  BankAccount
//
//  Created by Arkan Tesfay Mekonen on 3/24/19.
//  Copyright © 2019 Arkan Tesfay Mekonen. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Account
{
public: int AccountNumber;
public: double Balance;
public: Account(int AN,double B )
    {
        AccountNumber=AN;
        Balance=B;
        
    }
    
    public: void setAccountNUmber(int A)
    {
        AccountNumber=A;
        
    }
    public: int getAccountNumber()
    {
        return AccountNumber;
    }
    
    public : double getBalance()
    {
        return Balance;
    }
    
    public: void Deposit(double amount)
    {
        Balance+=amount;
        
    }
public: void withDraw(double amount)
    {
        if (Balance >1 && amount<Balance) {
            Balance -=amount;
            
        }else{
            cout <<"ALERT!!!"<<endl;
            cout <<"Your current amount is lower"<<endl;
            
            
        }
    }
    public : void accountRecipt()
    {
        cout << "Your current Balance is $"<<Balance<<". And your Account Number is #"<<AccountNumber<<endl;
    }
    
    


};
