#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *left, *right;
} *root=NULL;

void insert(int val)
{
    struct node *newnode, *nodeptr, *baseptr;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = val;
    newnode->left = NULL;
    newnode->right = NULL;

    if(root==NULL)
        root=newnode;
    else
    {
        baseptr=NULL;
        nodeptr=root;
        while(nodeptr!=NULL)
        {
            baseptr=nodeptr;
            if(val < nodeptr->info)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if(val < baseptr->info)
            baseptr->left = newnode;
        else
            baseptr->right = newnode;
    }
}

void inorder(struct node* ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d ", ptr->info);
        inorder(ptr->right);
    }
}

void preorder(struct node* ptr)
{
    if(ptr!=NULL)
    {
        printf("%d ", ptr->info);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node* ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->info);
    }
}

struct node* inordersuccessor(struct node* ptr)
{
    while(ptr!=NULL && ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

struct node* delete(struct node* root, int val)
{
    struct node* temp;

    if(root==NULL)
        printf("Node not found.");
    else if(val < root->info)
        root->left = delete(root->left, val);
    else if(val > root->info)
        root->right = delete(root->right, val);
    else
    {
        if(root->left != NULL && root->right != NULL)
        {
            temp = inordersuccessor(root->right);
            root->info = temp->info;
            root->right = delete(root->right, temp->info);
        }
        else
        {
            temp=root;

            if(root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }    
            else if(root->left != NULL)
                root = root->left;
            else
                root = root->right;
            free(temp);
        }
    }
    return root;
}

struct node* search(struct node* root, int val)
{
    if(root==NULL || root->info == val)
        return root;
    else if(val > root->info)
        return search(root->right, val);
    else
        return search(root->left, val);
}


void main()
{
    int elm, ch;
    char ctn;

    do
    {
        if(root == NULL)
            printf("\nEnter value of root (-1 to exit): ");
        else
            printf("Enter value of node (-1 to exit): ");
       
        scanf("%d", &elm);

        if(elm != -1)
            insert(elm);
    }while(elm != -1);

    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Preorder traversal");
        printf("\n5. Inorder traversal");
        printf("\n6. Postorder traversal\n");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: 
            	printf("Enter node to be inserted: ");
               scanf("%d", &elm);
               insert(elm);
               printf("\n");
               break;
            case 2: 
            	if(root != NULL)
               {
               	printf("Enter node to be deleted: ");
                  scanf("%d", &elm);
                  root = delete(root, elm);
               }
               else
                  printf("Tree is empty.");
               printf("\n");
               break;
            case 3:
            	printf("Enter node to be searched: ");
 				   scanf("%d", &elm);
			      if(search(root, elm) != NULL)
                  printf("Node found.");
               else
            	   printf("Node not found.");
            	printf("\n");
               break;
            case 4:
            	if(root != NULL)
               {
               	printf("Preorder traversal: ");
                  preorder(root);
               }
               else
               	printf("Tree is empty.");
               printf("\n");
					break;
            case 5:
            	if(root != NULL)
               {
	               printf("Inorder traversal: ");
                  inorder(root);
               }
               else
                  printf("Tree is empty.");
               printf("\n");
					break;
            case 6:
            	if(root != NULL)
               {
	               printf("Postorder traversal: ");
                  postorder(root);
               }
               else
		            printf("Tree is empty.");
		         printf("\n");
               break;
        }
        printf("\nDo you wish to continue? (y/n): ");
        scanf(" %c", &ctn);
    }while(ctn=='Y' || ctn=='y');    
}
