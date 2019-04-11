

#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;





class Account
{
public: string AccountNumber;
public: double Balance;
public: double amountWithdrawed;
public: Account(string AN,double B )
    {
        AccountNumber=AN;
        Balance=B;
        
    }
    
public: void setAccountNUmber(string A)
    {
        AccountNumber=A;
        
    }
public: double Transfer(double transferAmount)
    {
        double AmountTransfered;
        if (Balance>1 && transferAmount<Balance) {
            Balance-=transferAmount;
             AmountTransfered=transferAmount;
        }else
        {
            cout<<"Balance too Low to Transfer"<<endl;
            AmountTransfered=0;
        }
        Balance-=transferAmount;
        return AmountTransfered;
        
    }
public: string getAccountNumber()
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
        cout<<"*--------------------------------------------------------------------------------------------------------*"<<endl;
        cout<<"* You Deposited $"<<amount<<". Into You Checking Account"<<". Your current Balance is "<<getBalance()<<" *"<<endl;
        cout<<"*--------------------------------------------------------------------------------------------------------*"<<endl;
        
        
    }
    public : void accountRecipt()
    {
        cout<<"*---------------------------------------------------------------------------------------------*"<<endl;
        cout<<"* Your current Balance is $"<<getBalance()<<".And your Account Number is #"<<AccountNumber<<" *"<<endl;
        cout<<"*---------------------------------------------------------------------------------------------*"<<endl;
    }
    
    
    
    
};
class CheckingAccount : Account
{
    public : double interestRate;
    public :double minBalance=25;
    public :double serviceCharge;
    public :bool balanceBelowMin;
    public :double CheckingBalance=0;
    public :string CheckingAccountNumber;
    
public: CheckingAccount(Account user,double startingAmount) :Account(user.getAccountNumber(),user.getBalance())
    {
        
        CheckingBalance+=startingAmount;
        CheckingAccountNumber+=user.getAccountNumber()+"--Checking";
        interestRate=CheckingBalance*0.02*1;
        
    };
public: void Deposit_to_Checking(double amount)
    {
        CheckingBalance+=amount;
        cout<<"*--------------------------------------------------------------------------------------------------------*"<<endl;
        cout<<"* You Deposited $"<<amount<<". Into You Checking Account"<<". Your current Balance is "<<get_Checking_Balance()<<" *"<<endl;
        cout<<"*--------------------------------------------------------------------------------------------------------*"<<endl;
        
        
    }
    
public: void set_Interest_Rate(double IR)
    {
       
        interestRate=CheckingBalance*IR*1;
    }
public: string get_Checking_Acount_Number()
    {
        return CheckingAccountNumber;
    }
public: double withDraw_from_checking(double amount)
    {
        amountWithdrawed=amount;
        if (CheckingBalance >1 && amountWithdrawed<CheckingBalance) {
            CheckingBalance -=amountWithdrawed;
            
        }else{
            cout <<"ALERT!!!"<<endl;
            cout<<"*---------------------------------------*"<<endl;
            cout<<"* Your current Checking Balance  is low *"<<endl;
            cout<<"*---------------------------------------*"<<endl;
            
            
        }
        return  amountWithdrawed;
    }

public: double get_Checking_Balance()
    {
        return CheckingBalance;
    }
public: double retireive_Interest_Rate()
    {
        return interestRate;
    }
public: void set_Minimum_Balance()
    {
        if (CheckingBalance<=25) {
            minBalance=CheckingBalance;
        }
    }
public: double retireve_Minimum_Balance()
    {
        return minBalance;
    }
public: void set_Service_Charges()
    {
        serviceCharge=5;
        
    }
public: double retireve_Service_Charges()
    {
        return serviceCharge;
    }
public: void post_Checking_Interest()
    {
        CheckingBalance+=interestRate;
    }
public: bool verifyBalance()
    {
        balanceBelowMin=false;
        if (CheckingBalance<minBalance) {
            balanceBelowMin=true;
            CheckingBalance-=serviceCharge;
            cout<<"*---------------------------------------------------------*"<<endl;
            cout<<"* ALERT!!! Your Checking Account Balance is below minimum *"<<endl;
            cout<<"*---------------------------------------------------------*"<<endl;
            
            return true;
        }else
        {
            balanceBelowMin=false;
            cout <<"Your Checking balance is Good ('_')"<<endl;
        }
        return  false;
    }
public: void writeCheck(double amount,Account user)
    {
        if (verifyBalance()!=true) {
            double checkAmount=user.withDraw(amount);
            cout<< "I Authorize the Payment of $"<<checkAmount<<endl;
            cout << "Now your Balance is $"<< user.getBalance()<<endl;
            cout<<"*-------------------------------------------*"<<endl;
            cout<<"* I Authorize the Payment of $"<<checkAmount<<endl;
            cout<<"* Now your Balance is $"<< user.getBalance()<<endl;
            cout<<"*-------------------------------------------*"<<endl;
        }else{
            cout <<"Your balance is Good ('_')"<<endl;
        }
        
    }
public: void printCheckingAccountInfo()
    {
        cout <<" As of Today your Checking Account Balance is $"<<get_Checking_Balance()<<". Your Service charges is -$"<< serviceCharge<<" Your Account Number is #"<<CheckingAccountNumber<<"  Your interestRate is $"<<retireive_Interest_Rate()<<endl;
    }
    
    
};
class SavingAccount : Account
{
    public : double SavinginterestRate;
    public :double SavingminBalance=25;
    public :double SavingserviceCharge=5;
    public :bool SavingbalanceBelowMin;
    public :string SavingAccountNumber;
    public :double SavingBalance=0;
    
public: SavingAccount(Account S,double starting_Amount): Account(S.getAccountNumber(),S.getBalance())
    {
        setInterestRateSaving();
        SavingBalance+=starting_Amount;
        SavinginterestRate=SavingBalance*0.002*1;
        SavingAccountNumber=S.getAccountNumber()+"--Saving";

        
        
    };
public: void Deposit_to_Saving(double amount)
    {
        SavingBalance+=amount;
        cout<<"*--------------------------------------------------------------------------------------------------------*"<<endl;
        cout<<"* You Deposited $"<<amount<<". Into You Checking Account"<<". Your current Balance is "<<get_Saving_Balance()<<" *"<<endl;
        cout<<"*--------------------------------------------------------------------------------------------------------*"<<endl;
        
        
    }
public: string  getSavingAccountNUmber()
    {
        return SavingAccountNumber;
    }
public: double get_Saving_Service_Charges()
    {
        return SavingserviceCharge;
    }
    
public: double get_Saving_interset_rate()
    {
        return SavinginterestRate;
    }
public: double get_Saving_min_Balance()
    {
        return SavingminBalance;
    }
public: double withDraw_from_Saving(double amount)
    {
        amountWithdrawed=amount;
        if (SavingBalance >1 && amountWithdrawed<SavingBalance && SavingBalance>SavingminBalance) {
            SavingBalance -=amountWithdrawed;
            
        }else{
            cout <<"ALERT!!!"<<endl;
            cout<<"*---------------------------------------*"<<endl;
            cout<<"* Your current Saving Balance  is low *"<<endl;
            cout<<"*---------------------------------------*"<<endl;
            
            
        }
        return  amountWithdrawed;
    }
    
public: void setInterestRateSaving()
    {
        SavinginterestRate=SavingBalance*0.002*1;
    }

public: void setMinimumBalance(double minbalance)
    {
        
            SavingminBalance=minbalance;
        
    }

public: void setServiceCharges(int serviceC)
    {
        SavingserviceCharge=serviceC;
    }

public: void post_Saving_Interest()
    {
        SavingBalance+=SavinginterestRate;
    }
public: bool SavingverifyBalance()
    {
        SavingbalanceBelowMin=false;
        if (SavingBalance<SavingminBalance) {
            SavingbalanceBelowMin=true;
            cout <<"ALERT!!! Your Saving Account Balance is below minimum"<<endl;
            return  true;
        }else
        {
            SavingbalanceBelowMin=false;
            cout <<"Your Saving balance is Good ('_')"<<endl;
        }
        return  SavingbalanceBelowMin;
    }
public: void writeCheckForSaving(double amount,Account user)
    {
        if (SavingverifyBalance()) {
            double checkAmount=user.withDraw(amount);
            cout<< "I Authorize the Payment of $"<<checkAmount<<endl;
            cout << "Now your Balance is $"<< user.getBalance()<<endl;
        }else{
            
        }
        
    }
public: double get_Saving_Balance()
    {
        return SavingBalance;
    }
public: void printSavingAccountInfo()
    {
        cout <<" As of Today your Saving Account Balance is $"<<get_Saving_Balance()<<". Your service charges is -$"<<SavingserviceCharge<<" Your Account Number is #"<<getSavingAccountNUmber()<<"  Your interestRate is  $"<<get_Saving_interset_rate()<<endl;
    }
    
};

int  main() {
    
    string accountNumber;
    double startingBalance;
    int inputValue;
    cout<<"Enter Account Number: "<<endl;
    cin>>accountNumber;
    cout<<"Enter Starting Balance: "<<endl;
    cin>>startingBalance;

    Account user_Created_Account=Account(accountNumber,startingBalance);
    CheckingAccount use_Checking_account=CheckingAccount(user_Created_Account,user_Created_Account.getBalance());
    user_Created_Account.Balance-=user_Created_Account.getBalance();
    
    
    SavingAccount user_created_Saving_account=SavingAccount(user_Created_Account,0);
    if (use_Checking_account.verifyBalance()) {
        use_Checking_account.CheckingBalance-=use_Checking_account.retireve_Service_Charges();
        cout<<" You will get  charged Service Charge Because your Checking Account Balance was below minimum"<<endl;

    }
    
    cout<<"Do you want to procced to Menu [0/1]."<<endl;
    
    cin>>inputValue;
    if (inputValue==0) {
        if (user_created_Saving_account.get_Saving_Balance()>0) {
            user_created_Saving_account.printSavingAccountInfo();
          
        }else{
            use_Checking_account.printCheckingAccountInfo();
        }
        cout<<" Type [1] to go to the Menu! "<<endl;
        cin>>inputValue;
        
    }
    while(inputValue ==1 ) {
        cout<<"Menu"<<endl;
        cout<<" (1):Create Saving Account (2):Deposit (3):WithDraw\n (4):Get Account Number (5):Go to Saving-Account (6):Go to Checking-Account"<<endl;
        cout<<"Type One of Those Numbers to take Action"<<endl;
        cin>>inputValue;
        
        
                switch (inputValue) {
                    case 1:
                        user_created_Saving_account=SavingAccount(user_Created_Account,use_Checking_account.withDraw_from_checking(use_Checking_account.get_Checking_Balance()/5));
                        if (user_created_Saving_account.SavingverifyBalance()) {
                            user_created_Saving_account.SavingBalance-=user_created_Saving_account.get_Saving_Service_Charges();
                            cout<<" You were charged Service Charge Because your Saving Account Balance was below minimum"<<endl;
                        }
                        cout<<"<><><><>-<><><><>-Congratulation!! You Created a Saving Account-<><><><>-<><><><>"<<endl;
                        user_created_Saving_account.printSavingAccountInfo();
                        cout<<""<<endl;
                        cout<<" Type [1] to go to the Menu! "<<endl;
                        cin>>inputValue;
                        
                        break;
                    case 2:
                        double amount;
                        int deposit_code;
                        cout<<"Type How much you want to Deposit"<<endl;
                        cin>>amount;
                        cout<<" Type 1: To Deposit to CheckingAccount or Type 2: To Deposit to Saving Account"<<endl;
                        cin>>deposit_code;
                        switch (deposit_code) {
                            case 1:
                                use_Checking_account.CheckingBalance+=amount;
                                use_Checking_account.printCheckingAccountInfo();
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                                case 2:
                                if (user_created_Saving_account.get_Saving_Balance()>0) {
                                    user_created_Saving_account.SavingBalance+=amount;
                                    user_created_Saving_account.printSavingAccountInfo();
                                    cout<<" Type [1] to go to the Menu! "<<endl;
                                    cin>>inputValue;
                                    
                                }else{
                                    cout<<"You Dont have Saving Account Type 1 To go to Menu To create Saving Account"<<endl;
                                    cin>>inputValue;
                                }
                                
                                
                                
                                break;
                                default:
                                cout<<"Invalid Input"<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                        }
                        break;
                        
                        case 3:
                        
                        double amount_to_withdraw;
                        int withdraw_code;
                        cout<<"Type How much you want to Withdraw"<<endl;
                        cin>>amount_to_withdraw;
                        cout<<" Type 1: To Withdraw from CheckingAccount or Type 2: To Withdraw from Saving Account"<<endl;
                        cin>>withdraw_code;
                        switch (withdraw_code) {
                            case 1:
                                use_Checking_account.withDraw_from_checking(amount_to_withdraw);
                                use_Checking_account.printCheckingAccountInfo();
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                            case 2:
                                if (user_created_Saving_account.get_Saving_Balance()>0) {
                                    user_created_Saving_account.withDraw_from_Saving(amount_to_withdraw);
                                    user_created_Saving_account.printSavingAccountInfo();
                                    cout<<" Type [1] to go to the Menu! "<<endl;
                                    cin>>inputValue;
                                    
                                }else{
                                    cout<<"You Dont have Saving Account Type 1 To go to Menu To create Saving Account"<<endl;
                                    cin>>inputValue;
                                }
                                
                                break;
                                
                                default:
                                cout<<"Invalid Input"<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>withdraw_code;
                                break;
                        }
                        
                        break;
                        
                        case 4:
                        int account_no_code;
                        cout<<"To get Account Number of Checking Account Type [1] or Type [0] to get Account Number of Saving Account"<<endl;
                        cin>>account_no_code;
                    
                        switch (account_no_code) {
                            case 1:
                                cout<< " Checking Account Number is: "<<use_Checking_account.get_Checking_Acount_Number()<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                            case 0:
                                if (user_created_Saving_account.get_Saving_Balance()>0) {
                                    cout<< " Saving  Account Number is: "<<user_created_Saving_account.getSavingAccountNUmber() <<endl;
                                    cout<<" Type [1] to go to the Menu! "<<endl;
                                    cin>>inputValue;

                                }else{
                                    cout<<"You Dont have Saving Account Type 1 To go to Menu To create Saving Account"<<endl;
                                    cin>>inputValue;
                                   /* do {
                                        cout<<"Invalid Input"<<endl;
                                        cout<<" Type [1] to go to the Menu! "<<endl;
                                        cin>>inputValue;
                                    } while (inputValue!=1);
                                    if (inputValue==1) {
                                        
                                    }
                                    */
                                }
                                
                                break;
                                
                                
                            default:
                                cout<<"Invalid Input"<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>account_no_code;
                            break;
                        }
                        
                        break;
                        
                        case 5:
                        int saving_nav_code;
                        double saving_withdraw_amount;
                        
                        if (user_created_Saving_account.get_Saving_Balance()==0) {
                            string yes_no;
                            cout<<"You Dont have Saving Account Do you want to create one [y/n] ?"<<endl;
                            cin>>yes_no;
                            if (yes_no!="n") {
                                user_created_Saving_account=SavingAccount(user_Created_Account,use_Checking_account.withDraw_from_checking(use_Checking_account.get_Checking_Balance()/5));
                                cout<<"Congratulation you just created Saving Account"<<endl;
                            }else{
                                cout<<"Sorry Invalid Input"<<endl;
                                cin>>inputValue;
                            
                            }
                            }
                        cout<<"Saving Menu"<<endl;
                        cout<<" (1):Write-Check (2):Get Saving Balance (3):Get-Minimum-Balance\n (4):Get-Interset-Rate (5):Get-Service-Charges (6):Print Account Recipt "<<endl;
                        cin>>saving_nav_code;
                        switch (saving_nav_code) {
                            case 1:
                                cout<<"How much Do you want To withdraw?"<<endl;
                                cin>>saving_withdraw_amount;
                                user_created_Saving_account.SavingBalance-=user_created_Saving_account.withDraw_from_Saving(saving_withdraw_amount);
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                                
                            case 2:
                                cout<<" Your current Saving Balance is: $"<<user_created_Saving_account.get_Saving_Balance()<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                            case 3:
                                cout<<" Your current Saving Minimum Balance is: $"<<user_created_Saving_account.get_Saving_min_Balance()<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                            case 4:
                                cout<<" Your current Saving Interest Rate is: $"<<user_created_Saving_account.get_Saving_interset_rate()<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                            case 5:
                                cout<<" Your current Saving Service Charges is: $"<<user_created_Saving_account.get_Saving_Service_Charges()<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                                
                            case 6:
                                user_created_Saving_account.printSavingAccountInfo();
                                cin>>inputValue;
                                break;
                            default:
                                cout<<"Invalid Input Ty Again"<<endl;
                                cin>>saving_nav_code;
                                break;
                        }
                        
                        
                        
                        
                        break;
                        
                        case 6:
                        int checking_nav_code;
                        double checking_withdraw_amount;
                        cout<<"Checking Menu"<<endl;
                        cout<<" 1:Write-Check\n 2:Get Checking Balance\n 3:Get-Minimum-Balance\n 4:Get-Interset-Rate\n 5:Get-Service-Charges\n 6:Print Account Recipt\n "<<endl;
                        cin>>checking_nav_code;
                        switch (checking_nav_code) {
                            case 1:
                                cout<<"How much Do you want To withdraw?"<<endl;
                                cin>>checking_withdraw_amount;
                                use_Checking_account.withDraw_from_checking(checking_withdraw_amount);
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                                
                            case 2:
                                cout<<" Your current Checking Balance is: $"<<use_Checking_account.get_Checking_Balance()<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                            case 3:
                                cout<<" Your current Checking Minimum Balance is: $"<<use_Checking_account.retireve_Minimum_Balance()<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                
                                break;
                            case 4:
                                cout<<" Your current Checking Interest Rate is: $"<<use_Checking_account.retireive_Interest_Rate()<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                            case 5:
                                cout<<" Your current Checking Service Charges is: $"<<use_Checking_account.retireve_Service_Charges()<<endl;
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                                
                            case 6:
                                use_Checking_account.printCheckingAccountInfo();
                                cout<<" Type [1] to go to the Menu! "<<endl;
                                cin>>inputValue;
                                break;
                            default:
                                cout<<"Invalid Input Try Again"<<endl;
                                cin>>checking_nav_code;
                                break;
                        }
                        
               
        
        
        
        
                        break;
                        
                    default:
                        
                        break;
                }
                
                
            
    

    
    
    
    
        
    
}

}
