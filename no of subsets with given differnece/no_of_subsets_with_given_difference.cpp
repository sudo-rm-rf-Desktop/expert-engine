#include<bits/stdc++.h>
#define ll long long int
using namespace std;

/*
int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int dp[n + 1][sum + 1];
  // Initializing the first value of matrix
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]]; 
            else
                  dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int countWithGivenSum(int arr[ ], int n, int diff)
{   
     int sum=0;
    for(int i=0;i<n;i++)
         sum+=nums[i]
	 
	 int reqSum=(diff+sum)/2;
	 return subsetSum(arr,n,reqSum);
}
*/

int subset_sum(vector<int> arr , int n , int sum){
	bool t[n+1][sum+1];

	for(int i=0; i<n+1; i++){
		for(int j=0; j<sum+1; j++){
			if(i==0) t[i][j] = false;
			if(j==0) t[i][j] = true;
		}
	}

	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(arr[i-1] >= j){
				t[i][j] = t[i-1][j];
			}

			if(arr[i-1] < j){
				t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j]; 
			}
		}
	}

	return t[n][sum];
}

int solve(vector<int> a , int k){
	int n = a.size();
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += a[i];
	}
	int diff = (k +	sum)/2;

	 return subset_sum(a , a.size() , diff);

	
}


int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	vector<int> a;

	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	int dif;
	cin>>dif;

	cout<<solve(a , dif);


}
