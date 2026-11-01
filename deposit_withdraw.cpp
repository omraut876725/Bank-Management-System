#include<iostream>
#include"bank.h"
#include"types.h"
using namespace std;
Status Bank::deposit_money(Bank *bank_holder)
{
    uint size=0;
   if(check_account_no(&size,bank_holder)==e_success)
   {
    double deposit_amount;
    cout<<"Enter deposit amount"<<endl;
    cin>>deposit_amount;
    if (deposit_amount <= 0)
       {
         cout << "Invalid deposit amount" << endl;
        return e_failure;
      }
    bank_holder[size].balance=bank_holder[size].balance+deposit_amount;
      return e_success;
   }
   else
   {
    cout<<"Account not found"<<endl;
    return e_failure;
   }
   return e_success;
}
Status Bank::withdraw_money(Bank *bank_holder)
{
   uint size=0;
   if(check_account_no(&size,bank_holder)==e_success)
   {
    double withdraw_amount;
    cout<<"Enter withdrawl amount"<<endl;
    cin>>withdraw_amount;
    if (withdraw_amount <= 0)
      {
           cout << "Invalid withdrawal amount" << endl;
        return e_failure;
       }

       if (withdraw_amount > bank_holder[size].balance)
       {
            cout << "Insufficient balance" << endl;
             return e_failure;
        }

       bank_holder[size].balance -= withdraw_amount;
       return e_success;
   }
   else
   {
    cout<<"Account not found"<<endl;
     return e_failure;
   }
   return e_success;
}
