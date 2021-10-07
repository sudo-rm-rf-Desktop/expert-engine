#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> solve(int a[] , int t){
	vector<int> ans;
	stack<int> st;

	for(int i=0; i<t; i++){
		if(st.size() == 0) ans.push_back(-1);
		else if(st.size() > 0 && st.top() < a[i]){
			ans.push_back(st.top());
		}
		else if(st.size() > 0 && st.top() >= a[i]){
			while(st.size() > 0 && st.top() >= a[i]) st.pop();

			if(st.size() == 0) ans.push_back(-1);
			else ans.push_back(st.top());
		}

		st.push(a[i]);
	}

	return ans;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	vector<int> ans;
	ans = solve(a , n);
	for(auto i: ans){
		cout<<i<<" ";
	}
}