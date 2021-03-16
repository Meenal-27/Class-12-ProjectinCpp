//header files

#include <fstream.h>
#include <conio.h>
#include <stdio.h>

//class  1
class BOOK
{
     int bno;
     char title[50];
     char author[20];
     char publisher[20];
     float price;
     int mno;
     public:
     BOOK()  
     { mno=0;}                                          //constructor
     void add_book()               // to input the details of the book 
     {
         cout<<"Book no.    :";cin>>bno; 
         cout<<"Book title  :";gets(title);  
         cout<<"Author      :";gets(author);         
         cout<<"Publisher   :";gets(publisher);          
     }
     void display_book()           //to display the details of a book
    {
        cout<<"Book no.       : "<<bno<<endl;
        cout<<"Book title     : "<<title<<endl;
        cout<<"Book author    : "<<author<<endl;
        cout<<"Book publisher : "<<publisher<<endl;
  }

  int rbno()                                 //to return the bno.
  { return bno;}

  int issue(int tmno)
  {
       if(mno==0)
       {
	  mno=tmno;
	  return 1;
       }
       else
         return 0;
  } 

  int Return(int tmno)
  {
       if(mno==tmno)
       {
         mno=0;
         return 1;
       }
       else
       return 0;
  }
};


//class  2
class MEMBER
{
     int mno;
     char name[20];
     char mobile[20];
     char email[20];
     int bno;
 public:
     MEMBER()                                       //constructor
     { bno=0;}
   void add_member()                            //to add member
   {
       cout<<"Member no.  :";cin>>mno;
        cout<<"Member name :";gets(name);
       cout<<"Member's mobile number"<<endl;
       gets(mobile);
       cout<<"Member's email address"<<endl;
       gets(email);
   }

     void display_member()                //to display member
  {
      cout<<"Member no.    : "<<mno<<endl;
      cout<<"Member name   : "<<name<<endl;
      cout<<"Mobile no     : "<<mobile<<endl;
      cout<<"Email address : "<<email<<endl;
  }
  int rmno()                             //to return member number
  {return mno;}

  int issue(int tbno)
  {
      if(bno==0)
      {
          bno=tbno;
          return 1;
      }
      else return 0;
  }
  int Return(int tbno)
  {
       if(bno==tbno)
       {
          bno=0;
          return 1;
       }
       else
          return 0;
  }
};

void GET_BOOK()                         //to add book to binary file
{
    fstream f1;
    f1.open("BOOK.DAT",ios::binary|ios::out);
    BOOK B;
    char ans;
    int num=1;
    do
    {
       cout<<"ENTRY "<<num<<endl;
       B.add_book();
       f1.write((char*)&B,sizeof(B));
       cout<<"Want to write more(y/n)?"<<endl;
       cin>>ans;
       num++;
   }
   while(ans=='y');
   f1.close();
   }

void GET_MEMBER()               //to add member to the binary file
{
    fstream f2;
    f2.open("MEMBER.DAT",ios::binary|ios::out);
    MEMBER M;
    char ans;
    int num=1;
    do
    {
        cout<<"ENTRY "<<num<<endl;
        M.add_member();
        f2.write((char*)&M,sizeof(M));
        cout<<"Want to write more(y/n)?"<<endl;
        cin>>ans;
        num++;
    }
    while(ans=='y');
    f2.close();
}

void SHOW_BOOK()               //to display the details of a book 
{
       fstream f1;
       f1.open("BOOK.DAT",ios::binary|ios::in|ios::out);
       BOOK B;
       int bnos;
       cout<<"Give the book number of the book to be displayed"<<endl;
       cin>>bnos;
       while(f1.read((char*)&B,sizeof(B)))
      {
          if(B.rbno()==bnos)
          B.display_book();
      }
      f1.close();
}

void SHOW_MEMBER()                  //to display details of a member
{
     fstream f2;
     f2.open("MEMBER.DAT",ios::binary|ios::in|ios::out);
     MEMBER M;int mnos;
     cout<<"Give the member number of the member to be
     displayed"<<endl;
     cin>>mnos;
     while(f2.read((char*)&M,sizeof(M)))
     {
        if(M.rmno()==mnos)
        M.display_member();
     }
     f2.close();
}

int DELETE_BOOK()             //to delete a book from the binary file
{
     fstream f1,f3;
     f1.open("BOOK.DAT",ios::binary|ios::in);
     f3.open("TEMP.DAT",ios::binary|ios::out);
     BOOK B;
     int bnod,DEL=0;
     cout<<"Bno of the book to be deleted"<<endl;
     cin>>bnod;
     while(f1.read((char*)&B,sizeof(B)))
      {
            if(B.rbno()!=bnod)
            f3.write((char*)&B,sizeof(B));
            else
            DEL++;
     }  
    f1.close();
    f3.close();
    return DEL;
}

void ISSUE_BOOK()                              //to issue a book
{
     fstream f1,f2;
     f1.open("BOOK.DAT",ios::binary|ios::in|ios::out);
     f2.open("MEMBER.DAT",ios::binary|ios::in|ios::out);
     MEMBER M;
     BOOK B;
     int ibno,imno,b=0,m=0;
     cout<<"Enter the book number of the book ";
     cin>>ibno;
     cout<<"Give the member number of the member ";
     cin>>imno;
     while(!b && f1.read((char*)&B,sizeof(B)))
     { 
         if(B.rbno()==ibno && B.issue(imno))
         b=1;
     }
     if(b)
     {
          while(!m && f2.read((char*)&M,sizeof(M)))
          {         
               if(M.rmno()==imno && M.issue(ibno))
	           m=1;
          }
          if(m)
          {
                f1.seekp(f1.tellg()-sizeof(B));
                f2.seekp(f2.tellg()-sizeof(M));
                f1.write((char*)&B,sizeof(B));
                f2.write((char*)&M,sizeof(M));
                cout<<ibno<<" has been issued to "<<imno<<endl;
          }
          else
              cout<<"Sorry! Member not found or already issued            book"<<endl;
     }
     else
       cout<<"Sorry! Book not found or already issued"<<endl;
  
   f1.close();
   f2.close();
}
void RETURN_BOOK()                               //to return book
{
       fstream f1,f2;
       f1.open("BOOK.DAT",ios::binary|ios::in|ios::out);
       f2.open("MEMBER.DAT",ios::binary|ios::in|ios::out);
       MEMBER M;
       BOOK B;
       int Rbno,Rmno,Rb=0,Rm=0;
       cout<<"Enter the book number of the book ";
       cin>>Rbno;
       cout<<"Give the member number of the member ";
       cin>>Rmno;
       while(!Rb && f1.read((char*)&B,sizeof(B)))
       { 
            if(B.rbno()==Rbno && B.Return(Rmno))
            Rb=1;
       }
        if(Rb)
       {
           while(!Rm && f2.read((char*)&M,sizeof(M)))
           {
               if(M.rmno()==Rmno && M.Return(Rbno))
	   Rm=1;
           }
          if(Rm)
          {
              f1.seekp(f1.tellg()-sizeof(B));
              f2.seekp(f2.tellg()-sizeof(M));
              f1.write((char*)&B,sizeof(B));
              f2.write((char*)&M,sizeof(M));
              cout<<Rbno<<" has been returned by "<<Rmno<<endl;
          }
          else
              cout<<"sorry!Member already has a book/Member does not                                                                                                    exist"<<endl;
       }
      else
          cout<<"sorry!Book already issued/Book does not exist"<<endl;
  
   f1.close();
   f2.close();
}

void main()
{
     clrscr();

     int p;
     char ch;
     do
     {
          cout<<"the options available are"<<endl;
          cout<<"1.Get a book"<<endl;
          cout<<"2.Display a book"<<endl;
          cout<<"3.Add a member"<<endl;
          cout<<"4.Display a member"<<endl;
          cout<<"5.Delete a book "<<endl;
          cout<<"6.Issue a book"<<endl;
          cout<<"7.Return a book"<<endl;


         cout<<"please enter the choice ";
         cin>>p;

         switch(p)
         {
              case 1:GET_BOOK();break;
              case 2:SHOW_BOOK();break;
              case 3:GET_MEMBER();break;
              case 4:SHOW_MEMBER();break;
              case 5:
              {
	         if(DELETE_BOOK());
	         {
	             remove("BOOK.DAT");
	             rename("TEMP.DAT","BOOK.DAT");
	             cout<<"The book has been deleted"<<endl;
	         }
	    }
	    break;
               case 6:ISSUE_BOOK();break;
               case 7:RETURN_BOOK();break;
               default:cout<<"invalid option";break;
         };
         cout<<"WANT TO PERFORM ANY OTHER OPERATION(Y/N)?"<<endl;
         cin>>ch;
     }
     while(ch=='Y');
     getch();
}
