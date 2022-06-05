#include <iostream>
#include <algorithm>

using namespace std;
// Coin Changin problem using DP approach with tracing

int coinChange(int coins[], int n, int sum){
  int dp[n+1][sum+1];
  for (int i = 0; i < n+1; i++)
  {
    for (int j = 0; j < sum+1; j++)
    {
      if(i==0 || j==0){
        dp[i][j] = 0;
      }
      else if(i==1){
        dp[i][j] = 1+dp[i][j-coins[i-1]];
      }
      else if(j<i){
        dp[i][j] = dp[i-1][j];
      }
      else{
        dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
      }
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

  // Tracing the coins
  int index = dp[n][sum];
  int trace[index+1]; 
  int i=n,j=sum;


  while(i>0 && j>0){
    while (dp[i][j] == dp[i-1][j])
    {
      i--;
    }

    trace[index] = coins[i-1];
    j=j-coins[i-1];
    index--;
  }
  // printing the coins
  cout<<"Coins: ";
  for (int i = 1; i < dp[n][sum]+1; i++)
  {
    cout<<trace[i]<<" ";
  }
  cout<<endl;
  
  
  return dp[n][sum];
}

int main(){
  // --> Static Testing
  // int n = 3;
  // int coins[n] = { 1,2,5 };
  // int sum = 7;
  // int n = 4;
  // int coins[n] = { 1,5,6,8 };
  // int sum = 11;

  int n,sum;
  cout<<"Enter number of coins: ";
  cin>>n;
  int coins[n];
  cout<<"Enter the denominations of the coins: ";
  for (int i = 0; i < n; i++)
  {
    cin>>coins[i];
  }
  cout<<"Enter required sum: ";
  cin>>sum;
  sort(coins, coins+n);

  int ans = coinChange(coins, n, sum);
  cout<<"No. of coins: "<<ans;

}
