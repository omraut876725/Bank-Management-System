#include<iostream>
#include"bank.h"
#include"types.h"
#include <fstream>
#include<cstring>
#include <stdio.h>
using namespace std;
uint count;
//copy the function from file to bank_holder class
Status Bank::copy_bank_holder(Bank *bank_holder)
{
  ifstream fptr("text.txt");
if (!fptr.is_open())
{
    cout << "Unable to open file" << endl;
    return e_failure;
}
  fptr>>count;
  //cout<<count<<endl;
   for(int i=0;i<count;i++)
   {
    fptr >> bank_holder[i].id;
        fptr >> bank_holder[i].name;
        fptr >> bank_holder[i].balance;
   }
    fptr.close();

return e_success;
}
 Status Bank::check_account_no(uint *no,Bank *bank_holder)
 {
  string account_no;
  cout<<"Enter the Account no"<<endl;
  cin>>account_no;
  for(int i=0;i<count;i++)
  {
    if (account_no == bank_holder[i].id)
    {
       *no=i;
       return e_success;
    }
  }
  return e_failure;
 }
  Status Bank:: save_details(Bank *bank_holder)
  {
     FILE *fptr;
     fptr=fopen("text.txt","w");
     if(fptr==NULL)
     {
      cout<<"file failed to  open"<<endl;
       return e_failure;
     }
     fprintf(fptr,"%d\n",count);
      for (int i = 0; i < count; i++)
    {
        fprintf(fptr, "%s ", bank_holder[i].id.c_str());
        fprintf(fptr, "%s ", bank_holder[i].name.c_str());
        fprintf(fptr, "%f\n", bank_holder[i].balance);
    }
    fclose(fptr);
    return e_success;

  }