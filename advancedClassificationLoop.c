#include "NumClass.h"
#include <stdio.h>



/**
 * A strong number is the factorial sum of its digits, equal to the number itself.
 * 
*/
int isArmstrong(int numInt){
    int  orginalnum = numInt;
    int remainder;
    int pow = 0;     

    int result = 0;

    for ( int i = 0; orginalnum!=0 ; i++)
    {
        orginalnum /= 10;
        pow += 1;
    }
    
    int temp;
    for(orginalnum = numInt; orginalnum!=0; orginalnum/=10)
    {

        remainder = orginalnum%10;    
        temp = remainder;
       
        for (int i = 1; i < pow; i++)
        {
            remainder *= temp;
        }
        
        result += remainder;

    }

    if(result == numInt){
        return 1;
    }


    
    return 0;
}



/**
 * Strong number is a special number whose sum of the factorial of digits is equal to the original number. 
 * For Example: 145 is strong number. Since, 1! + 4! + 5! = 145. 
 * @return 1 if numInt is strong number.
*/
int isPalindrome(int numInt){
    int remainder;
    int sum = 0;
    int numberOrginal = numInt;
    while(numInt>0)    
    {    
        remainder = numInt %10;    
        sum = (sum*10) + remainder;    
        numInt = numInt/10;    
    }     
  
    if(numberOrginal==sum)
    {
          
        return 1;
    }  
 
     
    
    return 0;
}
