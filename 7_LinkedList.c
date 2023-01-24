#include <stdio.h>
#include <stdlib.h>

void insertFront();
void insertRear();
void insertNode();
void deleteFront();
void deleteRear();
void deleteNode();
void display();

struct node 
{
    int data;
    struct node *next;
};

struct node *head=NULL, *tail=NULL, *p, *ptr;

void main(){

    int choice; char ch;

    do{

        printf("\n1. Insert at front");
        printf("\n2. Insert at rear");
        printf("\n3. Insert after a node");
        printf("\n4. Delete from front");
        printf("\n5. Delete from rear");
        printf("\n6. Delete a node");
        printf("\n7. Display\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;
            
            case 2:
                insertRear();
                break;
            
            case 3:
                insertNode();
                break;

            case 4:
                deleteFront();
                break;

            case 5:
                deleteRear();
                break;
            
            case 6:
                deleteNode();
                break;
            
            case 7:
                display();
                break;
            
            default:
                printf("\nInvalid input.");
                break;
        }

        printf("\nDo you wish to continue? (y/n): ");
        scanf(" %c", &ch);
        printf("\n");
    }while (ch=='y' || ch=='Y');
}

void insertFront(){
    p=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);
    if (head==NULL){
        p->next=NULL;
        tail=p;
    }
    else
        p->next=head;
    head=p;
    printf("%d linked at front.\n", p->data);
}

void insertRear(){
    p=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);
    p->next=NULL;
    if(head==NULL){
        head=p;
        tail=p;
    }
    else{
        tail->next=p;
        tail=p;
    }
    printf("%d linked at rear\n", p->data);
}

void insertNode(){
    int se, flag=0;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    p=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);
    printf("After what node should this be inserted? ");
    scanf("%d", &se);
    while (ptr!=NULL)
    {
        if (ptr->data==se)
        {
            flag=1;
            break;
        }
        else
            ptr=ptr->next;
    }
    if (flag==1)
    {        
        p->next=ptr->next;
        ptr->next=p;
        printf("%d linked after %d", p->data, se);

        if (ptr==tail)
            tail=p;
    }
    else
        printf("Node not found\n");
}

void deleteFront(){
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    if (head==NULL)
        printf("List is empty\n");
    else{
        struct node *ptr=head;
        head=ptr->next;
        printf("%d deleted", ptr->data);
    }
    free(ptr);
}

void deleteRear(){
    struct node *prev;
    prev=(struct node*)malloc(sizeof(struct node));
    ptr=(struct node*)malloc(sizeof(struct node));
    if (head==NULL)
        printf("List is empty");
    else{
        ptr=head;
        while (ptr->next!=NULL){
            prev=ptr;
            ptr=ptr->next;
        }
        if (ptr==head)
            head=NULL;
        
        prev->next=NULL;
        printf("%d deleted", tail->data);
        tail=prev;
        
    }

    free(ptr);
}

void deleteNode(){
    struct node *prev;
    prev=(struct node*)malloc(sizeof(struct node));
    ptr=(struct node*)malloc(sizeof(struct node));
    if (head==NULL)
        printf("List is empty\n");
    else{
        int se;
        ptr=head;
        printf("Enter the node to be deleted: ");
        scanf("%d", &se);
        while (ptr!=NULL && ptr->data!=se)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        if (ptr!=NULL)
        {
            prev->next=ptr->next;
            if (ptr==tail)
                tail=prev;
            if (ptr==head){
                head=ptr->next;
            }
            printf("%d deleted", ptr->data);
        }
        else
        		printf("Node not found\n");
    }
    free(ptr);
}

void display(){
    ptr=(struct node*)malloc(sizeof(struct node));
    if (head==NULL)
        printf("List is empty\n");
    
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
    free(ptr);
}
