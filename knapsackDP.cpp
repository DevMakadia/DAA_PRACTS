#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n)
{

    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)

        return knapsack(W, wt, val, n - 1);

    else
    {
        return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n - 1));
    }
}

int main()
{

    int n;
    int wt[100];
    int val[100];
    int W;

    cout << "Enter the number of items : ";
    cin >> n;

    cout << "Enter the weight of the items :";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << "Enter the value of the items :";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    cout << "Enter the capacity of knapsack : ";
    cin >> W;

    cout << "The profit of the knapsack is :" << knapsack(W, wt, val, n);
    return 0;
}
