#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l, int m, int r) {
	int i, j, k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1], R[n2];

	for(i=0; i<n1; i++)
		L[i]=arr[l+i];
	for(j=0; j<n2; j++)
		R[j]=arr[m+1+j];

	i=0, j=0, k=l;

	while(i<n1 && j<n2) {
		if(L[i] <= R[j]) {
			arr[k]=L[i];
			i++;
		}
		else {
			arr[k]=R[j];
			j++;
			}
		k++;
	}

	// remaining elements of L[]
	while(i<n1) {
		arr[k]=L[i];
		i++;
		k++;
	}

	// remaining elements of R[]
	while(j<n2) {
		arr[k]=R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l<r) {
		int m=(l+r)/2;
		
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		
		merge(arr, l, m, r);
	}
}

void quickSort(int arr[],int first,int last){
	int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
	         i++;
         while(arr[j]>arr[pivot])
	         j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quickSort(arr,first,j-1);
      quickSort(arr,j+1,last);
   }
}

void display(int A[], int size) {
	for (int i=0; i<size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void main() {
	int arr[20], n, ch;
	char ctn;
	
	do {
		printf("Enter the number of elements in the array: ");
		scanf("%d", &n);
		printf("Enter the elements to the array: ");
		for(int i=0; i<n; i++)
			scanf("%d", &arr[i]);
		
		printf("1. Merge sort\n");
		printf("2. Quick sort\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				mergeSort(arr, 0, n-1);
				break;
			case 2:
				quickSort(arr,0,n-1);
				break;
			default:
				printf("Invalid input");
				break;	
		}
		
		printf("Array after sorting \n");
		display(arr, n);
		
		printf("Do you wish to continue? (y/n): ");
		scanf(" %c", &ctn);
		printf("\n");
	} while(ctn=='Y' || ctn=='y');
	
}
