#include <bits/stdc++.h>
using namespace std;

struct node{int data;struct node* next;};

typedef struct node node;

node* create_node(int item,node* next)
{
    node *new_node = (node*)malloc(sizeof(node));

    if(new_node==NULL)
    {
        cout << "Error!" << endl;
        exit(1);
    }

    new_node -> data = item;
    new_node -> next = next;

    return new_node;
}

node* prepend(node *head, int item)
{
    node *new_node= create_node(item,head);

    return new_node;
}


node* append(node *head,int item)
{
    node* new_node = create_node(item,NULL);

    if(head == NULL)
    {
        return new_node;
    }

    node *current_node = head;

    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;

    return head;
}

node *insert(node *head,int prev_data,int item)
{
    if(head==NULL)
    {
        append(head,item);
        return head;
    }

    node *current_node = head;

    while(current_node->data!=prev_data)
    {
        current_node = current_node->next;
    }

    node *new_node = create_node(item,current_node->next);

    current_node->next = new_node;

    return head;
}

void print_linked_list(node *head)
{
    node *current_node = head;

    while(current_node!=NULL)
    {
        cout << current_node->data << " ";
        current_node = current_node ->next;
    }

    cout << endl;
}

int count(node *head)
{
    int c = 0;

    node *current_node = head;

    while(current_node!=NULL)
    {
        c++;
        current_node = current_node->next;
    }

    return c;
}

node *remove_node(node *head,int item)
{
    node *current_node = head;

    if(head->data==item)
    {
        head = head->next;
        return head;
    }

    while(current_node->next->data!=item)
    {
        current_node = current_node->next;
    }

    current_node->next = current_node->next->next;

    return head;
}


int main()
{
    node *n1,*head;

    int d,e,choice;

    cout << "Enter the first data:" << endl;

    cin >> d;

    n1 = create_node(d,NULL);

    head = n1;

    while(true)
    {
        cout << "What do you want to do?" << endl;

        cout << "1.Prepend\n2.Append\n3.Insert\n4.Remove\n5.Print\n6.Quit" << endl;

        cin >> choice;

        if(choice==1)
        {
            cout << "Enter the value:" << endl;
            cin >> d;
            head = prepend(head,d);
        }

        else if(choice==2)
        {
            cout << "Enter the value:" << endl;
            cin >> d;
            head = append(head,d);
        }

        else if(choice==3)
        {
            cout << "Enter previous data:" << endl;
            cin >> e;
            cout << "Enter the value:" << endl;
            cin >> d;
            head = insert(head,e,d);
        }

        else if(choice==4)
        {
            cout << "Enter the value:" << endl;
            cin >> d;
            head = remove_node(head,d);
        }

        else if(choice==5)
        {
            print_linked_list(head);
        }

        else if(choice==6)
        {
            break;
        }

        else
        {
            cout << "Invalid Input!" << endl;
        }
    }

	return 0;
}
