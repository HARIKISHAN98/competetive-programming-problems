#include<iostream>
using namespace std;

bool Is_palindrome(int x)
{
//approach : based on the reverse half of number and compare it with another half
// if it is equal the it is palindrome otherwise not    

  if(x<0 || x!=0 && x%10 ==0)  //check base cases  || if no. is -ve 
  return false;               //last digit is 0 and not first then return false

  int reversNumber = 0;

  while(x > reversNumber)
  {
    reversNumber = reversNumber * 10 + x % 10;
    x/=10;
  }


return x == reversNumber || x == reversNumber/10;

}
int main()
{
    int number;
    cout<<"Enter a number to check palindrom : ";
    cin >> number;

 if( Is_palindrome(number) )
 cout<<number  <<" is palindrome "<<endl;
 
 else
 cout<<number  <<" is not palindrome "<<endl;


    return 0;
}