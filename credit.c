#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int ccNumLength = 0;
    
    printf("Please enter in your credit card number:");
    
    long long ccNum = GetLongLong();
    
    //printf("You have entered: %lld\n",ccNum);    
    
    //printf("last digit: %lld\n",ccNum%10);
    
    //printf("second to last digit: %lld\n",ccNum/10%10);    
    
    double x = ccNum;
    
    while(x>1)
    {
        x /= 10;
        ccNumLength++;
    }
    
    //printf("length of number is: %d\n", ccNumLength);
    
    long long first2Digits = ccNum;
    
    //printf("long long var of ccNum is: %lld\n",first2Digits);
    
    int i;
        
    for(i=1;i<=(ccNumLength-2);i++)
    {
        first2Digits /= 10;
    }
    
    //printf("first 2 digits are: %lld\n",first2Digits);
    
    int firstDigit = first2Digits/10;
    bool validity = 1;
    
    //printf("first digit is: %d\n", firstDigit);
    
    string ccType;
    bool Authentic = true;
    
    if((first2Digits==34 || first2Digits==37) && ccNumLength==15)
    {
        ccType = "AMEX";
    }
    else if((first2Digits>=51 && first2Digits<=55) && ccNumLength==16)
    {
        ccType = "MASTERCARD";
    }
    else if(firstDigit==4 && (ccNumLength==13 || ccNumLength==16))
    {
        ccType = "VISA";
    }
    else
    {
        printf("INVALID\n");
        Authentic = false;
        validity = 0;
    }
    
    double firstSumTemp = ccNum%10;
    long long temp = ccNum;
    
    int sum1 = 0;
    int sum2 = 0;
    
    
    if(Authentic)
    {
        while(temp>1)
        {
            temp /= 100;
            firstSumTemp += temp%10;
        }
        
        sum1 = firstSumTemp;
        //printf("Sum1 = %d\n", sum1);
        
        long long temp2 = ccNum/10;
        //printf("2nd to last number is: %lld\n", temp2%10);
        
        do
        { 
            // printf(": %ld\n",temp%10);
             if(temp2%10 >= 5)
             {
                if(temp2%10==5){
                    sum2 += 1;
                }
                else if (temp2%10==6){
                    sum2 += 3;
                }
                else if (temp2%10==7){
                    sum2 += 5;
                }
                else if (temp2%10==8){
                    sum2 += 7;
                }
                else if (temp2%10==9){
                    sum2 += 9;
                }
                else{
                    printf("error\n");
                }
    git remote add origin https://github.com/ytv/cs50-credit-card-validation.git
git push -u origin master         }
             else
             {
                sum2 += temp2%10 * 2;
             } 
           
             temp2 /= 100;
        } 
        while (temp2>1);
    }
    
    //printf("Sum2: %d\n", sum2);
    
    //printf("Total Sum = %d\n", sum1+sum2);
    
    int totalSum = sum1 + sum2;
    
    if(validity == 1)
    {
        if(totalSum%10 == 0)
        {
            //printf("%s",ccType);
            if(strcmp(ccType,"VISA") == 0){
                printf("VISA\n");
            }
            else if(strcmp(ccType,"MASTERCARD") == 0){
                printf("MASTERCARD\n");
            }
            else {
                printf("AMEX\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }    
    }
    return 0;
}
