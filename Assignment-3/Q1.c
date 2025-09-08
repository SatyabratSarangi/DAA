/*Conversion from infix to postfix expression*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char stack[100];
int top = -1,size;

void push(char element)
{
	if(top >= size-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = element;
	}
}
char pop()
{
	char element ;
	if(top <0)
	{
		printf("\nStack Underflow\n");
	}
	else
	{
		element = stack[top];
		top = top-1;
		return(element);
	}
}
int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix[], char postfix[])
{ 
	int i, j;
	char element;
	char x;

	push('(');                               
	strcat(infix,")");                  

	i=0;
	j=0;
	element=infix[i];         

	while(element != '\0')        
	{
		if(element == '(')
		{
			push(element);
		}
		else if( isdigit(element) || isalpha(element))
		{
			postfix[j] = element;              
			j++;
		}
		else if(is_operator(element) == 1)        
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(element))
			{
				postfix[j] = x;                  
				j++;
				x = pop();                       
			}
			push(x);

			push(element);                 
		}
		else if(element == ')')         
		{
			x = pop();                   
			while(x != '(')               
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");       
			exit(1);
		}
		i++;
		element = infix[i]; 
	}//End of while
	postfix[j] = '\0';
}
int main()
{
	char infix[30], postfix[30];         
	printf("Enter size of stack\n");
	scanf("%d",&size);
	printf("Enter Infix expression : \n");
	scanf(" %s",infix);
	InfixToPostfix(infix,postfix);                  
	printf("Postfix Expression: ");
	printf("%s",postfix);  
    return 0;                  
}