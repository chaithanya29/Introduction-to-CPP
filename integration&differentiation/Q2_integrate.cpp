# include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
float integfunc(float x);

int main(){
	/*Assignment 3; Q.3
	Trapezoidal integration */
	float a = 0, b = 3;
	float h, sum,res;
	res = (1/sqrt(2))*atan(3/sqrt(2));
	int N[7] = {10,30,100,300,750, 1000, 5000};
	ofstream myfile;
	myfile.open("integ.dat");

	for(int j = 0;j<7;j++){
		h = (b - a)/N[j];

		sum = (integfunc(b) + integfunc(a))*h/2;

		for(int i = 1;i<N[j];i++){
			sum = sum + h*integfunc(a + i*h);

		}
		myfile << N[j] << ' ';

		myfile << abs(res-sum)/res << endl;
	}
	myfile.close();
	return 0;
	
}
float integfunc(float x){
	return(1/(2+pow(x,2)));
}

