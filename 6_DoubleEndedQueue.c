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
		printf("1. Insert element from front\n");
		printf("2. Insert element from rear\n");
		printf("3. Delete element from front\n");
		printf("4. Delete element from rear\n");
		printf("5. Display the queue\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
		    case 1:
				if((r+1)%n == f)
					printf("The queue is full.\n");
				else{
					printf("Enter the element: ");
					scanf("%d", &a[f]);
					if(f==0)
						f=n-1;
					else
						f=(f-1)%n;
				}
				
			break;
			case 2:
				if((r+1)%n == f)
					printf("The queue is full.\n");
				else
				{
					printf("Enter the element: ");
					r=(r+1)%n;
					scanf("%d", &a[r]);
				}
			break;
			case 3:
				if(f==r){
					printf("The queue is empty.\n");
				}
				else{
					f=(f+1)%n;
					printf("%d deleted.\n", a[f]);
				}
			break;
			case 4:
				if(f==r){
					printf("The queue is empty.\n");
				}
				else{
					printf("%d deleted.\n", a[r]);
					if(r==0)
				   	r=n-1;
					else
						r=(r-1)%n;
				}	
			break;
			case 5:
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
			default:
				printf("Invalid choice.\n");
		}
		printf("Do you wish to continue? (y/n): ");
		scanf(" %c", &cont);
		printf("\n");
	}while(cont=='y' || cont=='Y');
}



