#include <bits/stdc++.h>
using namespace std;

typedef struct node node;

struct node{
  int data;
  node *left;
  node *right;
};

node *create_node(int item)
{
    node *new_node = (node*)malloc(sizeof(node));

    if(new_node==NULL)
    {
        cout << "Error" << endl;
        exit(1);
    }

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

node *search(node *n,int d)
{
    if(n->data==d)
        return n;

    if(n->left!=NULL)
    {
        search(n->left,d);
    }

    if(n->right!=NULL)
    {
        search(n->right,d);
    }

    return n;
}

void add_left_child(node *n)
{
    int p,c;

    cout << "Enter the value of parent:" << endl;

    cin >> p;

    cout << "Enter the value of child:" << endl;

    cin >> c;

    node *child = create_node(c);

    node *parent = search(n,p);


    parent->left = child;
}

void add_right_child(node *n)
{
    int p,c;

    cout << "Enter the value of parent:" << endl;

    cin >> p;

    cout << "Enter the value of child:" << endl;

    cin >> c;

    node *child = create_node(c);

    node *parent = search(n,p);


    parent->right = child;
}

node *create_tree(int d)
{
    node *root = create_node(d);

    return root;
}

void pre_order(node *n)
{
    cout << n->data << " ";

    if(n->left!=NULL)
    {
        pre_order(n->left);
    }

    if(n->right!=NULL)
    {
        pre_order(n->right);
    }
}

void post_order(node *n)
{
    if(n->left!=NULL)
    {
        post_order(n->left);
    }

    if(n->right!=NULL)
    {
        post_order(n->right);
    }

    cout << n->data << " ";
}

void in_order(node *n)
{
    if(n->left!=NULL)
    {
        in_order(n->left);
    }

    cout << n->data << " ";

    if(n->right!=NULL)
    {
        in_order(n->right);
    }
}

int main()
{
    int d,choice;

    node *root;

    cout << "Please enter value of root:" << endl;

    cin >> d;

    root = create_tree(d);

    for( ; ; )
    {
        cout << "What do you want to do?" << endl;

        cout << "1.Pre order traversal\n2.Post order traversal\n3.In order traversal\n4.Add left child\n5.Add right child\n6.Quit\n";

        cin >> choice;

        if(choice==1)
            {pre_order(root);
	    cout << endl;}

        else if(choice==2)
            {post_order(root);
	    cout << endl;}

        else if(choice==3)
            {in_order(root);
	    cout << endl;}

        else if(choice==4)
            add_left_child(root);

        else if(choice==5)
            add_right_child(root);

        else if(choice==6)
            break;

        else
        {
            cout << "Invalid Input!" << endl;


        }

    }

	return 0;
}
