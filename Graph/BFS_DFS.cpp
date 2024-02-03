#include <iostream>
#include <queue>
using namespace std;

void BFS(int G[][7], int start, int n)
{
    int i = start;
    cout<< i <<" ";

    int visited[n] = {0};
    visited[i] = 1;

    queue <int> Q;
    Q.push(i);

    while(!Q.empty())
    {
        i = Q.front();
        Q.pop();

        for(int j = 1; j<n ;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                visited[j] = 1;
                cout<< j <<" ";
                Q.push(j);
            }
        }
    }
    cout<<endl;
}

void DFS(int G[][7], int start, int n)
{
    int i = start;

    static int visited[7] = {0};

    if(visited[start] == 0)
    {
        cout<< i <<" ";
        visited[i] = 1;

        for(int j = 1; j<n; j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                DFS(G,j,n);
            }
        }
    }
}

int main()
{
    int G[7][7]={
                {0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}
                };

    BFS(G,4,7);
    DFS(G,1,7);
    
    return 0;
}