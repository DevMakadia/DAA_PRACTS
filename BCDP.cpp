#include<bits/stdc++.h>
using namespace std;



int binocoeff( int n , int k){

    if(k>n)
         return 0;
   
    if(k==n || k==0)
        return 1;
        return binocoeff(n-1,k-1) + binocoeff(n-1,k);
}

int main(){

    int n , k  ;
    cout<<"Enter n :";
    cin>>n;
    cout<<"Enter k :";
    cin>>k;

    cout<<"the value of "<<"("<< n << " , "<<k<<") "<<"is "<<binocoeff(n,k);
    return 0;
    
}