#include<iostream>
#include<string.h>
using namespace std;
class book
{
 public:
 char *Title,*Author,*Publisher;
 int Price,Stock;
 static int suc_transaction; 
  static int unsuc_transaction;   
  book()
  {
   Title=new char[2];
   Author=new char[2];
   Publisher=new char[2];
   Price=0;
   Stock=0;
  }
 void accept();
 void display();
 int search(char str[20]);
 void purchase();
 static void fun() 
 {
  cout<<"\nNumber of sucessfull transctions="<<suc_transaction;
   cout<<"\nNumber of unsucessfull transctions="<<unsuc_transaction;
 }
};
int book::suc_transaction;   
int book::unsuc_transaction; 
void book::accept()
{
 cout<<"Enter the title of book:";
 cin>>Title;
  cout<<"Enter the author of book:";
 cin>>Author;
  cout<<"Enter the publisher of book:";
 cin>>Publisher;
  cout<<"Enter the Price of book:";
 cin>>Price;
  cout<<"Enter the stock of book:";
 cin>>Stock;
}
void book::display()
{
 cout<<"\n"<<Title<<"\t"<<Author<<"\t"<<Publisher<<"\t"<<Price<<"\t"<<Stock<<"\t"<<"\n";
}
int book::search(char str[20])
{
 if(strcmp(str,Title)==0)
  return 1;
 else
  return 0; 
}
void book::purchase()
{
 int count;
 cout<<"\nEnter Number of Books to buy:";
 cin>>count;
 if(count<=Stock)
 {
  Stock=Stock-count;
  cout<<"\nAmount:Rs."<<(Price*count);
  book::suc_transaction++;
 }
 else
 {
  cout<<"\nRequired Copies are not available.";
    book::unsuc_transaction++;
 }
}
int main()
{
 book b1[20];
 int n,i,ch,val;
 char str[20];


 do
 {
  cout<<"\n\n1.Insert\n2.Display\n3Search\n4.Purchase Book\n5.Modify\n6.Number of Sucessful Transaction\n7.Exit"<<"\n";
  
  cout<<"Enter your choice = ";
  cin>>ch;
  
  switch(ch)
  {
   case 1:
   		b1[n++].accept();
   		break;
   case 2:  		
   		cout<<"Book Details:"<<"\n";
   		cout<<"Title"<<"\t"<<"Author"<<"\t"<<"Publisher"<<"\t"<<"Price"<<"\t"<<"Stock"<<"\t";
   		for(i=0;i<n;i++)
   		{
   		 b1[i].display();
  		}
  		break;
   case 3:
   		cout<<"\nEnter the title of book:";
   		cin>>str;
   		for(i=0;i<n;i++)
   		{
   		 val=b1[i].search(str);
   		 if(val==1)
   		 {
   		  cout<<"\nBookFound Sucessfully";
   		  break;
   		 }
   		}
   		if(i==n)
   		{
   		 cout<<"\nThis Book is not in Stock.";
   		}
   		break;
   case 4:
   		cout<<"\nEnter the title of book:";
   		cin>>str;
   		for(i=0;i<n;i++)
   		{
   		 val=b1[i].search(str);
   		 if(val==1)
   		 {
   		  b1[i].purchase();
   		  break;
   		 }
   		}
   		if(i==n)
   		{
   		 cout<<"\nThis Book is notin Stock.";
   		}
   		break;
   case 5:
   		cout<<"\nEnter the title of book:";
   		cin>>str;
   		for(i=0;i<n;i++)
   		{
   		 val=b1[i].search(str);
   		 if(val==1)
   		 {
   		  cout<<"\nEnter modified data:";
   		  b1[i].accept();
   		  break;
   		 }
   		}
   		if(i==n)
   		{
   		 cout<<"\nThis Book is not in Stock.";
   		}
   		break;
   case 6:
   		book::fun();
   		break;
   case 7:
   		cout<<"EXIT";
   		break;
  }
 }while(ch<7);
 return 0;
}
