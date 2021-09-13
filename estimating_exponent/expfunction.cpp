# include<iostream>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;

double firstMethod(int a, double b);
double secondMethod(int a, double b);
double thirdMethod(int a, double b);
int main(){
	/* Assignment 2
	Program for estimating the exponent function using 3 methods*/
	int N[101];
	int x[4] = {0,10,50,100};

	double result, res2, res3;
	double builtIn;
	double err1, err2, err3;
	N[0] = 1;
	for(int i = 1; i<101;i++){
		N[i] = i*10;
		
	}
	for(int l = 0; l<4;l++){

		string filename1 = "file" + to_string(int(x[l])) +"_1.dat";
		string filename2 = "file" + to_string(int(x[l])) +"_2.dat";
		string filename3 = "file" + to_string(int(x[l])) +"_3.dat";
  		ofstream file1(filename1);
  		ofstream file2(filename2);
  		ofstream file3(filename3);

		for (int k=0;k<100;k++){
			result = firstMethod(N[k],x[l]);
			res2 = secondMethod(N[k],x[l]);
			res3 = thirdMethod(N[k],x[l]);

			builtIn = exp(-x[l]);

			err1 = abs((result - builtIn)/builtIn);
			err2 = abs((res2 - builtIn)/builtIn);
			err3 = abs((res3 - builtIn)/builtIn);

			file1 << N[k] <<' '<< err1 <<endl;
			file2 << N[k] <<' '<< err2 <<endl;
			file3 << N[k] <<' '<< err3 <<endl;

		}
		file1.close();
		file2.close();
		file3.close();}
	return 0;
	}
	
	
double firstMethod(int n, double x){
	double sum = 0;
	
	for(int i = 0;i<n;i++){
		float fact=1.;
		for(int j = 1; j<i+1;j++){
			fact = fact*x/j;
		}
		sum = sum + pow(-1,i)*fact;
	}
	return(sum);
}
double secondMethod(int a, double b){
	double xp = 1.;
	double xn;
	double sum =1;
	for(int i=1;i<a;i++){
		xn = -xp*b/i;
		sum = sum + xn;
		xp = xn;
	}
	return(sum);
}
double thirdMethod(int a, double b){
	double xp = 1.;
	double xn;
	double sum =1;
	for(int i=1;i<a;i++){
		xn = xp*b/i;
		sum = sum + xn;
		xp = xn;
	}

	return(pow(sum,-1));
	}
/*
int factorial(int n) 
{ 
    //find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} */
 
