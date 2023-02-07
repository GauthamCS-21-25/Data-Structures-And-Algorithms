#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *next,*pre;
} *p,*head,*before,*tail,*temp,*after,*prev;

void getelement(){
  p = (struct node*)malloc(sizeof(struct node));
  printf("Enter the data : ");
  scanf("%d", &p->data);
  p->next = NULL;
  p->pre = NULL;
}

void insert_front(){
  getelement();
  if(head == NULL){
    head = p;
    tail = p;
  }
  else{
    p->next = head;
    head->pre = p;
    head = p;
  }
}

void insert_rear(){
  getelement();
  if(head == NULL){
    head = p;
    tail = p;
  }
  else{
    tail->next = p;
    p->pre = tail;
    tail = p;
  }
}

void insert_node_after(int n){
  int flag=0;
  p = head;
  while(p!=NULL){
    if(p->data==n){
      before = p;
      flag++;
      break;
    }
    p=p->next;
  }
  if(flag==0)
    printf("Element not present\n");
  else{
    getelement();
    after = before->next;
    before->next = p;
    p->pre = before;
    p->next = after;
    after->pre = p;
  }
}

void insert_node_before(int n){
  int flag=0;
  p = head;
  while(p!=NULL){
    if(p->data==n){
      after = p;
      flag++;
      break;
    }
    p=p->next;
  }
  if(flag==0)
    printf("Element not present\n");
  else{
    getelement();
    before = after->pre;
    p->next = after;
    p->pre = before;
    before->next = p;
    after->pre = p;
  }
}

void delete_front(){
  if(head == NULL)
    printf("List is empty\n");
  else if(head!=tail){
    printf("Element %d deleted\n",head->data);
    p = head;
    head = head->next;
    head->pre = NULL;
    free(p);
  }
  else{
  		printf("Element %d deleted\n",head->data);
    	p = head;
    	head=NULL;
    	tail=NULL;
    	free(p);
  }
}

void delete_rear(){
  if(head == NULL)
    printf("List is empty\n");
  else if(head!=tail){
    printf("Element %d deleted\n", tail->data);
    p = tail;
    tail = tail->pre;
    tail->next = NULL;
    free(p);
  }
  else{
  		printf("Element %d deleted\n",head->data);
    	p = head;
    	head=NULL;
    	tail=NULL;
    	free(p);
  }
}

void delete_node(int n){
  if(head == NULL)
    printf("List is empty\n");
  else{
    p = head;
    int flag=0;
    while(p!=NULL){
      if(p->data == n){
        flag++;
        break;
      }
      p=p->next;
    }
    if(flag == 0)
      printf("Element not found in list\n");
    else{
      printf("Element %d deleted\n", n);
      after = p->next;
      before = p->pre;
      before->next = after;
      after->pre = before;
      free(p);
    }
  }
}

void display_forward(){
  if(head == NULL)
    printf("List is empty\n");
  else{
    p = head;
    while(p != NULL){
      printf("%d ", p->data);
      p = p->next;
    }
  }
  printf("\n");
}
void display_backward(){
  if(head == NULL)
    printf("List is empty\n");
  else{
    p = tail;
    while(p != NULL){
      printf("%d ", p->data);
      p = p->pre;
    }
  }
  printf("\n");
}

void main(){
  int i,n,opt;
  char ch;
  printf("\n1. Insert at beginning");
  printf("\n2. Insert at end");
  printf("\n3. Insert after a node");
  printf("\n4. Insert before a node");
  printf("\n5. Delete from beginning");
  printf("\n6. Delete from end");
  printf("\n7. Delete a node");
  printf("\n8. Display forward");
  printf("\n9. Display backward\n");
  do{
    printf("\nEnter your choice : ");
    scanf("%d", &opt);
    switch(opt){
      case 1 :
      	insert_front();
      	printf("\n");
	      break;
      case 2 :
        insert_rear();
        printf("\n");
        break;
      case 3 :
        printf("Enter the element after which you have to add : ");
        scanf("%d", &n);
        insert_node_after(n);
        printf("\n");
        break;
      case 4 :
        printf("Enter the element before which you have to add : ");
        scanf("%d", &n);
        insert_node_before(n);
        printf("\n");
        break;
      case 5 :
        delete_front();
        printf("\n");
        break;
      case 6 :
        delete_rear();
        printf("\n");
        break;
      case 7 :
        printf("Enter the element you want to delete : ");
        scanf("%d", &n);
        delete_node(n);
        printf("\n");
        break;
      case 8 :
        display_forward();
        printf("\n");
        break;
      case 9 :
        display_backward();
        printf("\n");
        break;
      default :
        printf("Invalid option\n");
    }
    printf("Do you want to continue(y/n) : ");
    scanf(" %c", &ch);
  }while(ch=='y'||ch=='Y');
}
