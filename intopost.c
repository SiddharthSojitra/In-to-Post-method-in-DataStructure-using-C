#include<stdio.h>
#include"Stack.h"

int getPrec(char ch)
{
    switch(ch)
    {
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' :
        case '%' : return 2;
        case '(' : return 0;
        default : return -1;
    }
}

int isOperator(char ch)
{
    if( ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void intopost(char *in, char *post)
{
    STACK s;
    char out[50]="";
    init(&s);
    char ch,op;
    int i=0;
    printf("================================\n");
    printf("\t INPUT \t STACK \t OUTPUT \n");
    printf("================================\n");

    while(*in!='\0')
    {
        if(*in=='(')
        {
            push(&s,*in);
        }
        else if(*in==')')
        {
            while((ch=pop(&s))!='(')
            {
                *post=ch;
                out[i]=*post;
                i++;
                post++;
            }
        }
        else if(isOperator(*in))
        {
            while(getPrec(*in)<=getPrec(peep(&s)))
            {
                ch=pop(&s);
                *post=ch;
                out[i]=*post;
                i++;
                post++;
            }
            push(&s,*in);
        }
        else
        {
            *post=*in;
            out[i]=*post;
            i++;
            post++;
        }
        printf("\t%c\t",*in);
        display(&s);
        printf("\t%s\n",out);
        in++;
    }

    while(!isempty(&s))
    {
        *post=pop(&s);
        out[i]=*post;
        i++;
        printf("\t%c\t",*in);
        display(&s);
        printf("\t%s\n",out);
        post++;
    }


*post='\0';

}

int main()
{
    char in[50], post[50];

    printf("Enter Mathematical Infix Equation \n");
    scanf("%s",in);

    intopost(&in,&post);

    printf("Postfix is %s",post);
    return 0;
}
