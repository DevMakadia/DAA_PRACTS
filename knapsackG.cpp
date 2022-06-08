#include <bits/stdc++.h>
using namespace std;

struct item
{
    int weight;
    int value;
    int index;
};

// comparator function is used to sort the array
// in decreasing order of value/weight
bool comparator(struct item item1, struct item item2)
{
    return (item1.value / item1.weight) > (item2.value / item2.weight);
}

int main()
{
    struct item items[15]; 
    int n, c;
    // here index is used in 'items' array because after sorting the array might be shuffled
    // hence to print whether the item is included or not we keep track of indices.
    std::cout << "Enter number of items :" << std::endl;
    cin >> n;

    printf("Enter in the order (index[start with 0] weight value):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &items[i].index, &items[i].weight, &items[i].value);
    }

    //'solution' array is used to get an idea about which item is included
    float solution[n];
    // initially none of the items is included hence we fill the 'solution' array with 0s indicating the same
    memset(solution, 0, sizeof(solution));
    // knapsack capacity
    
    std::cout << "Enter the capacity of knapsack :" << std::endl;
    cin >> c;
    // track maximum profit
    float maxProfit = 0;
    // sorting the 'items' array in descending array of value/weight
    sort(items, items + n, comparator);
    // track current knapsack capacity
    float currKnapsackWeight = 0;
    for (int i = 0; i < n; i++)
    {
        // if item can't be included wholly
        if (currKnapsackWeight + items[i].weight > c)
        {
            // take a fraction of it
            float frac = (c - currKnapsackWeight) / items[i].weight;
            // include fractional weight of the item taken
            currKnapsackWeight += items[i].weight * frac;
            // include that value which we get by taking fraction of item
            maxProfit += items[i].value * frac;
            // indicate what fraction of item is taken
            solution[items[i].index] = frac;
            break; // as we taken a fraction no further items can be included
        }
        // as including the current item don't exceed the knapsack capacity it can be taken wholly
        else
        {
            // include weight of the item
            currKnapsackWeight += items[i].weight;
            // include value of the item
            maxProfit += items[i].value;
            // as we take item wholly we indicate its inclusion as 1
            solution[items[i].index] = 1;
        }
    }
    cout << "Knapsack weight:" << currKnapsackWeight << endl;
    cout << "Maximum profit:" << maxProfit << endl;
    cout << "Solution vector:";
    for (int i = 0; i < n; i++)
    {
        cout << solution[i] << " ";
    }
}
