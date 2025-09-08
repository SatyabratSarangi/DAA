//Q1. Implementation of Iterative Linear Search

#include<stdio.h>
void create_arr(int[],int);
int linear_search(int [],int,int);

int main(){
    int size,ele;
    printf("enter the size of arr you want");
    scanf("%d",&size);
    int arr[size];
    create_arr(arr,size);

    printf("enter the element you want to search");
    scanf("%d",&ele);
    int res=linear_search(arr,size,ele);
    if(res==-1){
        printf("element not present");
    }else{
        printf("element found at index %d",res);
    }
}
void create_arr(int arr[],int size){
    int i;
    printf("enter arr elements");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}
int linear_search(int arr[],int size,int key){
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==key)
            return i;
    }
    return -1;
}