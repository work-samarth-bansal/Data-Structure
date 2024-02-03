#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int Eval_Postfix(string eq)
{
    stack<int> s;
    s.push(0);

    for(int i=0; eq[i]!='\0';i++)
    {
        if(isdigit(eq[i]))
        {
            int num = eq[i] - '0';
            s.push(num);
        }
        else
        {
            int num1 = s.top();
            s.pop();
            int num2  = s.top();
            s.pop();

            if(eq[i]=='+')
            {
                int res = num2 + num1;
                s.push(res);
            }

            else if(eq[i]=='-')
            {
                int res = num2 - num1;
                s.push(res);
            }

            else if(eq[i]=='*')
            {
                int res = num2 * num1;
                s.push(res);
            }

            else if(eq[i]=='/')
            {
                if (num1 != 0) {
                    int res = num2 / num1;
                    s.push(res);
                }
                else 
                {
                    cout << "Division by Zero!" << endl;
                    return -1;                          // Indicate an error
                }
            }

            else if(eq[i]=='^')
            {
                int res = pow(num2,num1);
                s.push(res);
            }
        }
    }

    if (s.size() == 1) {
        return s.top();
    } else {
        cout << "\nInvalid Postfix Expression!" << endl;
        return INT32_MIN; 
    }
}

int main()
{
    string postfix = "3-5*62/+4-";                      // 35*62/+4-  =>  14
    cout<<"\nAnswer is : "<< Eval_Postfix(postfix)<<"\n\n";
}
