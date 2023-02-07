#include<stdio.h>
#define SIZE 20

int array[SIZE];

void heapify(int array[], int sizeHeap, int Pidx){
	int temp;
	int max = Pidx;
	int LCidx = 2 * Pidx + 1;
	int RCidx = 2 * Pidx + 2;
	if (LCidx < sizeHeap && array[LCidx] > array[max])
		max = LCidx;
	if (RCidx < sizeHeap && array[RCidx] > array[max])
		max = RCidx;
	if (max != Pidx){
		temp = array[Pidx];
		array[Pidx]=array[max];
		array[max]=temp;
		heapify(array, sizeHeap, max);
	}
}

void heapSort(int array[], int n){
	int temp;
	for (int NLNidx = n / 2 - 1; NLNidx >= 0; NLNidx--)
		heapify(array, n, NLNidx);
	for (int LHidx = n - 1; LHidx >= 1; LHidx--){
		temp=array[0];
		array[0]=array[LHidx];
		array[LHidx]=temp;
		heapify(array, LHidx, 0);
	}
}

void main(){
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements to the array: ");
	for(int i=0;i<n;i++)
		scanf("%d",&array[i]);
		
	heapSort(array, n);
	
	printf("Sorted array: ");
	for (int i = 0; i < n; ++i)
		printf("%d ",array[i] );
	printf("\n");
}
