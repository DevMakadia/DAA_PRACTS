#include <stdio.h>
#include <limits.h> //for INT_MAX

// Print result
void printSum(int result[], int front, int tail)
{
    printf("[");
    for (int i = front; i < tail; ++i)
    {
        if (result[i] != INT_MAX)
        {
            printf(" %d ", result[i]);
        }
    }
    printf("]\n");
}
// Finding the subset with given sum in an array
void subsetSum(int arr[], int result[], int sum, int size, int current_sum, int location)
{
    if (location == -1)
    {
        return;
    }
    // Through by recursion find previous element
    subsetSum(arr, result, sum, size, current_sum, location - 1);
    // Get element
    result[location] = arr[location];
    if (current_sum + arr[location] == sum)
    {
        // When we get sum
        printSum(result, location, size);
    }
    // Through by recursion find previous element
    subsetSum(arr, result, sum, size, current_sum + arr[location], location - 1);
    result[location] = INT_MAX;
}
// Handles the request to find subset sum
void findSubset(int arr[], int size, int sum)
{
    if (size <= 0)
    {
        return;
    }
    // Used to collect result
    int result[size];
    // Set initial value
    for (int i = 0; i < size; ++i)
    {
        // Initialize with max value
        // Assuming that all elements of are less than the maximum integer
        result[i] = INT_MAX;
    }
    // Display given sum
    printf("Subser Sum of %d is \n", sum);
    // Find subset with given sum
    subsetSum(arr, result, sum, size, 0, size - 1);
}
int main()
{
    int size;
    printf("Enter size of array : \n");
    scanf("%d",&size);
    // Define array elements
    int arr[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    // Get the size
    int sum;
    printf("Enter the size :\n");
    scanf("%d",&sum);
    findSubset(arr, size, sum);
    return 0;
}