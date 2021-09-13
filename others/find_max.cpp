#include<iostream>
#include<cmath>
using namespace std;
int findMax(int *vals, int numEls);
int main(){
	int arr[10] = {3,6,3,7,8,9,4,0,10,5};
	cout << "Maximum valued element of the array is : " << findMax(arr,10) << endl;
	return 0;
}
int findMax(int * vals, int numEls){
	int j, max = *vals;
	for (j = 1; j<numEls; j++)
		if (max<*(vals + j))
			max = *(vals + j);
	return max;
}
