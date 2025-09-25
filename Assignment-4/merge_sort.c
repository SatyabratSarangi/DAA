#include<stdio.h>
int size;
void merge(int arr[],int st,int mid,int end){
    int newarr[100];
    int i=st;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            newarr[k++]=arr[i++];
        }else{
            newarr[k++]=arr[j++];
        }
    }
    while(i<=mid){
        newarr[k++]=arr[i++];
    }
    while(j<=end){
        newarr[k++]=arr[j++];
    }
    for(i = 0; i < k; i++) {
        arr[st + i] = newarr[i];   
    }
}
void merge_sort(int arr[],int st,int end){
    if(st<end){
        int mid=st+(end-st)/2;
        merge_sort(arr,st,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}

int main(){
    int i;
    printf("enter the size of arr");
    scanf("%d",&size);

    int arr[size];
    printf("enter the element of arraya");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("\narray after sorting\n");
    merge_sort(arr,0,size-1);
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }

}