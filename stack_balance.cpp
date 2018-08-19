#include<iostream>
using namespace std;

bool is_balanced(string s)
{
    int l = s.length();
    int top = 0;
    char last_char;

    for(int i=0;i<l;i++)
    {
        if(s[i]=='(')
        {
            s[top] = s[i];
            top++;
        }

        else if(s[i]==')')
        {
            if(top==0)
            {
                return false;
            }

            top--;

            last_char = s[top];

            if(last_char!='(')
            {
                return false;
            }
        }
    }

    if(top==0)
    {
        return true;
    }

    else return false;
}

int main(void)
{
    string s;
    cin >> s;

    if(is_balanced(s)) cout << "Balanced" << endl;
    else cout << "Not balanced" << endl;

    return 0;
}
