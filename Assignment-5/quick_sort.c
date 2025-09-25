// Quick Sort

#include<stdio.h>
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low-1, j, t;
	for (j=low;j<=high-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
		}
	}
	t=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=t;
	return (i + 1);
}
void quicksort(int arr[], int low, int high)
{
	if(low< high)
	{
		int mid = partition(arr,low,high);
		quicksort(arr, low, mid - 1);
		quicksort(arr, mid + 1, high);
	}
}
void main()
{
	int n, i;
	printf("Please enter the size of the array : ");
	scanf("%d", &n);
	int arr[n];
	printf("Please insert the elements of array");
	for(i=0;i<n;i++)
	{
		printf("Element at index %d : ",i);
		scanf("%d",&arr[i]);
	}
	
	quicksort(arr,0,n-1);
	printf("The sorted array is : ");
	for(i=0;i<n;i++)
		printf(" %d", arr[i]);
	printf("\n");
}