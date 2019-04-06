//
//  main.cpp
//  Lab-2 D
//
//  Created by Awet Fikadu on 3/29/19.
//  Copyright © 2019 Awet Fikadu. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Account
{
public: int AccountNumber;
public: double Balance;
public: double amountWithdrawed;
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

    
public: double withDraw(double amount)
    {
        amountWithdrawed=amount;
        if (Balance >1 && amountWithdrawed<Balance) {
            Balance -=amountWithdrawed;
            
        }else{
            cout <<"ALERT!!!"<<endl;
            cout <<"Your current amount is lower"<<endl;
            
        }
        return  amountWithdrawed;
    }
public: void Deposit(double amount)
    {
       
        
        Balance+=amount;
        cout <<"You Deposited $"<<amount<<" into Your  Account"<<". Your current Balance is "<<getBalance()-amountWithdrawed<<endl;
        
    }
    public : void accountRecipt()
    {
        cout << "Your current Balance is $"<<Balance<<endl;
        cout<<"And your Account Number is #"<<AccountNumber<<"."<<"\t"<<endl;
        cout<<""<<endl;
    }
};

class CheckingAccount : Account
{
    public : double interestRate;
    public: double Checking_Balance=0;
    public :double  minBalance;
    public :double serviceCharge=5;
    public :bool ChekingBalanceBelowMin;
    
public: CheckingAccount(Account user) :Account(user.AccountNumber,user.Balance)
    {
        setInterestRate(user);
        
    };
    
public: void setInterestRate(Account balance)
    {
        double IR = balance.getBalance();
        interestRate=IR*0.002*1;
    }
public: double retireiveInterestRate()
    {
        return interestRate;
    }
public: void postInterest(Account balance)
    {
        cout << interestRate<< endl;
    }
public: void setMinimumBalance(Account balance)
    {
        if (balance.getBalance()<=25) {
            minBalance=balance.getBalance();
        }
    }
public: double retireveMinimumBalance()
    {
        return minBalance;
    }
public: void setServiceCharges(double serviceC)
    {
        if (Balance <= minBalance){
            serviceCharge=serviceC;

        }
    }
public: double retireveServiceCharges()
    {
        return serviceCharge;
    }

public: bool verifyBalance(Account user)
    {
        //balanceBelowMin=false;
        if (user.Balance<= minBalance) {
            ChekingBalanceBelowMin=true;
            cout <<"ALERT!!! Your Balance is below minimum"<<endl;
            cout<<""<<endl;
            //return true;
        }else
        {
            ChekingBalanceBelowMin=false;
            cout <<"Your balance is Good ('_')"<<endl;
            cout<<""<<endl;
        }
        //return  false;
        return ChekingBalanceBelowMin;
    }
public: void writeCheck(double amount,Account user)
    {
        if (verifyBalance(user)) {
            double checkAmount=user.withDraw(amount);
            cout<< "I Authorize the Payment of $"<<checkAmount<<endl;
            cout << "Now your Balance is $"<< user.getBalance()<<endl;
            cout<<""<<endl;
        }else{
            cout <<"Your balance is Good ('_')"<<endl;
            cout<<""<<endl;
        }
        
    }
    
public: void printAccountInfo(Account user)
    {
        cout <<"As of today, your Account Balance is $"<<user.getBalance()<<endl;
        cout<<"Your service charges is $"<< serviceCharge<<endl;
        cout<<"Your Account Number is #"<<user.getAccountNumber()<<endl;
        cout<<"Your interestRate is $"<<retireiveInterestRate()<<endl;
        cout<<""<<endl;
    }
    
};

class SavingAccount : Account
{
    public : double SavinginterestRate;
    public :double SavingminBalance=25;
    public :double SavingserviceCharge=5;
    public :bool SavingbalanceBelowMin;
    
public: SavingAccount(Account S): Account(S.Balance,S.AccountNumber)
    {
        setInterestRateSaving(S);
        
    };
    
public: void setInterestRateSaving(Account balance)
    {
        double IR=balance.getBalance();
        SavinginterestRate=IR*0.002*1;
    }
public: double retireiveInterestRateSaving()
    {
        return SavinginterestRate;
    }
public: void setMinimumBalance(double balance)
    {
        
        
    }
public: double retireveMinimumBalance()
    {
        return SavingminBalance;
    }
public: void setServiceCharges(int serviceC)
    {
        SavingserviceCharge=serviceC;
    }
public: double retireveServiceCharges()
    {
        return SavingserviceCharge;
    }
public: void postInterest()
    {
        cout << SavinginterestRate<< endl;
    }
public: bool SavingverifyBalance(Account user)
    {
        //SavingbalanceBelowMin=false;
        if (user.getBalance()<SavingminBalance) {
            SavingbalanceBelowMin=true;
            cout <<"ALERT!!! Your Balance is below minimum"<<endl;
            cout<<""<<endl;
            return  true;
        }else
        {
            SavingbalanceBelowMin=false;
            cout <<"Your balance is Good ('_')"<<endl;
            cout<<""<<endl;
        }
        return  SavingbalanceBelowMin;
    }
public: void writeCheckForSaving(double amount,Account user)
    {
        if (SavingverifyBalance(user)) {
            double checkAmount = user.withDraw(amount);
            cout<< "I Authorize the Payment of $"<<checkAmount<<endl;
            cout << "Now your Balance is $"<< user.getBalance() - amount <<endl; //change (- amount)
            cout<<""<<endl;
        }
            else{
                    cout <<"Your balance is Good ('_')"<<endl;
                cout<<""<<endl;

       }
        
    }
public: void printAccountInfo(Account user)
    {
        if (SavingverifyBalance(user)) {
            cout <<"As of Today your Account Balance is $"<< user.getBalance()-SavingserviceCharge<<" Charged with Service fee"<<endl;
        }else{
            cout <<"As of Today your Account Balance is $"<< user.getBalance()<<endl;
        }
        
        cout<<"Your service charges is $"<< SavingserviceCharge<<endl;
        cout<<"Your Account Number is #"<<user.getAccountNumber()<<endl;
        cout<<"Your interestRate is $"<<retireiveInterestRateSaving()<<endl;
        cout<<""<<endl;
    }
    
};

int main() {
    // insert code here...
    Account awet=Account(109888,10);
    awet.accountRecipt();
   // CheckingAccount awetCheckingAccount=CheckingAccount(awet);
    SavingAccount awetSavingAccount=SavingAccount(awet);
    
//    awetCheckingAccount.printAccountInfo(awet);
//    //awetCheckingAccount.verifyBalance(awet);
//    awetCheckingAccount.writeCheck(100,awet);
//    awet.withDraw(50000);
    awetSavingAccount.SavingverifyBalance(awet);
    awetSavingAccount.printAccountInfo(awet);
    awetSavingAccount.writeCheckForSaving(100,awet);
    awet.withDraw(1000);
    
    return 0;
}

