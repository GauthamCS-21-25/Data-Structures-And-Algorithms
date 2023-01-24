#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *st,*top=NULL,*ptr;
struct node *q,*f=NULL,*r=NULL;

void pushStack() {
	st=(struct node*)malloc(sizeof(struct node));
	printf("Enter element:");
	scanf("%d",&st->data);
	st->next=NULL;
	if(top==NULL)
		top=st;
	else {
		st->next=top;
		top=st;
	}
}
void popStack() {
	if(top==NULL)
		printf("Stack empty\n");
	else {
	ptr=top;
	top=top->next;
	free(ptr);
	}
}
void displayStack() {
	if(top==NULL)
		printf("Stack empty\n");
	else {
		ptr=top;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}
	printf("\n");
}

void enqueue() {
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter element:");
	scanf("%d",&q->data);
	q->next=NULL;
	if(f==NULL)
		f=q;
	else 
		r->next=q;
	r=q;
}
void dequeue() {
	if(f==NULL)
		printf("Queue is empty\n");
	else {
		ptr=f;
		f=f->next;
		free(ptr);
	}
}
void displayQueue() {
	if(f==NULL)
		printf("Queue empty\n");
	else {
		ptr=f;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}
	printf("\n");
}
void main() {
	int ch=-1; char ctn;
	do {
		printf("1. Push an element\n");
		printf("2. Pop an element\n");
		printf("3. Display stack\n");
		printf("4. Insert an element\n");
		printf("5. Delete an element\n");
		printf("6. Display queue\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				pushStack();
				break;
			case 2:
				popStack();
				break;
			case 3:
				displayStack();
				break;
			case 4:
				enqueue();
				break;
			case 5:
				dequeue();
				break;
			case 6:
				displayQueue();
				break;
			default:
				printf("Invalid input\n");
			break;
		}
		printf("Do you wish to continue? (y/n): ");
		scanf(" %c", &ctn);
		printf("\n");
	} while(ctn=='y' || ctn=='Y');
}
