#include<stdio.h>
#include<string.h>
int main()
{
    char str1[1000],str3[1000];
    char str2[1000];
    scanf("%s %s",str1,str2);
    int n1=strlen(str1),n2=strlen(str2);
    int k1=n1-1,k2=n2-1,i=0,carry=0;
    while(k1>=0 && k2>=0){
        int ans = (str1[k1]-48)+(str2[k2]-48)+carry;
        str3[i]=(ans%10)+48;
        carry=ans/10;
        k1--;
        k2--;
        i++;
    }
    while(k1>=0){
        int ans = (str1[k1]-48)+carry;
        str3[i]=(ans%10)+48;
        carry = ans/10;
        k1--;
        i++;
    }
    if(carry!=0){
        str3[i]=carry+48;
        str3[i+1]='\0';
    }
    else{
        str3[i]='\0';
    }

printf("%s",strrev(str3));
    
}