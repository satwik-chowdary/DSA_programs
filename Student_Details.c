/*
Write a C program to accept 20 student’s names, roll number and marks of three subjects then
display the average mark of three subjects as per given roll number. (Use array of structure)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char a)
{
    switch(a)
    {
        case '^':
            return 5;
            break;
        case '/':
            return 4;
            break;
            
        case '*':
            return 3;
            break;
            
        case '+':
            return 2;
            break;
        case '-':
            return 1;
            break;
    }
    
    return 0;
}

int main()
    {
	    char arr[100];
        printf("\nEnter an infix expression: ");
	    scanf("%s",arr);
	    int stop=-1;
	    int ptop=0;
	    char *postfix = NULL;
	    char *stack = NULL;
	    postfix = (malloc)(sizeof(100));
	    stack = (malloc)(sizeof(100));

	    for(int j=0;j<strlen(arr);j++)
        {
	        switch(arr[j])
            {
	            case '(':
	                stack[++stop] = arr[j];
	                break;
	                
	            case ')':
	                while(stack[stop] != '(' && stop!=-1)
                    {
	                    postfix[ptop++] = stack[stop];
	                    stop--;
	                }

	                stop--;
	                break;
	            
	            case '+':
	            case '-':
	            case '/':
	            case '*':
	            case '^':
	                while(precedence(arr[j]) <= precedence(stack[stop]) && stop!=-1)
                    {
	                    postfix[ptop++] = stack[stop--];
	                }

	                stack[++stop] = arr[j];
	                break;
	                
	            default:
	                postfix[ptop++] = arr[j];
	                break;
	        }
	    }

	    while(stop!=-1)
        {
	        postfix[ptop++] = stack[stop];
	        stop--;
	    }
		postfix[ptop] = '\0';
        printf("Equivalent postfix expression: ");
	    printf("%s\n",postfix);
        return 0;
    }

