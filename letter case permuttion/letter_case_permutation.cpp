#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(string input , string output , vector<string> &v){
	if(input.length() == 0){
		v.push_back(output);
		return;
	}

	if(isalpha(input[0])){
		string op1 = output;
		string op2 = output;

		op1.push_back(tolower(input[0]));
		op2.push_back(toupper(input[0]));

		input.erase(input.begin() + 0);

		solve(input , op1 , v);
		solve(input , op2 , v);
	}
	else{
		string op1 = output;

		op1.push_back(tolower(input[0]));

		input.erase(input.begin() + 0);

		solve(input , op1 , v);
	}

}

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	//start-code
	    string s = "a1B2";
	    string output = "";
	    vector<string> v;
	    solve(s , output , v);

	    for(auto i: v){
	    	cout<<i<<" ";
	    }
	    return 0;
}
