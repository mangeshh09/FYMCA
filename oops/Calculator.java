import java.util.*;

class Factorial{
static double factorial(double n)
{
if(n==0)
return 1;
else
return(n*factorial(n-1));
}
}
public class Calculator
{
 public static void main(String[] args)
{
   Factorial f=new Factorial();
   char op;
   double num1, num2, result;
  Scanner sc=new Scanner(System.in);

  System.out.println("Enter first number: ");
  num1 =sc.nextDouble();

   System.out.println("Enter the operator: ('+','-','*','/','!')");
  op =sc.next().charAt(0);

   System.out.println("Enter second number: ");
  num2 =sc.nextDouble();
    
   switch(op)
  {
   
   case '+':
         result= num1+num2;
         System.out.println(num1+ "+" +num2+ "=" +result);
         break;

   case '-':
         result= num1-num2;
         System.out.println(num1+ "-" +num2+ "=" +result);
         break;


  case '*':
         result= num1*num2;
         System.out.println(num1+ "*" +num2+ "=" +result);
         break;

  case '/':
         result= num1/num2;
         System.out.println(num1+ "/" +num2+ "=" +result);
         break;
  case '!':
          System.out.println(f.factorial(num1));
          System.out.println(f.factorial(num2));

  default :
         System.out.println("Invalid choice... ");
         break;
  }  
 } 
}      
     
