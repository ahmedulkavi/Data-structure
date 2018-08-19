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


int main()
{
    node *n1,*head;

    n1 = create_node(10,NULL);

    head = n1;

    print_linked_list(head);

    head = prepend(head,20);

    print_linked_list(head);

    cout << count(head) << endl;

    head = append(head,30);

    print_linked_list(head);

    head = append(head,40);

    print_linked_list(head);

    head = prepend(head,9);

    print_linked_list(head);

    cout << count(head) << endl;

	return 0;
}
