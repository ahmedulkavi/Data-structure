#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head;
Node *tail;

void create_ll()
{
    head = NULL;
    tail = NULL;
}

Node* create_node(int item)
{
    Node *node = new Node;
    node->data = item;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void prepend()
{
    cout << "Enter the value:" << endl;

    int item;

    cin >> item;

    Node *node = create_node(item);

    if(head==NULL && tail==NULL)
    {
        head = node;
        tail = node;
    }

    else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void append(void)
{
    cout << "Enter the value:" << endl;

    int item;

    cin >> item;

    Node *node = create_node(item);

    if(head==NULL && tail==NULL)
    {
        head = node;
        tail = node;
    }

    else
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

Node* search_node(int item)
{
    for(Node *node = head;node!=NULL;node=node->next)
    {
        if(node->data==item)return node;
    }

    return NULL;
}

void insertAfter(void)
{
    int ind,item;

    cout << "Enter the previous value:" << endl;
    cin >> ind;

    Node *prev_node = search_node(ind);
    if(prev_node==NULL)
    {
        cout << "Not found" << endl;
        return;
    }

    cout << "Enter the value:" << endl;

    cin >> item;

    Node *node = create_node(item);

    node->prev = prev_node;
    node->next = prev_node->next;
    prev_node->next->prev = node;
    prev_node->next = node;
}

void delete_node()
{
    int item;

    cout << "Enter the value you want to delete:" << endl;

    cin >> item;

    Node *node = search_node(item);

    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete [] node;
}

void traverseForward()
{
    for(Node *node=head;node!=NULL;node=node->next)
    {
        cout << node->data << " ";
    }

    cout << endl;
}

void traverseBackward()
{
    for(Node *node=tail;node!=NULL;node=node->prev)
    {
        cout << node->data << " ";
    }

    cout << endl;
}

void free_node()
{
    for(Node *node=head;node!=NULL; )
    {
        Node *temp = node->next;
        delete [] node;
        //cout << "del" << endl;
        node = temp;
    }
}

void choose(int c)
{
    if(c==1) traverseForward();
    else if(c==2) traverseBackward();
    else if(c==3) append();
    else if(c==4) prepend();
    else if(c==5) delete_node();
    else if(c==6) insertAfter();
    else cout << "Invalid input" << endl;
}

void menu(void)
{
    while(true)
    {
        int c;
        cout << "What do you want to do?" << endl;
        cout << "1.Traverse forward\n2.Traverse Backward\n3.Append\n4.Prepend\n5.Delete\n6.Insert\n7.Quit\n";
        cin >> c;
        if(c==7)return;
        choose(c);

    }
}
int main(void)
{
    create_ll();

    menu();

    free_node();

    return 0;
}
