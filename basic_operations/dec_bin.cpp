#include<iostream>
using namespace std;
/*C++ prgram to convert a given decimal number 'num' into 
its binary representation*/
int main(){
	int num = 108;//initializing and defining the given values
	int binary_rep[32];
	int i = 0;
	while (num){
		binary_rep[i] = num%2;
		num = num/2;
		i++;
	}
	for(int j = i-1;j>=0;j--){
		cout << binary_rep[j] << endl;
	}
	return 0;
}
