# include<iostream>
#include<cmath>
using namespace std;
/*C++ prgram to convert a given binary number 'num' into 
its decimal representation*/
int main(){
	int num = 1010111;//initializing and defining the given values
	int dec_val = 0;
	int num1;
	int flag = 0; //flag integer to track the number of iterations
	while (num){
		num1 = num%10;
	
		dec_val += num1*(int)pow(2,flag);
		flag = flag + 1;
		num = num/10;

	}
	cout << "The decimal converted number is = " << dec_val << endl;
	return 0;
}
