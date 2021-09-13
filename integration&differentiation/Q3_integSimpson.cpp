# include<iostream>
#include<cmath>
//#include<string>
#include<fstream>
using namespace std;
double func(double t);
int main(){
	/*Assignment 3; Q.4
	Integration by Trapezoidal and Simpson's 1/3rd rule*/
	float a = 0, b = 1;
	float h, sum1, sum2,res;
	res = 1 - exp(-1);
	int N[6] = {2,10,20,40,80,160};
	ofstream myfile1;
	ofstream myfile2;

	//Printing table
	cout<<"    N"<< ' ' ;
	cout<<"Trapezoidal integration"<< "   " ;
	cout<<"Simpson's 1/3rd rule"<< "  " ;
	cout<<"Relative error for trapezoidal"<< "   " ;
	cout<<"Relative error for Simpson's"<< endl;
	for(int j = 0;j<6;j++){
		h = (b - a)/N[j];
		sum1 = (func(b) + func(a))*h/2;
		sum2 = h*(func(a) + func(b))/3;
		for(int i = 1;i<N[j];i++){
			sum1 = sum1 + h*func(a + i*h);
			if (i%2==0){
				sum2 = sum2 + 2*(h/3)*func(a + i*h);
			} else{
				sum2 = sum2 + 4*(h/3)*func(a + i*h);
			
			}
		}
		cout << "    " << N[j] << "    " << sum1 << "               " << sum2 << "                  " << abs(res-sum1)/res << "                     " <<   abs(res-sum2)/res << endl;

		
	}
	
	myfile1.close();
	myfile2.close();
	
}
double func(double x){
	return(exp(-x));
}
