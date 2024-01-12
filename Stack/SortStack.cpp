#include <bits/stdc++.h> 
#include <stack>
using namespace std;

// Time Complexity => O(n²)
// Space Complexity => O(n)

void sortS(stack<int> &stack, int elem){

// Base Case
	if (stack.empty() || (stack.top()<=elem)) {

		stack.push(elem);
		return;

	}

	int temp = stack.top();
	stack.pop();

	sortS(stack, elem);

	stack.push(temp);
  	
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	// Base Case
	if(stack.empty()){
		return;
	}
	int val = stack.top();
	stack.pop();

	sortStack(stack);

	sortS(stack, val);


}