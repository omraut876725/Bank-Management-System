#include<iostream>
#include"types.h"
using namespace std;
#ifndef BANK
#define BANK

class Bank
{
    private: 
            string id;
             string name;
             double balance;
             
     public:
           Status copy_bank_holder(Bank *bank_holder);
           Status display_bank_balance(Bank *bank_holder);
           Status check_account_no(uint *no,Bank *bank_holder);
           Status deposit_money(Bank *bank_holder);
           Status withdraw_money(Bank *bank_holder);
           Status save_details(Bank *bank_holder);
};
#endif