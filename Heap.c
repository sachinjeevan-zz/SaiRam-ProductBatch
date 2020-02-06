#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int heap[n+1];
    int i=1,k;
    scanf("%d",&heap[i]);
    i++;
    while(i<=n){
        scanf("%d",&heap[i]);
        k=i;
        while(k/2>0){
            if(heap[k]>heap[k/2]){
                int temp = heap[k];
                heap[k]=heap[k/2];
                heap[k/2]=temp;
                k=k/2;
            }
            else{
                break;
            }
        }
        i++;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
    int size =n,temp,max;
    while(size>1){
        temp = heap[1];
        heap[1]=heap[size];
        heap[size]=temp;
        size--;
        k=1;
        while(2*k<=size){
            if(2*k+1<=size){
                if(heap[2*k]>heap[2*k+1]){
                    max = 2*k;
                }
                else{
                    max = 2*k+1;
                }
            }
            else{
                max = 2*k;
            }
            if(heap[max]>heap[k]){
                temp = heap[max];
                heap[max]=heap[k];
                heap[k]=temp;
                k=max;
            }
            else{
                break;
            }
        }

    }
    for(int i=1;i<=n;i++){
        printf("%d ",heap[i]);
    }

}