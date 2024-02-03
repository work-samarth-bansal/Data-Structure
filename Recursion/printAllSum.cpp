// C++ program to generate all non-increasing
// sequences of sum equals to x
#include<bits/stdc++.h>
using namespace std;

// Utility function to print array
// arr[0..n-1]
void printArr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	cout << arr[i] << " ";
	cout << endl;
}

// Recursive Function to generate all
// non-increasing sequences
// with sum x
// arr[] --> Elements of current sequence
// curr_sum --> Current Sum
// curr_idx --> Current index in arr[]
void generateUtil(int x, int arr[], int curr_sum, int curr_idx)
{
		
	// If current sum is equal to x, 
	// then we found a sequence
	if (curr_sum == x)
	{
		printArr(arr, curr_idx);
		return;
	}

	// Try placing all numbers from 
	// 1 to x-curr_sum at current index
	int num = 1;

	// The placed number must also be 
	// smaller than previously placed
	// numbers and it may be equal to 
	// the previous stored value, i.e.,
	// arr[curr_idx-1] if there exists
	// a previous number
	while (num <= x - curr_sum && (curr_idx == 0 || num <= arr[curr_idx - 1]))
	{
			
		// Place number at curr_idx
		arr[curr_idx] = num;

		// Recur
		generateUtil(x, arr, curr_sum + num,
								curr_idx + 1);

		// Try next number
		num++;
	}
}

// A wrapper over generateUtil()
void generate(int x)
{
	
	// Array to store sequences one by one
	int arr[x]; 
	generateUtil(x, arr, 0, 0);
}

// Driver code
int main()
{
	int x = 10;
	generate(x);
	return 0;
}
