#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v)
{
    vector<int>::iterator it;

    for(it=v.begin();it!=v.end();it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

void append(vector<int>&v)
{
    int in;

    cout << "Enter the value you want to append:" << endl;
    cin >> in;

    v.push_back(in);
}

void makespace(vector<int>&v,int in)
{
    v.push_back(v[v.size()-1]);
    for(int i=v.size()-1;i>0;i--)
    {
        v[i]=v[i-1];
    }

    v[in] = -1;

}

int search(vector<int>&v,int n)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==n) return i;
    }

    return -1;
}

void prepend(vector<int>&v)
{
    int in;

    cout << "Enter the value you want to prepend:" << endl;
    cin >> in;

    makespace(v,0);

    v[0] = in;
}

void insert(vector<int>&v)
{
    int ind,in;

    cout << "Enter previous index:" << endl;
    cin >> ind;
    cout << "Enter the value:" << endl;
    cin >> in;

    makespace(v,ind+1);
    v[ind+1] = in;
}

void del_all(vector<int>&v)
{
    int in,d;
    cout << "Enter the value you want to delete:" << endl;
    cin >> in;

    d = search(v,in);

    while(d!=-1)
    {
        v.erase(v.begin()+d);
        d = search(v,in);
    }
}

void choose(vector<int>&v,int c)
{
    if(c==1) print(v);
    else if(c==2) append(v);
    else if(c==3) prepend(v);
    else if(c==4) del_all(v);
    else if(c==5) insert(v);
    else cout << "Invalid input" << endl;
}

void menu(vector<int>&v)
{
    while(true)
    {
        int c;
        cout << "What do you want to do?" << endl;
        cout << "1.Print\n2.Append\n3.Prepend\n4.Delete all\n5.Insert\n6.Quit\n";
        cin >> c;
        if(c==6)return;
        choose(v,c);

    }
}

int main(void)
{
    vector<int> v;

    for(int i=0;i<5;i++)
    {
        v.push_back(i+1);
    }

    menu(v);

    return 0;
}
