# include<iostream>
#include<cmath>
//#include<string>
#include<fstream>
using namespace std;
float BW(float x,float mu, float sig);
float summation(int N, float a, float b, float mu, float sig);
int main(){
	// Using Trapezoidal method of numerical integration,
	// finding the cumulative integral between the bounds specified 	  // by the user for the non-relativistic Breit-Wigner distribution
	float a, b;
	cout << "Enter lower and upper bounds " << endl;
	cin >> a; // lower bound for cumulative integration
	cin >> b;// upper bound for cumulative integration
	
	int N = 500; //number of intervals between the bounds
	
	float sigma = 1, mode = 0;// assuming mode to be 0 and variance 1
	
	float val1 = summation(N,a,b, mode, sigma);
	// cumulative integral in bounds specified by user
	cout << "Value of the cumulative integral is : " << val1 << endl;
	// Assuming that the total integral can be estimated between 
	// (mode-10 , mode+10)
	float val2 = summation(N,mode-10,mode+10, mode, sigma);
	
	// Probability that values lie beyond 1.5*sigma
	float val3 = summation(N,mode-1.5,mode+1.5, mode, sigma);
	cout << "Probability that values lie beyond 1.5*sigma is :" << abs(val3 - val2)/val2 << endl;
	
	//Probability that values lie beyond 2.5*sigma
	float val4 = summation(N,mode-2.5,mode+2.5, mode, sigma);
	cout << "Probability that values lie beyond 2.5*sigma is :" << abs(val4 - val2)/val2 << endl;
	
	// Probability that values lie beyond 3.5*sigma
	float val5 = summation(N,mode-3.5,mode+3.5, mode, sigma);
	cout << "Probability that values lie beyond 3.5*sigma is :" << abs(val5 - val2)/val2 << endl;
	return 0;
	
}
float BW(float x,float mu, float sig){
	// Defining the non-relativistic Breit-Wigner (Cauchy) 		// distribution
	return ((1/(M_PI*pow(sig,2)))*(1/(1+pow((x-mu)/sig, 2))));
}
float summation(int N, float a, float b, float mu, float sig){
	// Iterative summation between specified bounds
	float h = (b - a)/N;
	
	float sum = (BW(b,mu,sig) + BW(a,mu,sig))*h/2;

	for(int i = 1;i<N;i++){
		sum = sum + h*BW(a + i*h,mu,sig);

	}
	return(sum);
}
