#include <stdio.h>

struct job
{
    int id;
    int t1;
    int t2;
};

void bubbleSort1(struct job arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].t1 > arr[j + 1].t1)
            {
                struct job temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void bubbleSort2(struct job arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].t2 > arr[j + 1].t2)
            {
                struct job temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main()
{
    printf("Johnson's algorithm for 2 machine scheduling problem\n");
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct job arr[n];

    printf("Enter the processing time of jobs: ");
    for (int i = 0; i < n; i++)
    {
        arr[i].id = i + 1;
        scanf(" %d %d", &arr[i].t1, &arr[i].t2);
    }
    int j = 0;
    struct job m1[n];
    for (int i = 0; i < n; i++)
        if (arr[i].t1 <= arr[i].t2)
            m1[j++] = arr[i];
    bubbleSort1(m1, j);
    struct job m2[n];
    int k = 0;
    for (int i = 0; i < n; i++)
        if (arr[i].t1 > arr[i].t2)
            m2[k++] = arr[i];
    bubbleSort2(m2, k);
    struct job m3[n];
    for (int i = 0; i < j; i++)
        m3[i] = m1[i];
    for (int i = 0; i < k; i++)
        m3[j + i] = m2[k - i - 1];
    printf("\nThe order of jobs is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", m3[i].id);
    printf("\n");
    int sum1 = 0, sum2 = 0;
    return 0;
}
