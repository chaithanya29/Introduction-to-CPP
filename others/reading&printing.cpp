#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float score[7],el;
	float *ptr;
	ptr = score;
	cout << "Enter elements of the array " << endl;
	for(int i = 0; i<7 ; i++){
		cin >> el;
		score[i] = el;
	}
	
	cout << "Printing the array " << endl;
	for(int j = 0; j<7; j++){
		cout << *(ptr + j) << " ";
	}
	cout << endl;
	return 0;
}
