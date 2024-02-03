#include <iostream>
#include <stack>
#include <string>
using namespace std;

int Precedence(char c)
{
    if(c=='-' || c=='+')
        return 1;
    if(c=='*' || c=='/')
        return 2;
    if(c=='^' || c=='!')
        return 3;

    return -1;           //This is basicly for Brackets -> ()
}

bool isOperator(char c)
{
    return (c=='+' || c=='-' || c=='*' || c=='/' );
}

bool isUnary(char c)
{
    return (c=='^' || c=='!' );
}

void toPostfix(string eq)
{
    stack <char> s;
    string ans = "";

    for(int i=0; eq[i]!='\0'; i++)
    {
        if(isalnum(eq[i]))
        {
            ans += eq[i];
        }
        else if(eq[i]=='(')
        {
            s.push(eq[i]);
        }
        else if(eq[i]==')')
        {
            while(s.top()!='(')
            {
                ans += s.top();
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(eq[i]))
        {
            while(!s.empty() && Precedence(eq[i]) <= Precedence(s.top()))
            {
                ans += s.top();
                s.pop();
            }
            s.push(eq[i]);
        }
        else if(isUnary(eq[i]))
        {
            s.push(eq[i]);
        }
    }
    while(!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    ans += '\0';
    cout<<'\n'<<ans<<'\n'<<endl;
}


int main()
{
    string infix = "((a+b)*c)-d^e^f!";          //"(a+b)*c-d^f^g!/e"
    toPostfix(infix);

}
