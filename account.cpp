

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
        cout <<"You Deposited $"<<amount<<". Into You Checking Account"<<". Your current Balance is "<<getBalance()-amountWithdrawed<<endl;
        
    }
    public : void accountRecipt()
    {
        cout << "Your current Balance is $"<<Balance<<". And your Account Number is #"<<AccountNumber<<endl;
    }
    
    


};
class CheckingAccount : Account
{
    public : double interestRate;
    public :double minBalance;
    public :double serviceCharge=5;
    public :bool balanceBelowMin;
    
public: CheckingAccount(Account user) :Account(user.getAccountNumber(),user.getBalance())
    {
        setInterestRate(user);
        
    };
    
public: void setInterestRate(Account balance)
    {
        double IR=balance.getBalance();
        interestRate=IR*0.002*1;
    }
public: double retireiveInterestRate()
    {
        return interestRate;
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
public: void setServiceCharges(int serviceC)
    {
        serviceCharge=serviceC;
    }
public: double retireveServiceCharges()
    {
        return serviceCharge;
    }
public: void postInterest()
    {
        cout << interestRate<< endl;
    }
public: bool verifyBalance(Account balance)
    {
        balanceBelowMin=false;
        if (balance.getBalance()<minBalance) {
            balanceBelowMin=true;
            balance.getBalance()-serviceCharge;
            cout <<"ALERT!!! Your Balance is below minimum"<<endl;
            return true;
        }else
        {
            balanceBelowMin=false;
            cout <<"Your balance is Good ('_')"<<endl;
        }
        return  false;
    }
public: void writeCheck(double amount,Account user)
    {
        if (verifyBalance(user)) {
            double checkAmount=user.withDraw(amount);
            cout<< "I Authorize the Payment of $"<<checkAmount<<endl;
            cout << "Now your Balance is $"<< user.getBalance()<<endl;
        }else{
            cout <<"Your balance is Good ('_')"<<endl;
        }
        
    }
public: void printAccountInfo(Account user)
    {
        cout <<" As of Today your Account Balance is $"<<user.getBalance()<<".your service charges is -$"<< serviceCharge<<" Your Account Number is #"<<user.getAccountNumber()<<"Your interestRate is $"<<retireiveInterestRate()<<endl;
    }

};
class SavingAccount : Account
{
    public : double SavinginterestRate;
    public :double SavingminBalance;
    public :double SavingserviceCharge=5;
    public :bool SavingbalanceBelowMin;
    
public: SavingAccount(Account S): Account(S.getAccountNumber(),S.getBalance())
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
public: void setMinimumBalance(Account balance)
    {
        if (balance.getBalance()<=25) {
            SavingminBalance=balance.getBalance();
        }
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
public: bool SavingverifyBalance(Account balance)
    {
        SavingbalanceBelowMin=false;
        if (balance.getBalance()<SavingminBalance) {
            SavingbalanceBelowMin=true;
            balance.getBalance()-SavingserviceCharge;
            cout <<"ALERT!!! Your Balance is below minimum"<<endl;
            return  true;
        }else
        {
            SavingbalanceBelowMin=false;
            cout <<"Your balance is Good ('_')"<<endl;
        }
        return  SavingbalanceBelowMin;
    }
public: void writeCheckForSaving(double amount,Account user)
    {
        if (SavingverifyBalance(user)) {
            double checkAmount=user.withDraw(amount);
            cout<< "I Authorize the Payment of $"<<checkAmount<<endl;
            cout << "Now your Balance is $"<< user.getBalance()<<endl;
        }else{
            
        }
        
    }
public: void printAccountInfo(Account user)
    {
        cout <<" As of Today your Account Balance is $"<<user.getBalance()<<".your service charges is -$"<< SavingserviceCharge<<" Your Account Number is #"<<user.getAccountNumber()<<"Your interestRate is $"<<retireiveInterestRateSaving()<<endl;
    }
    
};

    int main() {
        // insert code here...
        Account awet=Account(3454,1000);
        awet.accountRecipt();
        
        CheckingAccount awetCheckingAccount=CheckingAccount(awet);
        
        SavingAccount awetSavingAccount=SavingAccount(awet);

        awetCheckingAccount.printAccountInfo(awet);
        awetCheckingAccount.writeCheck(100,awet);
        awet.withDraw(5000);
        
        
        
        return 0;
    }


