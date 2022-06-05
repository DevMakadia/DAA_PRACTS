#include<bits/stdc++.h>

    int n , tot ;
    int arr[10];

int funct(){

    int sum = 0;
    for(int i = 0 ; i <n ; i++){
        sum += arr[i];
    }
    printf("The sum is %d", sum);

    

    if(sum > tot){
        printf("this can't be solved :");
    }

    else{
        for(int i = 0 ; i <n ; i++){
            
        }

    }


    

}

int main(){

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter the elements :\n");
    
    for(int i = 0; i <n ; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr , arr+n , greater<int>());

    printf("Enter the total amount : ");
    scanf("%d", &tot);

    funct();
    return 0 ;



}