#define SIZE 100
#include <stdio.h>
int n, f=0, r=0, a[SIZE];
void main(){
	int ch;
	int i;
	char cont;
		printf("Enter the number of elements in the queue: ");
		scanf("%d", &n);
		printf("\n");
	do{
		printf("Queue operations available are: \n");
		printf("1. Add an element\n");
		printf("2. Delete an element\n");
		printf("3. Display the queue\n");
		printf("4. Display the front and rear element in the queue\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				if((r+1)%n == f)
					printf("The queue is full.\n");
				else
				{
					printf("Enter the element: ");
					r=(r+1)%n;
					scanf("%d", &a[r]);
				}
			break;
			case 2:
				if(f==r){
					printf("The queue is empty.\n");
				}
				else{
					f=(f+1)%n;
					printf("%d popped.\n", a[f]);
				}
			break;
			case 3:
				if(f==r){
					printf("The queue is empty.\n");
				}
				else
				{
					if(f<r)
						for(i=f+1; i<=r; i++)
							printf("%d\t", a[i]);
					else{
						for(i=f+1; i<n; i++)
							printf("%d\t", a[i]);
						for(i=0; i<=r; i++)
							printf("%d\t", a[i]);
					}
					printf("\n");
				}	
			break;
			case 4:
				if(f==r){
					printf("The queue is empty.\n");
				}
				else
				{
					printf("Front element is %d.\n", a[f+1]);
					printf("Rear element is %d.\n", a[r]);
				}
			break;
			default:
				printf("Invalid choice.\n");
		}
		printf("Do you wish to continue? (y/n): ");
		scanf(" %c", &cont);
		printf("\n");
	}while(cont=='y' || cont=='Y');
}
