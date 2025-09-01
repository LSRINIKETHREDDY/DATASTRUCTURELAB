#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define max 100

char stack[max];
int top = -1;

void push(char c)
 {
    if (top < max - 1) 
	{
        stack[++top] = c;
    }
}

char pop()
 {
    if (top != -1) 
	{
        return stack[top--];
    }

    return '\0'; 
}

char peek() 
{
    if (top != -1)
   {
        return stack[top];
    }
    
    return '\0'; 
}

int precedence(char op) 
{
    switch(op) 
	{
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int isoperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

void infinixtopostfix(char infinix[], char postfix[]) 
{
    int i, k = 0;
    char symbol;
    
    for (i = 0; i < strlen(infinix); i++) 
	{
        symbol = infinix[i];
        
        if (isalnum(symbol)) 
		{
            postfix[k++] = symbol;
        } else if (symbol == '(') 
		{
            push(symbol);
        } else if (symbol == ')') 
		{
            while (peek() != '\0' && peek() != '(') 
			{
                postfix[k++] = pop();
            }
            if (peek() == '(') 
			{
                pop(); 
            }
        } 
		else if (isoperator(symbol)) 
		{
            while (peek() != '\0' && precedence(peek()) >= precedence(symbol)) 
			{
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }
    
    while (peek() != '\0') 
	{
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; // Null-terminate the postfix string
}

int main() 
{
    char infinix[max], postfix[max];
    printf("Enter an infix expression: ");
    scanf("%s", infinix);
    
    infinixtopostfix(infinix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
