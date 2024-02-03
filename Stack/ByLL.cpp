#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class Stack {
	Node* top;

    public:
	Stack() { top = NULL; }

	void push(int data)
	{
		Node* temp = new Node;
        temp->data = data;
        temp->next = NULL;

		// Check if stack (heap) is full
		if (!temp) {
			cout << "\nStack Overflow";
			return;
		}
		temp->next = top;
		top = temp;
	}

	bool isEmpty()
	{
		return top == NULL;
	}

	int StackTop()
	{
		if (!isEmpty())
			return top->data;
		else
			return INT32_MIN;
	}

    int peek(int idx=1)
    {
        Node *p = top;
        for(int i=1;i<idx;i++)
        {
            p=p->next;
        }
        return p->data;
    }

	int pop()
	{
		Node* temp;
        int x = INT32_MIN;

		if (top == NULL) {
			cout << "\nStack Underflow" << endl;
			return x;
		}
		else {
			temp = top;
            x = top->data;
			top = top->next;
            delete temp;
		}
        return x;
	}
    
    void display()
	{
		Node* temp;
		if (isEmpty()) {
			cout << "\nStack Underflow";
			exit(1);
		}
		else {
			temp = top;
			while (temp)
            {
				cout <<"| "<< temp->data <<" |"<< endl;
				temp = temp->next;
			}
            cout<<"------"<<endl;
		}
	}
};

int main()
{
	Stack s;
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);
	s.display();

    cout << "\nStack Top element is " << s.peek() << endl;
    cout << "\nStack Second Top element is " << s.peek(2) << endl;

	cout<<"\nPopped: "<<s.pop()<<endl;
	cout<<"\nPopped: "<<s.pop()<<endl;

	s.display();

	cout << "\nTop element is " << s.StackTop() << endl;

	return 0;
}
