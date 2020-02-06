#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int k=(n-2)/2;
    int arr[k];
    for(int i=0;i<k;i++){
        arr[i]=i+1;
    }
    int i,j,z=1,res;
    while(1){
        i=z;
        j=z;
        res = i+j+(2*i*j);
        if(res>k)break;
        while(1){
            res = i+j+(2*i*j);
            if(res>k)break;
            arr[res-1]=0;
            j++;
        }
        z++;

    }
    printf("2 ");
    for(int l=0;l<k;l++){
        if(arr[l]!=0){
            printf("%d ",arr[l]*2+1);
        }
    }

}