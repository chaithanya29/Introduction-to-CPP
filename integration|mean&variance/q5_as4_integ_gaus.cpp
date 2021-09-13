# include<iostream>
#include<cmath>
//#include<string>
#include<fstream>
using namespace std;
float gaus(float x,float mu, float sig);
float summation(int N, float a, float b, float mu, float sig);
int main(){
	// Using Trapezoidal method of numerical integration,
	// finding the cumulative integral between the bounds specified 	  // by the user for the Gaussian distribution
	float a, b;
	cout << "Enter bounds " << endl;
	cin >> a; // lower bound for cumulative integration
	cin >> b; // upper bound for cumulative integration
	
	int N = 500; // number of intervals between the bounds
	
	float sigma = 1, mean = 0;// assuming mean to be 0 and variance 1
	// cumulative integral in bounds specified by user
	float val1 = summation(N,a,b, mean, sigma);
	cout << "Value of the cumulative integral is : " << val1 << endl;
	// Assuming that the total integral can be estimated between 
	// (mean-10 , mean+10)
	float val2 = summation(N,mean-10,mean+10, mean, sigma);
	
	// Probability that values lie beyond 1.5*sigma
	float val3 = summation(N,mean-1.5,mean+1.5, mean, sigma);
	cout << "Probability that values lie beyond 1.5*sigma is :" << abs(val3 - val2)/val2 << endl;
	
	//Probability that values lie beyond 2.5*sigma
	float val4 = summation(N,mean-2.5,mean+2.5, mean, sigma);
	cout << "Probability that values lie beyond 2.5*sigma is :" << abs(val4 - val2)/val2 << endl;
	
	// Probability that values lie beyond 3.5*sigma
	float val5 = summation(N,mean-3.5,mean+3.5, mean, sigma);
	cout << "Probability that values lie beyond 3.5*sigma is :" << abs(val5 - val2)/val2 << endl;
	
	return 0;
	
}
float gaus(float x,float mu, float sig){
// defining the Gaussian distribution with mean mu and standard deviation sig
	return ((1/sqrt(2*M_PI*pow(sig,2)))*(exp(-pow((x - mu),2)/(2*pow(sig,2)))));
}

float summation(int N, float a, float b, float mu, float sig){
	// Iterative summation between specified bounds
	float h = (b - a)/N;
	
	float sum = (gaus(b,mu,sig) + gaus(a,mu,sig))*h/2;

	for(int i = 1;i<N;i++){
		sum = sum + h*gaus(a + i*h,mu,sig);

	}
	return(sum);
}

