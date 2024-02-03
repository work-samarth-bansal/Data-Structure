#include <iostream>
#include <cmath>
using namespace std;

class Term
{
    public:
    int coeff;
    int exp;
};

class Poly
{
    public:
    int n;
    Term *terms;

    Poly(int n)
    {
        this->n=n;
        terms = new Term[n];
    }
    ~Poly()
    {
        delete[] terms;
    }
};

void create(Poly *p)
{
    for(int i=0;i<p->n;i++)
    {
        cout<<"Coefficient : ";
        cin>>p->terms[i].coeff;
        cout<<"Exponent : ";
        cin>>p->terms[i].exp;
    }
}

void display(Poly p)
{
    for(int i=0;i<p.n;i++)
    {
        cout<<p.terms[i].coeff<<"x^"<<p.terms[i].exp;
        if (i < p.n - 1)
            cout << " + ";
    }
    cout<<endl;
}

/*void Eval(Poly *p ,int x)
{
    double sum = 0;
    for(int i=0 ; i<p->n; i++)
    {
        int term = pow(x,p->terms[i].exp);
        sum += p->terms[i].coeff * term;
    }
    cout<<"Value of Polynomial P(2) = ";
    cout<<sum<<endl;
}*/

int main()
{
    int n;
    cout<<"Number of Terms: ";
    cin>>n;
    Poly px(n);

    create(&px);
    display(px);
    //Eval(&px,2);

    double sum = 0;
    for(int i=0 ; i<px.n; i++)
    {
        int term = pow(2,px.terms[i].exp);
        sum += px.terms[i].coeff * term;
    }
    cout<<"Value of Polynomial P(2) = ";
    cout<<sum<<endl;
}
