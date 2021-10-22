// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;

// class Base{
// 	public :
// 	int x; //data part
// // public:
// // 	void setX(int a){ x = a;}//function part
// // 	void getX() {return x;}//function part
// };

// int main()
// {
// 	#ifndef ONLINE_JUDGE
// 	    freopen("input.txt", "r", stdin);
// 	    freopen("output.txt", "w", stdout);
// 	#endif

// 	    Base b;
// 	    b.x = 10;
// 	    cout<<b.x;
// }

// //this whole thing is a capule called Base (in this case)
// //   --------------------------
// // (  data_part | funtion part  )
// //   ---------------------------

//CONST EXAMPLE
// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;

// class Base{
// 	//int x; //unchagable
// 	mutable int x;
// 	int y;
// public:
// 	Base() {

// 	}
// 	Base(int a , int b) :x(a) , y(b{

// 	}

// 	void setX(int a){
// 		x = a;
// 	}

// 	int getX() const {
// 		x = 20;
// 		y = 30;
// 		return x;
// 	}
// };

// int main()
// {
// 	#ifndef ONLINE_JUDGE
// 	    freopen("input.txt", "r", stdin);
// 	    freopen("output.txt", "w", stdout);
// 	#endif

// 	    Base b;
// 	    b.setX(210);
// 	    cout<<b.getX();  
// }

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr = {1,2,3,4,4,4,4,4,4,6};
	int n = arr.size();
	int k = 4;
	int i=0;
	vector<int> ans;
	while(i < n){
		if(arr[i] == k){
			ans.push_back(i);
			while(arr[i-1] == arr[i]){
				i++;
			}
			ans.push_back(i);
			break;
		}
		i++;
	}

	for(auto i: ans){
		cout<<i<<" ";
	}
}

https://www.codingninjas.com/codestudio/problem-details/deleting-and-adding-the-last-node_1170051

    If the given linked list is empty or has only one element, then return head
       

        Declare two-node type variables (assume ‘P’ and ‘Q’),
         first to hold the second last node and other to the last node


             Initially, set both the variables to the head.

    Now, Keep changing the ‘Q’ variable to the next and ‘P’ to the 
    second until the second reaches the NULL value.


    while('Q'->next != NULL) => ‘P’ = ‘Q’, ‘Q’ = ‘Q’ -> next


    Now, assign ‘P’ ->next = NULL because after deleting the last node, this node becomes the last.
    Make sure that now, ‘Q’ will point to the head.
    Return ‘Q’.