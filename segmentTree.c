#include<stdio.h>
int nextPowerof2(int n){
    int a=1;
    while(a<n){
        a=a<<1;
    }
    return a;
}
void constructTree(int arr[],int segTree[],int start,int end,int pos){
    if(start==end){
        segTree[pos]=arr[start];
    }
    else{
        int mid = (start+end)/2;
        constructTree(arr,segTree,start,mid,2*pos);
        constructTree(arr,segTree,mid+1,end,2*pos+1);
        segTree[pos]=segTree[2*pos]+segTree[2*pos+1];

    }
}
int getSum(int segTree[],int s,int e,int qs,int qe,int pos){
    if(s>=qs && e<=qe){
        return segTree[pos];
    }
    else if(e<qs || s>qe){
        return 0;
    }
    else{
        int mid = (s+e)/2;
        return getSum(segTree,s,mid,qs,qe,2*pos)+getSum(segTree,mid+1,e,qs,qe,2*pos+1);
    }

}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k = 2*nextPowerof2(n);
    int segTree[k];
    constructTree(arr,segTree,0,n-1,1);
    for(int i=1;i<k;i++){
        printf("%d ",segTree[i]);
    }
    printf("\n");
    printf("%d",getSum(segTree,0,n-1,2,6,1));

}