#include <bits/stdc++.h>
#include "BigInt.h"

using namespace std;


BigInt::BigInt(string num)
{
    decStr=num;
}
BigInt::BigInt(int num)
{
    while (num!=0){
            int x = num%10 ;
    num/=10 ;
        decStr=char(x+48)+decStr;
    }

}
BigInt BigInt::operator+ (BigInt& secondNumber){
            BigInt right=secondNumber;
            BigInt current= *this;
            char temp; int maxsize,mini,carry=0,sum,sum1=0,sum2=0;BigInt ans("");string container;
                if (secondNumber.decStr[0]!='-'&&decStr[0]=='-'){
            BigInt m(decStr.substr(1));
             ans=(secondNumber-m);
            return ans;
        }
        else if (secondNumber.decStr[0]=='-'&&decStr[0]!='-'){
            BigInt second(secondNumber.decStr.substr(1));
            BigInt m(decStr);
             ans=(m-second);
            return ans;
        }
        else if (secondNumber.decStr[0]=='-'&&decStr[0]=='-'){
                BigInt m(decStr.substr(1)), second(secondNumber.decStr.substr(1));
                 ans=(second+m);
                 ans.decStr="-"+ans.decStr;
                return ans;
        }
        else if (secondNumber.decStr[0]!='-'&&decStr[0]!='-'){
             if (secondNumber.decStr.length()>decStr.length()){
                    maxsize=secondNumber.decStr.length();
                    mini=decStr.length();
                    for ( int m=mini;m<maxsize;m++){
                        decStr="0"+decStr;}
                    container=decStr;
                    decStr=secondNumber.decStr;
                    secondNumber.decStr=container;
        }

        else{
                    maxsize=decStr.length();
                    mini=secondNumber.decStr.length();
                     for ( int m=mini;m<maxsize;m++){
                        secondNumber.decStr="0"+secondNumber.decStr;
                    }}

            for(int i=(maxsize-1);i>=0;i--){
            sum=carry+secondNumber.decStr[i]+decStr[i]-96;
            if (sum>=10){
                carry=1;
                sum%=10;}
            else {
                carry=0;
            }
               char temp=(sum+'0');
            ans.decStr=temp+ans.decStr;
            }
            bool zero=true;
            for (int in = 0; in < ans.decStr.length(); in++){
                if (ans.decStr[in]!='0'){
                    zero=false;
                    break;
                }in++;
            }
            if (zero==true){
                ans.decStr="0";
            }}
            temp=carry+'0';
                        ans.decStr=temp+ans.decStr;
 *this = current;
            secondNumber=right;
            return ans;
        }

BigInt BigInt::operator- (BigInt& secondNumber)
{//cout<<"FIRST"<<decStr<< "  -  "<<secondNumber.decStr<<endl;
BigInt right=secondNumber;
            BigInt current= *this;

        int maxsize,mini,borrow=0,sum;BigInt ans("");bool negative=false;
        //bool inverse=false;
        string container;int sum1=0;int sum2=0;
        if (secondNumber.decStr[0]!='-'&&decStr[0]=='-'){
            BigInt m(decStr.substr(1));
             ans=(m+secondNumber);
             ans.decStr="-"+ans.decStr;
            return ans;
        }
        else if (secondNumber.decStr[0]=='-'&&decStr[0]!='-'){

            BigInt  second(secondNumber.decStr.substr(1));
            BigInt m(decStr);
            ans=(m+second);
            return ans;
        }
        else if (secondNumber.decStr[0]=='-'&&decStr[0]=='-'){
            //decStr[0]='/0';
           // secondNumber.decStr[0]='/0';
          // cout<<"BEFORE"<<decStr<<"-"<<secondNumber;
            BigInt m(decStr.substr(1)), second(secondNumber.decStr.substr(1));
            ans=(second-m);
            //cout<<endl<<second<<" MINUS "<<m<<endl;
//            inverse=true;
            return ans;
        }
        else if (secondNumber.decStr[0]!='-'&&decStr[0]!='-'){

        if (secondNumber.decStr.length()>decStr.length()){
                negative=true;
                    maxsize=secondNumber.decStr.length();
                    mini=decStr.length();
                    for ( int m=mini;m<maxsize;m++){
                        decStr="0"+decStr;}
                    container=decStr;
                    decStr=secondNumber.decStr;
                    secondNumber.decStr=container;
        }
        else if (decStr.length()==secondNumber.decStr.length()){
                for (int in =0;in<=(decStr.length()); in++){
                   if ((decStr[in]-'0')<(secondNumber.decStr[in]-'0')){
                    negative=true;
                    container=secondNumber.decStr;
                    secondNumber.decStr=decStr;
                    decStr=container;
                    break;
                   }
                   else{
                       // negative=false;
                    break;
                   }
                }

    }


        else{
                    maxsize=decStr.length();
                    mini=secondNumber.decStr.length();
                     for ( int m=mini;m<maxsize;m++){
                        secondNumber.decStr="0"+secondNumber.decStr;
                    }}
            for(int i=(decStr.length()-1);i>=0;i--){

                if (decStr[i]==0&&borrow==1){
                    for (int m=i;m>=0;m--){
                        if (decStr[m]>0){
                            decStr[m]=decStr[m]-49;
                            borrow=0;
                            break;
                        }
                    }

                }
                sum=decStr[i]-secondNumber.decStr[i]-borrow;
            if (sum<0){
                sum=(10+decStr[i])-secondNumber.decStr[i]-borrow;
                borrow=1;

            }
            else {
                borrow=0;

            }
            char temp=(sum+'0');
            ans.decStr=temp+ans.decStr;
            }
            bool zero=true;
            for (int in = 0; in < ans.decStr.length(); in++){
                if (ans.decStr[in]!='0'){
                    zero=false;
                    break;
                }in++;
            }
            if (zero==true){
            }
            if (negative==true){
                ans.decStr="-"+ans.decStr;
            }

            *this = current;
            secondNumber=right;
            return ans;}
        }

bool BigInt::operator==(BigInt m)
    {
        BigInt num(decStr);
        BigInt diff=num-m;
        if (diff.decStr=="0")
        {
            return 1;
        }
        else
            return 0;
    }
bool BigInt::operator!=(BigInt m)
{
    BigInt num(decStr);
    //BigInt zero("0");
    BigInt diff=num-m;
    if (diff.decStr=="0")
    {
        return 0;
    }
    else
        return 1;
}

bool BigInt::operator> (BigInt m)
{
    BigInt num(decStr);
    BigInt diff=num-m;
    if(diff.decStr[0]=='-')
    {
        return 0;
    }
    else
        return 1;
}
bool BigInt::operator< (BigInt m)
    {
        BigInt num(decStr);
        BigInt diff=num-m;

        if(diff.decStr[0]=='-')
        {
            return 1;
        }
        else
            return 0;
    }
BigInt BigInt::operator--(int )
        {
            BigInt temp= *this;
            BigInt one("1");
            *this= *this - one;
            return temp;
        }
BigInt BigInt::operator++(int )
        {
            BigInt temp= *this;
            BigInt one("1");

            *this= *this + one;
            return temp;
        }
