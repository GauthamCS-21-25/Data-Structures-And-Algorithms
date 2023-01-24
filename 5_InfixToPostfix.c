#define SIZE 50

#include <stdio.h>
#include <string.h>

void main(){

    /* i_exp is the infix expression, p_exp is the postfix expression
    stack is used to store operators while conversion, var used to store the variables in the expression */
    char i_exp[SIZE], p_exp[SIZE], stack[SIZE/2], var[SIZE/2];

    // val used to store the value of each variables, operand used to store operands while evaluating the postfix expression
    int val[SIZE/2]; float operand[SIZE/2];

    // top is the top element in the stack, pos is the postion/ index of postfix expression array, len is the length of the expression
    int top=-1; int pos=0, len;

    // operator is the array of all possible operators present in an expression, priority is the array of priority of operators corresponding to the index
    char operator[] = {'(','^', '/', '*', '+', '-', ')'};
    int priority[] = {0, 3, 2, 2, 1, 1, 0};

    /* term is the next term/element in the expression, is_Operator is used to check whether term is an operator or not
    isp : In Stack Priority, icp: In Coming Priority */
    char term; int is_Operator=0, index, isp, icp;

    // navar is the number of variables present in the expression, t1 is the first operand and t2 is the second operand while evaluating postfix expression
    int nvar; float t1, t2;

    int choice; char ch;
    
    do{
        printf("1. Convert infix expression to postfix expression\n");
        printf("2. Evaluavte postfix expression\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        // Infix to Postfix expression conversion
        if(choice==1){
            printf("Enter the infix expression: ");
            scanf("%s", i_exp);

            // Compute the length of the expression
            len=strlen(i_exp);
            
            printf("\nTerm\tStack\tOutput\n");
            
            for(int i=0; i<len; i++){
                term=i_exp[i];  // term in the infix expression
                for(int j=0; j<7; j++)  // loop to check whether the term is an operator or not
                    if(term==operator[j]){
                        is_Operator=1;  // if the term is an operator then store its index
                        index=j;
                        break;
                    }
                if(is_Operator==0)  // if term is not an operator then the term must be a variable, hence push it to postfix expression
                    p_exp[pos++]=term;
                else{
                    if(term=='(')   // if term is an opening brace, then push it to the stack
                        stack[++top]=term;
                    else if(term==')'){     // if the term is a closing brace, then push the element at stack[top] to postfix expression
                        p_exp[pos++]=stack[top--];
                        top--;
                    }
                    else if(top==-1)    // if stack is empty, then push the operator to the stack
                        stack[++top]=term;

                    // if the stack is not empty, then the priority of the element in the stack and element coming is to be calculated.
                    else{   
                        for(int j=0; j<7; j++)  // Compute the in coming priority
                            if(term==operator[j]){
                                icp=j;
                                break;
                            }
                        for(int j=0; j<7; j++)  // Compute the in stack priority
                            if(stack[top]==operator[j]){
                                isp=j;
                                break;
                            }
                        if(priority[icp]>priority[isp]) // if in-coming priority is greater than in-stack priority, then push the operator to the stack
                            stack[++top]=term;
                        else{   // pop the elements from the stack and push to postfix expression
                            while(top>=0){  
                                if(stack[top]!='(' && stack[top]!=')')
                                    p_exp[pos++]=stack[top];
                                top--;
                            }    
                            stack[++top]=term;  // then push the term to the stack
                        }     
                    }              
                }
                is_Operator=0;  // reset is_Operator

                // Print the stack table
                printf("%c\t", term);
                for(int x=0; x<=top; x++)
                    printf("%c", stack[x]);
                printf("\t%s\n", p_exp);    
            }

            // Pop the rest of the operators from the stack and push it to postfix expression
            while(top>=0){
                if(stack[top]!='(' && stack[top]!=')')
                    p_exp[pos++]=stack[top];           
                top--;
                
                // Print the stack table
                printf("\t");
                for(int x=0; x<=top; x++)
                    printf("%c", stack[x]);
                printf("\t%s\n", p_exp);   
            }
            printf("\nPostfix Expression: %s \n", p_exp);
        }
        
        top=-1; pos=0;  // reset top and pos

        // Postfix expression evaluation
        if(choice==2){
            printf("How many variables are present in the expression? ");
            scanf("%d", &nvar);     // accept the number of variables present in the expression
            printf("Enter the variable(s) and their value(s): \n");
            for(int i=0; i<nvar; i++)
                scanf(" %c %d", &var[i], &val[i]);      // accept the variable and it's value if a+b => 1+2 then input will be a 1 b 2
            len=strlen(p_exp);      // length of the postfix expression
            
            for(int i=0; i<len; i++){
                term=p_exp[i];  
                for(int j=1; j<6; j++)  // loop to check whether the term is an operator or not
                    if(term==operator[j]){
                        is_Operator=1;  // if the thern is an operator, then store its index
                        index=j;
                        break;
                    }
                if(is_Operator!=1){     // if the term is not an operator i.e it is an operand, then take its value and push it to operand
                    for(int j=0; j<nvar; j++)
                        if(term==var[j]){   // to get the value of the variable
                            operand[++top]=val[j];
                            break;
                        }
                }

                // else the term is an operator, then compute the operation eith the operands in the stack and then push it to operand
                else{
                    t1=operand[top--];  // pop the first operand
                    t2=operand[top--];  // pop the second operand

                    // Perform the operation
                    if(term=='/')
                        operand[++top]=t2/t1;
                    else if(term=='*')
                        operand[++top]=t2*t1;
                    if(term=='+')
                        operand[++top]=t2+t1;
                    if(term=='-')
                        operand[++top]=t2-t1;
                }
                is_Operator=0;  // reset is_Operator
            }
            printf("Result: %.2f", operand[top]);   // Print result
        }
        
        top=-1; pos=0;  // reset top and pos
        
        if(choice!=1 && choice!=2)  // if choice is invalid
        		printf("Invalid input\n");
        
        printf("\nDo you wish to continue (y/n)? ");    // whether the use wants to continue execution or not
        scanf(" %c", &ch);
        printf("\n");
    }while(ch=='y'||ch=='Y');
}