The above project is prepared with the objective of aiding in the management of books in a library.
It allows the user to make a file which stores the details of the various books present in the library. 
It also allows the user to store details of the various members of the library.
It provides the user with the option to access and/or delete the details of any book or member immediately. 
Every member and book has been provided with a special identification number in order to protect the privacy of each entity during borrowing and returning process.
In our project, we use object oriented programming and have created two classes BOOK and MEMBER with following descriptions:
BOOK : stores details of each book using 
       data members:
       1.bno: It stores the unique identification number of  the book.
       2.title: It stores name of the book.
       3.author: It stores the name of the author of the book.
       4.publisher:It stores the name of the publisher of the book.
       5.price: It stores the price of the book.
       Member functions:
       1. add_book(): It inputs the values of various data members.
       2.display_book():It displays the value of various data members.
       3.rbno(): It returns the value of the bno.
       4.issue() : It facilitates the issuing of the book.
       5.return() : It facilitates the returning of the book.
MEMBER : stores details of each member 
         data members
       1.mno: It stores the identification number of the member.                
       2.name: It stores name of the member.
       3.email: It stores the email id of the member.
       4.mobile: It stores the mobile number of the member.
       Member functions:
       1. add_member(): It inputs the values of various data members.
       2.display_member():It displays the various data members.
       3.rmno(): It returns the value of the mno.
       4.issue() : It facilitates the issuing of the book.
       5.return() : It facilitates the returning of the book.                       

Functions used in the program :
void GET_BOOK() :to accept details about an object of the class BOOK
In order to obtain information about the books present in the  library.

void GET_MEMBER()to accept details about an object of the class MEMBER
In order to obtain information about the membership present in the  library.

void SHOW_BOOK() to display the details of a book by searching from
the binary file on the basis of the book number(bno)          of the the book.

void SHOW_MEMBER()to display the details of a member by searching on                
                  the basis of the membenumber(Mno)of the the book.
int DELETE_BOOK() to delete a book from the binary file by searching 
                  On the basis of the book number of the book.

void ISSUE_BOOK() to issue a book .Function asks for the book number 
                  Of the book and the member of the member to whom the 
                  Book is issued.

void RETURN_BOOK()to return  a book.Function asks for the book number 
                  Of the book and the member number of the member by 
                  Whom the book is returned. 
