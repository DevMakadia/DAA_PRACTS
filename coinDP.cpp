#include<bits/stdc++.h>
using namespace std;

int count(int s[] , int m , int n ){

    if(n==0)
    return 1;

    if(n<0)
    return 0 ; 

    if(m<=0 && n>=0)
    return 0 ;

    return count( s , m-1 , n ) + count(s , m , n - s[m-1]);

}

int main()
{

    int  n , m , i;
    int arr[100];

    cout<<"Enter the number of coins :";
    cin>>m;

    cout<<"Enter the Coins :";
    for(i = 0 ; i<m ; i++){
        cin>>arr[i];
    }

    cout<<"Enter your amount :";
    cin>>n;

    cout<< " " << count(arr , m ,n );

    return 0;
    
}
