#include <iostream>
using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};

class Poly
{
    int n;
    Term *terms;

public:
    Poly(int n)
    {
        this->n = n;
        terms = new Term[n];
    }

    ~Poly()    // Destructor to free memory allocated for terms
    {
        delete[] terms;
    }

    int getN() const    // Getter method for 'n'
    {
        return n;
    }

    Term *getTerms() const    // Getter method for 'terms'
    {
        return terms;
    }
};

void create(Poly *p)
{
    for (int i = 0; i < p->getN(); i++)
    {
        cout << "Coefficient : ";
        cin >> p->getTerms()[i].coeff;
        cout << "Exponent : ";
        cin >> p->getTerms()[i].exp;
    }
}

void display(Poly p)
{
    for (int i = 0; i < p.getN(); i++)
    {
        cout << p.getTerms()[i].coeff << "x^" << p.getTerms()[i].exp;
        if (i < p.getN() - 1)
            cout << " + ";
    }
    cout<<endl;
}

int main()
{
    Poly p(3);

    create(&p);
    display(p);

    return 0;
}
