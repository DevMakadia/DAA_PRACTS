#include<bits/stdc++.h>
using namespace std;

int mcm(int p[], int i, int j)
{
    if (i == j)
        return 0;

    int k;
    int min = INT_MAX;
    int count;
 

    for (k = i; k < j; k++)
    {
        count = mcm(p, i, k)
                + mcm(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];
 
        if (count < min)
            min = count;
    }

    return min;
}
 
int main(){
    
    int  n ,  i;
    int arr[100];

    cout<<"Enter the number of matrix :";
    cin>>n;

    cout<<"Enter the matrix dimensions :";
    for(i = 0 ; i<=n ; i++){
        cin>>arr[i];
    }

    cout<< " The least amount of multiplications is : " << mcm(arr , 1 , n);

    return 0;
}

