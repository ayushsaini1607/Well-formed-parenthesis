#include<stdio.h>
#include<process.h>

#define SIZE 20

#define true 1                        
#define false 0

char stack[SIZE];
int top=-1;                       

int isEmpty()
{
    if(top==-1)
       return true;                
    return false;
}

int isFull()
{
    if(top==SIZE-1)
       return true;
    return false;
}

void push(char c)
{
    if(isFull())
       {
           printf("\nStack Overflow!");
           return;
       }
    stack[++top]=c;
}

char pop()
{
   if(isEmpty())
     {
         printf("\nStack Underflow!");
         exit(-1);
     }
    return stack[top--]; 
}

int match(char c)
{
    if(isEmpty())
      return false;
    if(c==')' && pop()=='(')
       return true;
    if(c=='}' && pop()=='{')
       return true;
    if(c==']' && pop()=='[')
       return true;
    return false;
}

int wellFormed(char exp[])
{
   char temp;
   int i;
   for(i=0;exp[i]!='\0';i++)
    {
       switch(exp[i])
        {
            case '(':
            case '{':
            case '[':
                push(exp[i]);
                break;
            case ')':
            case '}':
            case ']':
               if(!match(exp[i]))
                  return false;
               break;
            default:
               continue;
        }
    }
    if(top!=-1)
       return false;
    return true;
}

int main()
{
    printf("\nWell formedness of parenthesis\n");
    char expression[SIZE];
    fflush(stdin);
    printf("\nEnter an expression that has parenthesis : ");
    gets(expression);
    if(wellFormed(expression))
      printf("\nValid expression, parenthesis rightly placed");
    else
      printf("\nInvalid expression, parenthesis are not rightly placed");
}