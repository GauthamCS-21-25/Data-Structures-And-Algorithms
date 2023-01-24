#include <stdio.h>
#define SIZE 20
void main(){
	int a[SIZE], b[SIZE], c[SIZE];
	int m, n;
	int p=1, q=1, r=1;
	int pflag=0, qflag=0;
	
	printf("Enter the number of terms in the first expression: ");
	scanf("%d", &m);
	a[0]=m;
	printf("Enter the expression according to the specific format: \n");
	for(int i=1; i<((m*2)+1); i++)
		scanf("%d", &a[i]);
		
	printf("Enter the number of terms in the second expression: ");
	scanf("%d", &n);
	b[0]=n;
	printf("Enter the expression according to the specific format: \n");
	for(int i=1; i<((n*2)+1); i++)
		scanf("%d", &b[i]);
			
	while(p<2*m+1 || q<2*n+1){
		if(a[p]==b[q]){
			c[r]=a[p];
			c[r+1]=a[p+1]+b[q+1];
			p+=2; q+=2; r+=2;
		}
		else if(a[p]>b[q]){
			c[r]=a[p];
			c[r+1]=a[p+1];
			p+=2; r+=2;
		}
		else{
			c[r]=b[q];
			c[r+1]=b[q+1];
			q+=2; r+=2;
		}		
	}
	
	while(p<=2*m){
		c[r]=a[p];
		c[r+1]=a[p+1];
		p+=2; r+=2;
	}
	while(q<=2*n){
		c[r]=b[q];
		c[r+1]=b[q+1];
		q+=2; r+=2;
	}
	
	c[0]=(r-1)/2;
	
	printf("Expression 1: ");
	for(int i=1; i<((m*2)+1); i+=2){
		printf("%dx^%d", a[i+1], a[i]);
		if(i!=2*m-1)
			printf("+");
	}
	printf("\n");
	
	printf("Expression 2: ");
	for(int i=1; i<((n*2)+1); i+=2){
		printf("%dx^%d", b[i+1], b[i]);
		if(i!=2*n-1)
			printf("+");
	}
	printf("\n");
	
	printf("Result: ");
	for(int i=1; i<r; i+=2){
		printf("%dx^%d", c[i+1], c[i]);
		if(i!=r-2)
			printf("+");
	}
	printf("\n");
	
	/*printf("The sum of polynomial expresiion is represented as: ");
	for(int i=0; i<=r-1; i++)
		printf("%d ", c[i]);
	printf("\n");*/
}
