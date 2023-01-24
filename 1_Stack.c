#define SIZE 100
#include <stdio.h>
int n, t=-1, a[SIZE];
void main(){
	int ch;
	int i;
	char cont;
		printf("Enter the number of elements in the stack: ");
		scanf("%d", &n);
		printf("\n");
	do{
		printf("Stack operations available are: \n");
		printf("1. Push an element\n");
		printf("2. Pop an element\n");
		printf("3. Display the stack\n");
		printf("4. Display the top element in the stack\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				if(t==n-1)
					printf("The stack is full.\n");
				else
				{
					printf("Enter the element: ");
					t+=1;
					scanf("%d", &a[t]);
				}
			break;
			case 2:
				if(t==-1)
					printf("The stack is empty.\n");
				else{
					printf("%d popped.\n", a[t]);
					t-=1;
				}
			break;
			case 3:
				if(t==-1)
					printf("The stack is empty.\n");
				else
				{
					for(i=0; i<=t; i++)
						printf("%d\t", a[i]);
					printf("\n");
				}	
			break;
			case 4:
				if(t==-1)
					printf("The stack is empty.\n");
				else
					printf("Top element is %d.\n", a[t]);
			break;
			default:
				printf("Invalid choice.\n");
		}
		printf("Do you wish to continue? (y/n): ");
		scanf(" %c", &cont);
		printf("\n");
	}while(cont=='y' || cont=='Y');
}

