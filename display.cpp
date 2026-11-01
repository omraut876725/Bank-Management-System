#include<iostream>
#include"bank.h"
#include"types.h"
using namespace std;
 Status Bank:: display_bank_balance(Bank *bank_holder)
 {
   uint size=0;
   if(check_account_no(&size,bank_holder)==e_success)
   {
      cout<<"Available balance is : "<<bank_holder[size].balance<<endl;
      return e_success;
   }
   else
   {
    cout<<"Account not found"<<endl;
    return e_failure;
   }
return e_success;
 }