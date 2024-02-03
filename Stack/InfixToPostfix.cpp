#include <iostream>
#include <stack>
using namespace std;

int Precedence(char c)
{
    if(c=='-' || c=='+')
        return 1;
    if(c=='*' || c=='/')
        return 2;
    if(c=='^' || c=='!')
        return 3;
    else
        return -1;
}

bool isOperator(char c)
{
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
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
        else if(isOperator(eq[i]))
        {
            while(!s.empty() && Precedence(eq[i]) <= Precedence(s.top()))
            {
                ans += s.top();
                s.pop();
            }
            s.push(eq[i]);
        }
    }
    while(!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    cout<<'\n'<<ans<<'\n'<<endl;

}

main()
{
    string infix = "a+b*c-d^f/e";
    toPostfix(infix);

}


// else if(isOperator(eq[i]))
        // {
        //     if(!s.empty())
        //     {
        //         if(Precedence(eq[i]) > Precedence(s.top()))
        //         {
        //             s.push(eq[i]);
        //         }
        //         else
        //         {
        //             while(!s.empty() && Precedence(eq[i]) <= Precedence(s.top()))
        //             {
        //                 ans += s.top();
        //                 s.pop();
        //             }
        //             s.push(eq[i]);
        //         }
        //     }
        //     else
        //     {
        //         s.push(eq[i]);
        //     }
        // }