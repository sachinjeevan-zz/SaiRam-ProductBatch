#include<stdio.h>
#include<string.h>
int main()
{
    char str1[1000],str2[1000],str3[1000];
    for(int h=0;h<999;h++)str3[h]='0';
    str3[999]='\0';
    scanf("%s %s",str1,str2);
    int n1=strlen(str1),n2=strlen(str2);
    int k1=n1-1,k2=n2-1,carry1=0,carry2=0,i,k=0;
    while(k2>=0){
        k1=n1-1;
        carry1=0;
        carry2=0;
        i=k;
        while(k1>=0){
            int ans = (str1[k1]-48)*(str2[k2]-48)+carry1;
            int sum = (str3[i]-48)+(ans%10)+carry2;
            str3[i] = (sum%10)+48;
            carry1= ans/10;
            carry2 = sum/10;
            k1--;
            i++;
        }
            str3[i]=((str3[i]-48)+carry1+carry2)+48;

        k++;
        k2--;
    }
    if(str3[i]!='0'){
        str3[i+1]='\0';
    }
    else{
        str3[i]='\0';
    }
printf("%s",strrev(str3));


}