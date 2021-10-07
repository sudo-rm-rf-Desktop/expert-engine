#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// int solve(string s , string s1 , int n , int m){
//     if(n == 0 || m == 0) return 0;

//     if(s[n-1] == s1[m-1]){
//     	return 1 + solve(s , s1 , n-1 , m-1);
//     }
//     else{
//     	return max(solve(s , s1 , n-1 , m) , solve(s , s1 , n , m-1));
//     }
// }

int solve(string s , string s1 , int n , int m){

    int t[n+1][m+1];

    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            
        }
    }

    if(n == 0 || m == 0) return 0;

    if(s[n-1] == s1[m-1]){
        return 1 + solve(s , s1 , n-1 , m-1);
    }
    else{
        return max(solve(s , s1 , n-1 , m) , solve(s , s1 , n , m-1));
    }
}

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	string s , s1;
	cin>>s>>s1;
	int n = s.length();
	int m = s1.length();
	cout<<solve(s , s1 , n , m);

    return 0;
}

/*

T = int(input())
for _ in range(T):
    n, p, k = map(int, input().split())
    ans = 0
    
    a = p%k - 1
    b = ((n-1)//k)*k
    b = n - 1 - b
    
    if (a>b):
        ans += (b+1)*((n-1)//k + 1) +(a-b)*((n-1)//k)
    else:
        ans += ((n-1)//k + 1)*(a+1)
        
    for i in range(a+1, n, k):
        ans += 1
        if (i==p):
            print(ans)
            break
*/

/*

int t; 
     cin >> t;
        while(t--){
             set<int, greater<int> > s;
            int a[4] ;
            for(int i=0;i<4;i++){
                int n ; 
                cin>>n;
                a[i] = n;
                s.insert(n);
            }
            int l = s.size();
            if(l==4 || l==3){
               cout << 2 <<'\n';
            }
            else if(l==2){
                sort(a,a+4);
                if(a[0]==a[1]&&a[2]==a[3])cout << 2 <<'\n';
                else cout << 1 <<'\n';
            }
            else cout << 0 <<'\n';
        }

*/