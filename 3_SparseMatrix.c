#include <stdio.h>
#define SIZE 20

void read(int op);
void transpose();
void addition();
void display_trans();
void display_sum();

int atf[SIZE][SIZE], btf[SIZE][SIZE], stf[SIZE][SIZE];
int m1, n1, t1;
int m2, n2, t2; 
int i, j;
int r=1;

void main(){
	int ch; char ct;
	do{
		// Operation Menu
		printf("1. Find the transpose of a matrix\n");
		printf("2. Find the sum of two matrices\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		printf("\n");
		switch(ch){
			case 1:
				read(ch);
				transpose();
				display_trans();
				break;
			case 2:
				read(ch);
				// Check whether number of rows and columns of both the matrices are equal 
				if(m1==m2 && n1==n2){
					addition();
					display_sum();
				}
				else
					printf("Matrix addition not possible");
				break;
			default:
				printf("Invalid choice");
				break;
		}
		printf("Do you wish to continue? (y/n) : ");
		scanf(" %c", &ct);
		printf("\n");
	}while(ct=='Y' || ct=='y');
}

void read(int op){
    // Accept required input for matrix A
    printf("Enter the number of rows in the sparce matrix A: ");
    scanf("%d", &m1);
    printf("Enter the number of columns in the sparce matrix A: ");
    scanf("%d", &n1);
    printf("Enter the total number of non-zero elements in matrix A: ");
    scanf("%d", &t1);
    // Accepting the triple form matrix of A
    atf[0][0]=m1; atf[0][1]=n1; atf[0][2]=t1;
    printf("Enter the triple form matrix: \n");
    for(i=1; i<=t1; i++)
        for(j=0; j<3; j++)
            scanf("%d", &atf[i][j]);
    if(op==2){
		 // Accept required input for matrix B
		 printf("Enter the number of rows in the sparce matrix B: ");
		 scanf("%d", &m2);
		 printf("Enter the number of columns in the sparce matrix B: ");
		 scanf("%d", &n2);
		 printf("Enter the total number of non-zero elements in matrix B: ");
		 scanf("%d", &t2);
		 // Accepting the triple form matrix of A
		 btf[0][0]=m2; btf[0][1]=n2; btf[0][2]=t2;
		 printf("Enter the triple form matrix: \n");
		 for(i=1; i<=t2; i++)
		     for(j=0; j<3; j++)
		         scanf("%d", &btf[i][j]);
    }
}
void transpose(){
	int c=1; 
	btf[0][0]=n1; btf[0][1]=m1; btf[0][2]=t1;
    for(i=0; i<n1; i++){
        for(j=1; j<=t1; j++){
            if(atf[j][1]==i){
                btf[c][0]=atf[j][1];
                btf[c][1]=atf[j][0];
                btf[c][2]=atf[j][2];
                c+=1;
            }
        }
    }
}
void addition(){
	int p=1, q=1;
	while(p<=t1 && q<=t2){
			// Both rows are same
   		if(atf[p][0]==btf[q][0]){
   			//Both columns are same
				if(atf[p][1]==btf[q][1]){
                stf[r][0]=atf[p][0];
                stf[r][1]=atf[p][1];
                stf[r][2]=atf[p][2]+btf[q][2];
                p++; q++; r++;
            }
            // Row same, column of matrix A less than column of matrix B
            else if(atf[p][1]<btf[q][1]){
                stf[r][0]=atf[p][0];
                stf[r][1]=atf[p][1];
                stf[r][2]=atf[p][2];
                p++; r++;
            }
            // Row same, column of matrix B less than column of matrix A
            else{
                stf[r][0]=btf[q][0];
                stf[r][1]=btf[q][1];
                stf[r][2]=btf[q][2];
                q++; r++;
            }
        }
        // Row of matrix A less than row of matrix B
        else if(atf[p][0]<btf[q][0]){
            stf[r][0]=atf[p][0];
            stf[r][1]=atf[p][1];
            stf[r][2]=atf[p][2];
            p++; r++;
        }
        // Row of matrix B less than row of matrix A
        else{
            stf[r][0]=btf[q][0];
            stf[r][1]=btf[q][1];
            stf[r][2]=btf[q][2];
            q++; r++;
        }
    }
    // Remaining elements in matrix A
    while(p<=t1){
        stf[r][0]=atf[p][0];
        stf[r][1]=atf[p][1];
        stf[r][2]=atf[p][2];
        p++; r++;
    }
    // Remaining elements in matrix B 
    while(q<=t2){
        stf[r][0]=btf[q][0];
        stf[r][1]=btf[q][1];
        stf[r][2]=btf[q][2];
        q++; r++;
    }
    stf[0][0]=m1; stf[0][1]=n1;stf[0][2]=r-1;
}
void display_trans(){
	printf("Triple form of transpose matrix: \n");
    for(i=0; i<=t1; i++){
        for(j=0; j<3; j++)
            printf("%d ", btf[i][j]);
        printf("\n");
    }
}
void display_sum(){
	printf("The sum of two matrices is: \n");
	for(i=0; i<r; i++){
        for(j=0; j<3; j++)
            printf("%d ", stf[i][j]);
        printf("\n");
    }
}
