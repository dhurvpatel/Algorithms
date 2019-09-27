// Author : Dhruv Patel
//
#include<bits/stdc++.h>

using namespace std;

int RangMinQuery(int input[], int presentNode, int i, int j, int left, int right){

	if(left <= i && j <= right) return input[presentNode];
	else if( right < i || j < left) return INT_MAX;
	else {
		int middle = (i + j) / 2;
		return ( min(RangMinQuery(input, 2*presentNode + 1, i, middle, left, right), 
			RangMinQuery(input, 2*presentNode + 2, middle + 1, j, left, right)));
	}

}

int main(void){
	int noOfElements;
	cout<<"Enter noOfElements: ";
	cin>>noOfElements;

	int size=1;
	while(noOfElements>size) size *= 2;

	int length = 2*size -1;
	int input[length] = {0};
	
	int index = size;

	cout<<"Enter "<<noOfElements<<" space seperated elements: ";
	for(int i = index - 1; i < size - 1 + noOfElements; i++){
		cin>>input[i];
	} 

	for(int i = size - 2; i >= 0; i--){
		if(input[2*i + 1] <  input[2*i + 2]){
			input[i] = input[2*i + 1];				//for MIN element
		} else input[i] = input[2*i + 2];
	}

/*	for(int i=0; i<length; i++){
		cout<<input[i]<<" ";
	}
	cout << endl;
*/
	int noOfTestCases;
	cout<<"Enter noOfTestCases: ";
	cin >> noOfElements;
	while(noOfTestCases--){
		int left, right;
		cout<<"Enter "<<noOfTestCases<<" Left[space]Right queries:"<<endl;
		cin>>left>>right;
		cout<<RangMinQuery(input, 0, size - 1, length-1, size - 1 + left, size - 1 + right)<<endl;
	}
	

	return 0;
}