#include <iostream>
using namespace std;

void print(int row,int col);

int main()
{
    print(7,9);
}


// *       * * * * *
// *       *
// *       *  
// * * * * * * * * *
//         *       *
//         *       *
// * * * * *       *

void print(int row,int col)
{
    for(int i=0;i<=row;i++)
    {
        if(i==0)
        {
            cout<<" *";
            for(int j=0;j<col/2;j++)
                cout<<"  ";

            for(int j=0;j<col/2;j++)
                cout<<" *";
            cout<<endl;
        }
        else if(i<row/2)
        {
            cout<<" *";
            for(int j=0;j<col/2;j++)
                cout<<"  ";

            cout<<" *"<<endl;
        }
        else if(i==row/2)
        {
            for(int j=0;j<col;j++)
                cout<<" *";
            cout<<endl;
        }
        else if(i<row-1)
        {
            for(int j=0;j<col/2-1;j++)
                cout<<"   ";
            cout<<"  *";
            for(int j=0;j<col/2-3;j++)
                cout<<"   ";
            cout<<"  *"<<endl;
        }
        else if(i==row)
        {
            for(int j=0;j<col/2+1;j++)
                cout<<" *";
            for(int j=0;j<col/2-1;j++)
                cout<<"  ";
            cout<<" *"<<endl;
        }
    }  
}


