# include<iostream>
#include<cmath>
//#include<string>
#include<fstream>
using namespace std;
float func(float x);
double func1(double x);
int main(){	
	/* Assignment 3, Q4
	Single and Double precision differentiation using 3 point 
	formula*/
	float h[5]={1,0.3,0.1,0.01,0.001}, x = sqrt(2);
	double h1[5]={1,0.3,0.1,0.01,0.001}, x1 = sqrt(2);
	for(int i = 0;i<5;i++){
		float diff_val = (func(x+h[i]) - func(x-h[i]))/(2*h[i]);
		cout << diff_val << endl;
		cout << abs((1./3) - diff_val) << endl;
		double diff_val1 = (func1(x1+h1[i]) - func1(x1-h1[i]))/(2*h1[i]);
		cout << diff_val1 << endl;
		cout << abs((1./3) - diff_val1) << endl;
	}
	
}
float func(float x){
	return(atan(x));
}
double func1(double x){
	return(atan(x));
}
