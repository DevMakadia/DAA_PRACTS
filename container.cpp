#include <bits/stdc++.h>

using namespace std;

int amt;

void container(int C[], int n)
{

    int i;

    sort(C, C + n);

    cout << "The order of the containers is :";
    for (i = 0; i < n; i++)
    {
        cout << C[i] << " ";
    }

    int loaded = 0;
    int j = 0;

    while (C[j] <= amt)
    {
        loaded++;
        amt -= C[j];
        j++;
    }

    cout << "\n The number of containers that can be loaded is :" << loaded;
}

int main()
{

    int n, i, j;
    int C[100];

    cout << "Enter the number of containers :";
    cin >> n;

    cout << "Enter the weight of the containers :";
    for (i = 0; i < n; i++)
    {
        cin >> C[i];
    }

    cout << "Enter the limit  of containers :";
    cin >> amt;

    container(C, n);
    return 0;
}