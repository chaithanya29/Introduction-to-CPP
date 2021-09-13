# include<iostream>
using namespace std;
/*C++ program to find the machine precision of the machine on which
the program is run */
int main(){
	float eps = 0.5; //initial guess for the precision
	float eps1;
	while((1+eps)!=1){
	//defining condition for machine precision
	eps1 = eps;
	eps = eps/2;
	}
	cout << "Machine Precision is = "<< eps1 << endl;
	return 0;
}
