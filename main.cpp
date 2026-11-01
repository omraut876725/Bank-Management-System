```c
/*
==============================================================================
   Project     : MP3 Tag Reader and Editor (ID3v2)
   Name        : Om Raut
   Date        : 15-Sept-2026
   Batch Id    : 26019f_009
   Language    : C++
   Files       : main.c, view.c, edit.c, read_and_validate.c,
                 mp3.h, types.h, makefile
==============================================================================

 DESCRIPTION
 -----------
 This is a command-line-based MP3 Tag Reader and Editor application
 developed to read, display, and modify metadata information stored
 in MP3 audio files using the ID3v2 tagging format.

 The metadata contains information about the audio file, such as the
 song title, artist name, album name, release year, music genre, and
 comments. The program allows the user to view existing tag information
 and edit selected metadata fields without intentionally modifying
 the actual audio content.

 FILE FORMAT
 -----------
 MP3 files may contain an ID3v2 tag at the beginning of the file.
 The tag consists of a header followed by multiple frames. Each frame
 stores a particular type of metadata along with its frame identifier,
 size, flags, and data.

 The ID3v2 header contains the identifier "ID3", version information,
 flags, and tag size. The tag size is stored as a synchsafe integer,
 which must be decoded to determine the actual size of the tag.

 Common frame identifiers include:
 TIT2 : Song title
 TPE1 : Lead artist or performer
 TALB : Album name
 TYER : Year in ID3v2.3
 TCON : Music genre or content type
 COMM : Comments

 FEATURES
 --------
 1. View MP3 tags : Reads and displays the available metadata from
                     the specified MP3 file.

 2. Edit title    : Updates the song title stored in the TIT2 frame.

 3. Edit artist   : Updates the artist name stored in the TPE1 frame.

 4. Edit album    : Updates the album name stored in the TALB frame.

 5. Edit year     : Updates the year information stored in the
                     supported year frame.

 6. Edit genre    : Updates the music genre stored in the TCON frame.

 7. Edit comments : Updates the comment information stored in the
                     COMM frame, if supported by the implementation.

 8. Preserve data : Copies the remaining MP3 data to the output file
                     while updating the metadata, as implemented.

 COMMAND-LINE USAGE
 ------------------
 View MP3 tags:
     ./a.out -v song.mp3

 Edit song title:
     ./a.out -e -t "New Title" song.mp3

 Edit artist name:
     ./a.out -e -a "New Artist" song.mp3

 Edit album name:
     ./a.out -e -A "New Album" song.mp3

 Edit release year:
     ./a.out -e -y "2026" song.mp3

*/

#include<iostream>
#include"bank.h"
#include"types.h"
using namespace std;


int main()
{
  Bank bank_holder[10];
if(bank_holder->copy_bank_holder(bank_holder)==e_success)
{
 // cout<<"copy successfull"<<endl;
}

  do
  {
    cout<<"-----------------------------------------------------\n";
    cout<<"-----------------------------------------------------\n";
   cout<<"--------------PAISA VASOOL BANK----------------------\n";
    cout<<"------------........-----------------------------------------\n";
    

    cout<<"Enter Choice"<<endl;
    cout<<"1.Display balance"<<endl;
    cout<<"2.Deposit balance"<<endl;
    cout<<"3.withdraw amout"<<endl;
    cout<<"4.do you want to Exit\n";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
               {
                 //cout<<"display balance is selected\n";
                bank_holder-> display_bank_balance(bank_holder);
                 break;
               }
        case 2:
               {
                // cout<<"deposit balance is selected\n";
                bank_holder-> deposit_money(bank_holder);
                 break;
               }
       case 3:
               {
                // cout<<"withdraw balance is selected\n";
                bank_holder->withdraw_money(bank_holder);
                 break;
               }
        case 4:
               {
               if(bank_holder->save_details(bank_holder)==e_success)
               {  cout<<"Thank you"<<endl;
                  return 0;
               }
               else
               {
                cout<<"error in saving"<<endl;
               }
                 break;
               }
        default :
               {
                 cout<<"Enter valid Choice\n";
                 return 0;
                 
               }
    }
    
    
  }while(1);
}