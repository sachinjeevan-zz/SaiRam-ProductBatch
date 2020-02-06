#include<stdio.h>
void merge(int arr[],int start,int mid,int end){
    int n1 = mid-start+1 , n2 = end-mid;
    int L[n1],R[n2],k=0;
    for(int i=start;i<=mid;i++){
        L[k]=arr[i];
        k++;
    }
    k=0;
    for(int i=mid+1;i<=end;i++){
        R[k]=arr[i];
        k++;
    }
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[start]=L[i];
            start++;
            i++;
        }
        else{
            arr[start]=R[j];
            start++;
            j++;
        }
    }
    while(i<n1){
        arr[start]=L[i];
        start++;
        i++;
    }
    while(j<n2){
        arr[start]=R[j];
        start++;
        j++;
    }
}
void mergeSort(int arr[],int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}