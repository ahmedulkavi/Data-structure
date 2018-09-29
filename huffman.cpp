#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

struct block
{
    char info;
    int freq;
    int iValue;

    bool operator<(block const &k) const
    {
        if(freq==k.freq) return info < k.info;
        return freq < k.freq;
    }
};

struct codedBlock
{
    char info;
    string code;
};

block blocks0[128];

block *blocks;

int cnt = 0;

struct node
{
    block mes;
    node *left;
    node *right;
    node *parent;
};

node *root = NULL;

node** tree;

int avail;

int left(int i)
{
    return 2*i + 1;
}

int right(int i)
{
    return 2*i +2;
}

void min_heapify(block *heap, int &heap_size, int i)
{
    int l,r, smallest;

    l = left(i);

    r = right(i);

    if(l<=heap_size && heap[l] < heap[i])
    {
        smallest = l;
    }

    else
    {
        smallest = i;
    }

    if(r <= heap_size && heap[r] < heap[smallest])
    {
        smallest = r;
    }

    if(smallest!=i)
    {
        swap(heap[i],heap[smallest]);
        min_heapify(heap,heap_size,smallest);
    }
}

void insert(block *heap,int &heap_size,block in)
{
    heap_size++;
    heap[heap_size] = in;

    for(int i=heap_size/2;i>=0;i--)
    {
        min_heapify(heap,heap_size,i);
    }
}

void print_heap(block *heap,int heap_size)
{
    for(int i=0;i<=heap_size;i++)
    {
        cout << heap[i].info << " " << heap[i].freq << " " << heap[i].iValue << endl;
    }

    cout << endl;
}

block extract(block *heap,int &heap_size)
{
    block min_item = heap[0];

    heap[0] = heap[heap_size];

    heap_size--;

    min_heapify(heap,heap_size,0);

    return min_item;
}

node* create_node(char in,int fr,int iv)
{
    node *n = new node;

    n->mes.info = in;
    n->mes.freq = fr;
    n->mes.iValue = iv;

    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;

    return n;
}


node* search_Inode(char in,int fr,int iv)
{
    for(int i=0;i<avail;i++)
    {
        if(tree[i]->mes.info==in && tree[i]->mes.freq==fr && tree[i]->mes.iValue==iv)
        {
            return tree[i];
        }
    }

    return NULL;
}

void create_tree(block *heap,int &heap_size)
{
    node *n,*n1,*p;
    int i = 0;

    tree = new node*[2*heap_size+1];

    avail = 0;

    block temp;

    for(int i=0;i<=heap_size;i++)
    {
        n = create_node(heap[i].info,heap[i].freq,heap[i].iValue);

        tree[i] = n;

        avail++;
    }

    while(heap_size!=-1)
    {
        temp = extract(heap,heap_size);

        if(heap_size==-1) break;

        n = search_Inode(temp.info,temp.freq,temp.iValue);

        if(n==NULL)
        {
            n = create_node(temp.info,temp.freq,temp.iValue);
            tree[avail] = n;
            avail++;
        }

        temp = extract(heap,heap_size);

        n1 = search_Inode(temp.info,temp.freq,temp.iValue);

        if(n1==NULL)
        {
            n1 = create_node(temp.info,temp.freq,temp.iValue);
            tree[avail] = n;
            avail++;
        }

        i++;

        p = create_node(char(127),n->mes.freq+n1->mes.freq,i);


        temp.info = p->mes.info;
        temp.freq = p->mes.freq;
        temp.iValue = p->mes.iValue;


        insert(heap,heap_size,temp);

        tree[avail] = p;
        avail++;

        p->left = n;
        p->right = n1;
        n->parent = p;
        n1->parent = p;
    }

    if(avail==1)
    {
        root = tree[0];
    }

    else root = p;
}

string generate_code(char in,int fr)
{
    string code = "";

    node *n = search_Inode(in,fr,0);

    //cout << n->mes.info << endl;

    if(n==root) return "0";

    while(n!=root)
    {

        if(n==n->parent->left) code+="0";

        else if(n==n->parent->right) code+="1";

        n = n->parent;
    }


    reverse(code.begin(),code.end());

    return code;
}

string decoder(string s2,codedBlock *c)
{
    string s3 = "",cmp ="";

    for(int i=0;i<s2.length();i++)
    {
        cmp+=s2[i];
        for(int j=0;j<cnt;j++)
        {
            if(cmp==c[j].code)
            {
                s3+=c[j].info;
                cmp = "";
            }
        }
    }

    return s3;
}

void pre_order(node *n)
{
    if(n==NULL) return;

    cout << n->mes.freq << " " ;

    pre_order(n->left);

    pre_order(n->right);
}

int main(void)
{
    string s,s1,s2 = "",s3;

    cout << "Enter the text you want to encode:" << endl;

    getline(cin,s);

    cout << endl;

    for(int i=0;i<128;i++)
    {
        blocks0[i].info = char(i);
        blocks0[i].freq = 0;
        blocks0[i].iValue = 0;
    }

    for(int i=0;i<s.length();i++)
    {
        blocks0[int(s[i])].freq++;
    }

    for(int i=0;i<128;i++)
    {
        if(blocks0[i].freq!=0) cnt++;
    }

    blocks = new block[cnt];

    for(int i=0,j=0;i<128;i++)
    {
        if(blocks0[i].freq!=0)
        {
            blocks[j].info = blocks0[i].info;
            blocks[j].freq = blocks0[i].freq;
            blocks[j].iValue = blocks0[i].iValue;
            j++;
        }
    }

    sort(blocks,blocks+cnt);

    block heap[cnt];

    int heap_size = -1;

    for(int i=0;i<cnt;i++)
    {
        insert(heap,heap_size,blocks[i]);
    }

    create_tree(heap,heap_size);

    codedBlock *codes = new codedBlock[cnt];

    //pre_order(root);

    for(int i=0;i<cnt;i++)
    {
        s1 = generate_code(blocks[i].info,blocks[i].freq);

        codes[i].info = blocks[i].info;
        codes[i].code = s1;
    }


    for(int i=0;i<cnt;i++)
    {
        cout << codes[i].info << " " << codes[i].code << endl;
    }

    cout << endl;

    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<cnt;j++)
        {
            if(s[i]==codes[j].info) s2+=codes[j].code;
        }
    }

    cout << "Encoded format:" << endl;

    cout << s2 << endl << endl;

    cout << endl;

    cout << "For decode, enter the exact code:" << endl;

    cin >> s3;

    if(s3==s2) cout << endl << "Decoded format:" << endl << decoder(s3,codes) << endl;

    else cout << "Wrong code" << endl;

    /*for(int i=0;i<cnt;i++)
    {
        cout << blocks[i].info << " " << blocks[i].freq << endl;
    }*/

    cout << endl;

    return 0;
}
