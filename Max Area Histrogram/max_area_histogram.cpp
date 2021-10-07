#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> NSR(int a[] , int n){
	stack<pair<int,int>> s2;
	vector<int> right;
	int psudo_index = n+1;
	for(int i=n-1; i>=0; i--){
		if(s2.size() == 0) right.push_back(psudo_index);
		else if(s2.size() > 0 && s2.top().first < a[i]){
			right.push_back(s2.top().second);
		}
		else if(s2.size() > 0 && s2.top().first >= a[i]){
			while(s2.size() > 0 && s2.top().first >= a[i]){
				s2.pop();
			}
			if(s2.size() == 0) right.push_back(psudo_index);
			else right.push_back(s2.top().second);
		}

		s2.push({ a[i] , i});
	}
	return right;
}

vector<int> NSL(int a[] , int n){
	stack<pair<int,int>> s1;
	int psude_index = -1; 
	vector<int> left;
	
	for(int i=0; i<n; i++){
		if(s1.size() == 0) left.push_back(psude_index);
		else if(s1.size() > 0 && s1.top().first < a[i]){
			left.push_back(s1.top().second);
		}
		else if(s1.size() > 0 && s1.top().first >= a[i]){
			while(s1.size() > 0 && s1.top().first >= a[i]){
				s1.pop();
			}
			if(s1.size() == 0) left.push_back(psude_index);
			else left.push_back(s1.top().second);
		}
		s1.push({a[i] , i});
	}

	return left;
}

int solve(int a[] , int n){
	
	vector<int> right , left;

	right = NSR(a , n);
	left = NSL(a , n);
	
	reverse(right.begin() , right.end());

	for(auto j: right) cout<<j<<"  ";
		cout<<endl;
	for(auto i: left) cout<<i<<"  ";
		cout<<endl;
	
	vector<int> diff;
	for(int i=0; i<n; i++){
		diff.push_back(right[i] - left[i] - 1);
	}

	for(auto i: diff) cout<<i<<" ";
		cout<<endl;


	vector<int> area;
	for(int i=0;i<n; i++){
		area.push_back(a[i] * diff[i]);
	}

	for(auto i: area) cout<<i<<" ";
		cout<<endl;


	sort(area.begin()  , area.end());

	return area[area.size()];
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

	cout<<solve(a , n);
	
}