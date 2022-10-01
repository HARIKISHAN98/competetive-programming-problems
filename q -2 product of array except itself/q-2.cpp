//cp question 2 Product of Array Except Self
#include<iostream>
#include<math.h>
using namespace std;


int divide(int num,int deno)
{
int sign = (num<0) ^ (deno<0),ans;
// bitwise operator is used because it have a property
// same hoga to  0 ,diffrent hoga to 1
// thats why if +/+ = + , -/- = +  store 0 in sign variable
// if +/- = - , -/+ = - store 1 in sign variable

    if(deno == 0)  //0 se kisi ko bhi divide kro 0 aayega
    return 0;

    else if(num == 0)    // numerator is 0 it means not defined , so we return 0;
    {
        cout<<"division Not possible"<<endl;
        return 0;
    }

    else
    {
       ans = exp(log(num) - log(deno)) + 0.000000001;
       //  0.000000001 is add because this exp function give less accurate value
    }

    return sign == 0 ? ans : -ans ;
    // if sign = 0 num/deno = +ve means no need to change sign
    // if sign = 0 num/deno = -ve means  need to change sign , that's why return with -ve sign

}

int* product_except_itself(int nums[],int size)
{
int  product = 1, count_zero = 0;
// product variable contain product of element except nums[i]
// count_zero is used to count the zeros in nums array

int *ptr = new int(size); //create dynamic array

for (int i = 0; i < size; i++)
{
    if(nums[i] == 0)     //if element is 0 then count_zero value increase by 1
    count_zero++;
    
    else         //otherwise product is store in product variable except self
    product *= nums[i];
}

for (int i = 0; i < size; i++)
{
    if (count_zero > 1)
    {
     ptr[i] = 0; //if zero is more then  1 then in resultant array all elements is 0
    }
    
    else if(count_zero == 1)
    {
       if(nums[i]==0)   //if element is 0 then put product in place at ans[i];
       ptr[i] = product ;

       else  //kyuki sare product ko zero bna dega
       ptr[i] = 0;
    }

    else
    {
    ptr[i] = divide(product,nums[i]);   //divide function does not contain divide 
    }                                   // operator ,it use log

}

return ptr;  //return the pointer which contain base address of dynamic array
}

int main()
{
int size;
cout<<"Enter size of array : "<<endl;
cin >> size;
int nums[size];
cout<<"Enter "<<size <<" element in array :"<<endl;

for (int i = 0; i < size; i++) //input the array
{
    cin >> nums[i];
}


cout<<"The resultant array is :"<<endl;

int *ptr = product_except_itself(nums,size);

for (int i = 0; i < 5; i++)
{
    cout<<*(ptr+i)<<" ";
}
cout<<endl;


    return 0;
}