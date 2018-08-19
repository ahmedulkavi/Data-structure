#include<iostream>
using namespace std;

#define STACK_MAX 10

typedef struct
{
    int top;
    int data[STACK_MAX];
}Stack;

void push(Stack *s,int item)
{
    if(s->top < STACK_MAX)
    {
        s->data[s->top] = item;
        s->top++;
    }

    else cout << "Stack is full!" << endl;
}

void pop(Stack *s)
{
    int item;

    if(s->top == 0)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    else
    {
        s->top--;
        item = s->data[s->top];
    }

    return;
}

void print(Stack *s)
{
    if(s->data[s->top-1]==0)
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    for(int i=0;i<s->top;i++)
    {
        if(i==s->top-1)
        {
            cout << s->data[i] << endl;
            return;
        }

        cout << s->data[i] << " ";
    }

    return;
}

int main(void)
{
    Stack st;
    int item,ch,in;

    st.top = 0;

    while(true)
    {
        cout << "What do you want to do?\n1.Push\n2.Pop\n3.Print top\n4.Print\n5.Quit\n";
        cin >> ch;

        if(ch==1)
        {
            cout << "Enter the item:" << endl;
            cin >> in;
            push(&st,in);
        }

        else if(ch==2) pop(&st);

        else if(ch==3)
        {
            if(st.data[st.top-1]==0)
            {
                cout << "Stack is empty!" << endl;
                continue;
            }

            cout << st.data[st.top-1] << endl;
        }

        else if(ch==4) print(&st);

        else if(ch==5) break;

        else cout << "Invalid input" << endl;
    }

    return 0;
}
