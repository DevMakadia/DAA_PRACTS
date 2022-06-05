#include <stdio.h>
int x[12], w[12], pr[12], m, n, z, val;
void main()
{
    int k, i;
    float r = 0;
    void knapsack(float, int, float);
    int s1 = 0;
    printf("\n\n\t\tKNAPSACK PROBLEM USING BACKTRACKING\n\n");
    printf("\n\tEnter the No.of Items: ");
    scanf("%d", &n);
    printf("\n\tEnter the Weight & Value for the Items \n");
    for (i = 0; i < n; i++)
    {
        printf("\n\titem %d: ", i + 1);
        scanf("%d %d", &w[k], &pr[k]);
        r += w[k];
        s1 += pr[k];
    }
    printf("\n\n\t\tEnter the Knapsack Capacity: ");
    scanf("% d", &m);
    printf("\n\n\tITEMS IN THE KNAPSACK\n\n");
    printf("\titem\tweight\tvalue\n\n");
    knapsack(0, 1, r);
}
void knapsack(float s, int k, float r)
{
    int j, p;
    x[k] = 1;
    if (s + w[k] == m)
    {
        printf("%d Set\n", ++z);
        for (j = 1; j <= k; j++)
        {
            if (x[j])
            {
                printf("\n%d\t %d\t", j, w[j]);
                printf("%d ", pr[j]);
            }
        }
        printf("\n\n");
    }
    else if (s + w[k] + w[k + 1] <= m)
        knapsack(s + w[k], k + 1, r - w[k]);
    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0;
        knapsack(s, k + 1, r - w[k]);
    }
}