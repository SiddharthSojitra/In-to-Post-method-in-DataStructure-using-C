#define MAX 10
typedef struct
{
    int data[MAX];
    int top;
}STACK;

void init(STACK *s)
{
    s->top=-1;
    //printf("\nstack initialized");
}

int isempty(STACK *s)
{
    if(s->top==-1)
    {
        //printf("stack is empty");
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(STACK *s,int val)
{
    if(s->top==MAX-1)
    {
       // printf("\nStack is full");
    }
    else
    {
        s->top++;
        s->data[s->top]=val;
        //printf("\nvalue %d inserted",val);
    }
}
int pop(STACK *s)
{
    int val=NULL;
    if(s->top==-1)
    {
        //printf("\nStack is empty");
    }
    else
    {
        val=s->data[s->top];
        s->top--;
    }
    return val;
}
int peep(STACK *s)
{
    int val=NULL;
    if(s->top==-1)
    {
        //printf("\nstack is empty");
    }
    else
    {
        val=s->data[s->top];
    }
    return val;
}
int display(STACK *s)
{
    int i;
    if(s->top==-1)
    {
        //printf("\nStack is empty");
    }
    else
    {
        for(i=s->top;i>=0;i--)
        {
            printf("%c",s->data[i]);
        }
    }
}

/*
void change(STACK *s)
{
    int pos,val,i;
    printf("\nenter position of element and element to change=");
    scanf("%d",&pos);
    printf("\nenter other value=");
    scanf("%d",&val);
    if(s->top==-1)
    {
        printf("\nstack is empty");
    }
    else
    {
        i=s->top-(pos-1);
        if(i>=0&&i<=s->top)
        {
            s->data[i]=val;
        }
        else
        {
            printf("invalid position");
        }
    }
}*/

