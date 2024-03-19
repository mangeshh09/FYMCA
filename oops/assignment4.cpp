//NAME : MANGESH A. GHADWAJE
//ROLL NO:24
//BATCH : B2
//COURSE: OOPs PRACTICAL
//
//Assginment No. 3
//
//Problem Statment: Design a class ‘Complex ‘with data members for real and imaginary part.
//Provide default and parameterized constructors. Write a program to perform
//arithmetic operations of two complex numbers using operator overloading.
//i. Addition and subtraction using friend functions
//ii. Multiplication and division using member functions.
//
//
//
//CODE:

#include<iostream>
using namespace std;
class Complex
{
 private:
  float real,img;
 public:
  Complex()
  {
   real=0;
   img=0;
  }
  void accept()
  {
   cout<<"Enter the complex number:"<<"\n";
   cout<<"Real:";
   cin>>real;
   cout<<"Imaginary:";
   cin>>img;
  }
  void display()
  {
   cout<<"complex number is:";
   cout<<real<<"+"<<img<<"i"<<"\n";
  }
  Complex(float a,float b)
  {
   real=a;
   img=b;
  }
  friend Complex operator +(Complex c1,Complex c2)
  {
   c1.real=c1.real+c2.real;
   c1.img=c1.img+c2.img;
   return c1;
  }

  friend Complex operator -(Complex c1,Complex c2)
  {
   c1.real=c1.real-c2.real;
   c1.img=c1.img-c2.img;
   return c1;
  }
  Complex operator *(Complex c2);
  Complex operator /(Complex c2);
};
Complex Complex::operator *(Complex c2)
{
 Complex c3;
 c3.real=(real*c2.real)-(img*c2.img);
 c3.img=(real*c2.img)+(img*c2.real);
 return c3;
}
Complex Complex::operator /(Complex c2)
{
 Complex c3;
 c3.real=((real*c2.real)+(img*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
 c3.img=((real*c2.img)+(img*c2.real))/((c2.real*c2.real)+(c2.img*c2.img));
 return c3;
}
int main()
{
 int ch;
 Complex c3;		
 Complex c4(4,5);		
 
 Complex c5;
 c5.accept();
 cout<<"1st";
 c4.display();
 cout<<"\n";
 cout<<"2nd";
 c5.display();
 cout<<"\n";

 
 do
 {
 cout<<"\n"<<"Enter your choice:";
 cout<<"\n1.Addition"<<"\n"<<"2.Substraction"<<"\n"<<"3.Multiplication"<<"\n"<<"4.Division"<<"\n5.Exit"<<"\n";
 cin>>ch;
 switch(ch)
 {
  case 1: 	cout<<"Addition:";
 		//c3=c4+c5;
 		c3=operator+(c4,c5);
 		c3.display();
 		cout<<"\n";
 		break;
  case 2:   cout<<"Substraction:";
		// c3=c4-c5;
 		c3=operator-(c4,c5);
 		c3.display();
		cout<<"\n";
		break;
  case 3:   cout<<"Multication:";
 		c3=c4*c5;
 		//c3=c4.operator*(c5);
 		c3.display();
 		cout<<"\n";
		break;
  case 4:	cout<<"Division:";
		// c3=c4/c5;
 		c3=c4.operator/(c5);
 		c3.display();
 		cout<<"\n";
		break;
	case 5:
			break;	
  default:
 		cout<<"enter invalid choice";
 }
 }while(ch<=4);
 return 0;
}


//
//OUTPUT:
//
//Enter the complex number:
//Real:2
//Imaginary:5
//1stcomplex number is:4+5i
//
//2ndcomplex number is:2+5i
//
//
//Enter your choice:
//1.Addition
//2.Substraction
//3.Multiplication
//4.Division
//5.Exit
//1
//Addition:complex number is:6+10i
//
//
//Enter your choice:
//1.Addition
//2.Substraction
//3.Multiplication
//4.Division
//5.Exit
//2
//Substraction:complex number is:2+0i
//
//
//Enter your choice:
//1.Addition
//2.Substraction
//3.Multiplication
//4.Division
//5.Exit
//3
//Multication:complex number is:-17+30i
//
//
//Enter your choice:
//1.Addition
//2.Substraction
//3.Multiplication
//4.Division
//5.Exit
//4
//Division:complex number is:1.13793+1.03448i
//
//
//Enter your choice:
//1.Addition
//2.Substraction
//3.Multiplication
//4.Division
//5.Exit
//5

