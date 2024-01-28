#include "NumClass.h"
#include <stdio.h>




int digits(int num)
{
    int temp = 0;
   
   while (num != 0) {
      temp++;
      num = num/10;
   }
    return temp;
}


int subtractingNumber(int num ,int temp)
{
    
if (num == 0)
        return temp;
 
    
    temp = (temp * 10) + (num % 10);
 
    return subtractingNumber(num / 10, temp);
} 



int power(int num , int res)
{
    int sum = 1;
    for (int i = 0; i < res; i++)
    {
        sum = sum*num;
    }
   
    return sum;
}

int testArmstrongNumber(int num ,int r,int sum)
{   
    
    if (num == 0)
    {
        return sum;
    }
    sum = sum + power(num%10,r);
    
    return testArmstrongNumber(num/10 ,r,sum);
}


int isArmstrong(int num)
{
    int power1 = digits(num);
    int sum = 0;
    int temp = testArmstrongNumber(num,power1,sum);

    if(temp == num)
    {
      
        return 1;
    }
    else
    {
        
        return 0;
    }
    
}
    



int isPalindrome(int num)
{
    int secNum = subtractingNumber(num, 0);

    if (secNum == num)
    {
       
        return 1 ;
    }

    else
    {
        return 0;
    }    

}
