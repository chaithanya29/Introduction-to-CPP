# include<iostream>
#include<cmath>
//#include<string>
#include<fstream>
using namespace std;

float mean(float *arr, int size);
float STD(float *arr, int size, float avg);

int main(){
	/*Program to find the mean and standard deviation of a given 
	sample of numbers, stored in the array ar  */
	int s = 12; //size of array

	float ar[12] = {9.2,14.1,9.8,12.4,16.0,12.6,22.7,18.9,21.0,14.5,20.4,16.9};
	float m = mean(ar,s);
	float v = STD(ar,s,m);
	cout << "Mean : " << m << endl;
	cout << "Standard Deviation : " << v << endl;
	
	return 0;
}

float mean(float *arr, int size){
	//Function to calculate mean of elements of array arr
	int i;
	float sum = 0;
	for(i=0;i<size;i++){
		sum += arr[i];
	}
	return(sum/size);
}

float STD(float *arr, int size, float avg){
	//Function to calculate standard deviation of elements of 
	// array arr with mean 'avg'
	int i;
	float val = 0;
	for(i=0;i<size;i++){
		val += pow(arr[i] - avg, 2);
	}
	return(sqrt(val/(size-1)));
}
