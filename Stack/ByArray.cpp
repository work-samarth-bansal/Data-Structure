#include <iostream>
#include <climits> // Include for INT32_MIN
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *data;

public:
    Stack(int n)
    {
        size = n;
        top = -1;
        data = new int[n];
    }

    bool IsEmpty()
    {
        return top == -1;
    }

    bool IsFull()
    {
        return top == size - 1;
    }

    // int peek()
    // {
    //     if(IsEmpty())
    //         return INT32_MIN;
    //     else
    //         return data[top];
    // }

    int peek(int idx = 1)
    {
        if (idx >= 0 && idx <= top)
            return data[top-idx+1];
        else
            return INT32_MIN;
    }

    void push(int x)
    {
        if (IsFull())
            cout << "Stack Overflow : cannot push "<< x <<endl;
        else
        {
            top++;
            data[top] = x;
        }
    }

    int pop()
    {
        int x = INT32_MIN;
        if (IsEmpty())
            cout << "Stack Underflow "<<endl;
        else
        {
            x = data[top];
            top--;
        }
        return x;
    }

    void Display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout <<"| "<< data[i] <<" |"<< endl;
        }
        cout<<"-----\n"<<endl;
    }

    ~Stack()
    {
        delete[] data;
    }
};

int main()
{
    Stack st(3);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << "Top Element : " << st.peek() << endl;

    cout<<endl;
    st.Display();

    cout << "\nStack Top element is " << st.peek() << endl;
    cout << "\nStack Second Top element is " << st.peek(1) << endl;

    cout << "\nPopped: " << st.pop() << endl;
    st.Display();

    cout << "Top Element : " << st.peek() << endl;
    return 0;
}
