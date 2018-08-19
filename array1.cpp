#include<iostream>
using namespace std;

int size = 10;

void initialize(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        a[i] = 5;
    }
    a[n-1] = 6;
}

bool is_filled(int n)
{
    if(n==size)return true;
    return false;
}

void expand(int *a,int &n)
{
    if(is_filled(n))
    {
        size*=2;
        int *new_arr = new int [size];
        int *b = new int [size];


        for(int i=0;i<n;i++)
        {
            b[i] = a[i];
        }

        delete [] a;

        new_arr = a;

        for(int i=0;i<n;i++)
        {
            new_arr[i] = b[i];
        }

        delete [] b;

        //return new_arr;

    }
}

void shrink(int *a,int &n)
{
    if(n<=size/2)
    {
        size/=2;
        int *new_arr = new int [size];
        int *b = new int [size];


        for(int i=0;i<n;i++)
        {
            b[i] = a[i];
        }

        //delete [] a;

        new_arr = a;

        for(int i=0;i<n;i++)
        {
            new_arr[i] = b[i];
        }

        delete [] b;

    }
}

void del(int *a,int &n)
{
    int index;

    cout << "Insert the index you want to delete:" << endl;

    cin >> index;

    a[index] = -1;
    for(int i=index;i<n;i++)
    {
        a[i] = a[i+1];
    }

    n--;

    shrink(a,n);
}

void bsort(int *a,int n)
{
    int t;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>=a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int search(int *a,int &n,int in)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==in)
        {
            return i;
        }
    }

    return -1;
}

void print(int *a,int n)
{
    //cout << a[0] << endl;

    for(int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            cout << a[i] << endl;
            return;
        }
        cout << a[i] << "\t";
    }
}

void append(int *a,int &n)
{
    expand(a,n);

    int in;

    cout << "Enter the value you want to append:" << endl;
    cin >> in;

    a[n] = in;
    n++;
}

void makespace(int *a,int in,int n)
{
    for(int i=n;i>in;i--)
    {
        a[i] = a[i-1];
    }

    a[in] = -1;
}

void prepend(int *a,int &n)
{
    expand(a,n);

    int in;
    makespace(a,0,n);

    cout << "Enter the value you want to prepend:" << endl;
    cin >> in;

    a[0] = in;
    n++;
}

void insert(int *a,int &n)
{
    expand(a,n);

    int ind,in,ch,v;

    cout << "1.Insert by index\n2.Insert by value" << endl;
    cin >> ch;

    if(ch==1)
    {
        cout << "Enter the previous index:" << endl;
        cin >> ind;

        makespace(a,ind+1,n);

        cout << "Enter the value you want to insert:" << endl;
        cin >> in;

        a[ind+1] = in;

        n++;
    }

    else if(ch==2)
    {
        cout << "Enter the previous value:" << endl;
        cin >> v;
        ind = search(a,n,v);

        if(ind==-1)
        {
            cout << "Value not found" << endl;
            return;
        }

        makespace(a,ind+1,n);

        cout << "Enter the value you want to insert:" << endl;
        cin >> in;

        a[ind+1] = in;
        n++;
    }

    else cout << "Invalid input" << endl;

}

void del_all(int *a,int &n)
{
	int in;
	cout << "Enter the value you want to delete:" << endl;
	cin >> in;

	int d = search(a,n,in);

	while(d!=-1)
	{
		for(int i=d;i<n;i++)
		{
			a[i]=a[i+1];
		}

		n--;

		d = search(a,n,in);
	}

	shrink(a,n);
}

void choose(int ch,int *a,int &n)
{
    if(ch==1)print(a,n);

    else if(ch==2)append(a,n);

    else if(ch==3)prepend(a,n);

    else if(ch==4)insert(a,n);

    else if(ch==5)del(a,n);

    else if(ch==6)bsort(a,n);

    else if(ch==7)
    {
        int in;
        cout << "Enter the value you want to search:" << endl;
        cin >> in;

        int k=search(a,n,in);
        if(k==-1) cout << "Not found" << endl;

        else cout << in << " found in index " << k << endl;
    }

    else if(ch==8)
    {
    	del_all(a,n);
    }

    else cout << "Invalid input" << endl;
}

void menu(int *a,int &n)
{
    int choice;

    while(true)
    {
        cout << "What do you want to do?\n1.Print\n2.Append\n3.Prepend\n4.Insert\n5.Delete\n6.Sort\n7.Search\n8.Delete all\n9.Quit\n";

        cin >> choice;

        if(choice==9)return;

        choose(choice,a,n);
    }

}

int main(void)
{
    int n;

    int *a = new int [size];

    n = 10;

    initialize(a,n);

    menu(a,n);

    delete [] a;

    return 0;
}
