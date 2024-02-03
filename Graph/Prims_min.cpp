#include <iostream>
//#include <climits>
using namespace std;

#define I INT32_MAX

static int t[2][7] = {0};

void prims(int G[][8], int len)
{
    int min, m, n, k;

    min = I;
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            if (min > G[i][j])
            {
                min = G[i][j];
                m = i;
                n = j;
            }
        }
    }

    int near[8] = {I,I,I,I,I,I,I,I};
    near[m] = 0;
    near[n] = 0;

    t[0][0] = m;
    t[1][0] = n;

    for (int i = 1; i <= len; i++)
    {
        if (near[i] != 0)
        {
            if (G[i][m] < G[i][near[i]])
                near[i] = m;
            else
                near[i] = n;
        }
    }

    for (int i = 1; i < len - 1; i++)
    {
        min = I;

        for (int j = 1; j <= len; j++)
        {
            if (near[j] != 0 && G[j][near[j]] < min)
            {
                k = j;
                min = G[j][near[j]];
            }
        }

        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (int j = 1; j <= len; j++)
        {
            if (near[j] != 0 && G[j][k] < G[j][near[j]])
            {
                near[j] = k;
            }
        }
    }

    for (int i = 0; i < len - 1; i++)
    {
        cout << "( " << t[0][i] << " , " << t[1][i] << " )" << endl;
    }
}

int main()
{
    int G[8][8] = {
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I}};

    prims(G, 7);

    return 0;
}
