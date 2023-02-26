#include<stdio.h>

int arr[10], n;

void insertion();
void selection();
void display();

void main(){
	int choice; char ctn;
	do{
		printf("\nEnter the number of elements in the array: ");
		scanf("%d", &n);
		printf("Enter the elements to the array: ");
		for(int i=0; i<n; i++)
			scanf("%d", &arr[i]);
			
		printf("\n1. Insertion Sort");
		printf("\n2. Selection Sort");

		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				insertion();
				display();
				break;
			case 2:
				selection();
				display();
				break;
			default:
				printf("\nInvalid choice");
				break;
		}
		printf("Do you wish to continue (y/n)? ");
		scanf(" %c", &ctn);
	}while(ctn=='Y'||ctn=='y');
}

void insertion(){
	int key, j;
	for(int i=0; i<n ;i++){
		key=arr[i]; j=i-1;
		while(j>=0 && key<=arr[j]){
			arr[j+1]=arr[j];
			j-=1;
		}
		arr[j+1]=key;
	}
}

void selection(){
	int min_index, temp, i, j;
	for(int i=0; i<n-1; i++){
		min_index=i;
		for(int j=i+1; j<n; j++)
			if(arr[j]<arr[min_index])
				min_index=j;
		temp=arr[i];
		arr[i]=arr[min_index];
		arr[min_index]=temp;
	}
}

void display(){
	for(int i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}
