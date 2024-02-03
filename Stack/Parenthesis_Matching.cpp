#include <iostream>
#include <stack>
using namespace std;

bool Parenthesis_Matching(string eq)
{
    stack <char> s;
    for(int i=0;eq[i]!='\0';i++)
    {
        if(eq[i]=='(')
        {
            s.push('(');
        }
        if(eq[i]==')')
        {
            if(s.empty()) return false;
            s.pop();
        }
    }
    return s.empty();
}

bool isBalanced(string eq)
{
    stack <char> s;
    for(int i=0;eq[i]!='\0';i++)
    {
        if(eq[i]=='(' || eq[i]=='[' || eq[i]=='{')
        {
            s.push(eq[i]);
        }

        if(eq[i]==')' || eq[i]==']' || eq[i]=='}' )
        {
            if(s.empty()) 
                return false;
            
            if(eq[i]==')' && s.top()=='(') 
                s.pop();            
            else if(s.top()==eq[i]-2)
                s.pop();
            else
                return false;
        }
    }
    return s.empty();
}

int main()
{
    string equation = "{a+b*([c*d]-(e/f))}";

    // if(Parenthesis_Matching(equation))
    //     cout<<"\nParenthesis are Matching\n"<<endl;
    // else
    //     cout<<"\nParenthesis are not Matching\n"<<endl;

    if(isBalanced(equation))
        cout<<"\nAll Brackets  '('   ,')'  ,'['   ,']'  ,'{' and '}' are Matching\n"<<endl;
    else
        cout<<"\nAll Breackets  '('   ,')'  ,'['   ,']'  ,'{' and '}' are not Matching\n"<<endl;
}