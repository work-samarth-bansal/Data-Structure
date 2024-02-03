#include <iostream>
#include <cmath>
using namespace std;

class Node
{
    public :
    int coeff;
    int exp;
    Node *next;

    Node(): coeff(0),exp(0),next(NULL){}
    Node(int c,int e): coeff(c),exp(e),next(NULL){}
};

class Polynomial
{
    Node *head;

    public:
    Polynomial()
    {
        head=NULL;
    }
    Polynomial(int n);
    //~Polynomial();

    void Display();
    int eval(int x);
};

Polynomial::Polynomial(int n)
{
    head = NULL;

    for(int i=0; i<n; i++)
    {
        int coeff,exp;
        cout<<"Coefficient : ";
        cin>>coeff;
        cout<<"Exponent : ";
        cin>>exp;

        Node *temp = new Node(coeff,exp);

        if(head==NULL || exp > head->exp)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            Node *current = head;
            Node *prev=NULL;
            while(current!=NULL && exp<=current->exp)
            {
                prev = current;
                current=current->next;
            }
            prev->next=temp;
            temp->next=current;
        }
    }
}

void Polynomial::Display()
{
    Node *p=head;

    while(p)
    {
        cout<<p->coeff<<"x**"<<p->exp;
        if(p->next)cout<<" + ";
        p=p->next;
    }
    cout<<endl;
}

int Polynomial::eval(int x)
{
    int sum =0;
    Node *p=head;

    while(p)
    {
        sum += p->coeff * pow(x,p->exp);
        p=p->next;
    }
    return sum;
}

int main()
{
    Polynomial px(3);
    px.Display();
    int result = px.eval(2);
    cout << "Result: " << result << endl;
}