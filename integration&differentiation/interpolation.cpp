# include<iostream>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;
float interp(int N, int x2[], float y[], int x);
int main(){/*
	int * in_ptr, n=0,N=9;
	double x_old[N], f_old[N];
	string line;
	ifstream
	//ifstream ReadFile("sample_data.dat");
	in_ptr = fopen("sample_data.dat","r");
	fgets(line,sizeof(line),in_ptr);

	while (fgets(line,sizeof(line),in_ptr)!=NULL){
		sscanf(line,"%1f %1f", &x_old[n], &f_old[n]);
		n++;
	}
	int N_old = n;
	fclose(in_ptr);

	cout << x_old << endl;*/
	int x_old[9] = {0,25,50,75,100,125,150,175,200};
 	float f_old[9] = {10.6,16.0,45.0,83.5,52.8,19.9,10.8,8.25,4.70};
	float x_new[100];
	x_new[0] = 0;
	for (int i = 0; i < 99; i++){
	x_new[i+1] = x_new[i] + 2;
    
}
	ofstream ofile1("interp9.dat");
	for (int i = 0; i < 100; i++){
    	float val = interp(9,x_old,f_old,x_new[i]);
    	ofile1<<x_new[i]<<' '<<val<<endl;
  	}
  	ofile1.close();

  	ofstream ofile2("interp3.dat");
  	for (int j = 0; j <= 6; j=j+2){
  		int xp[3] = {x_old[j],x_old[j+1],x_old[j+2]};
		float yp[3] = {f_old[j],f_old[j+1],f_old[j+2]};
  		for (int i = x_old[j]/2; i < x_old[j]/2 + 25; i++){
    			float val = interp(3,xp,yp,x_new[i]);
    			ofile2<<x_new[i]<<' '<<val<<endl;
  		}
  	}
  	ofile2.close();
  
  
	return 0;	
}

float interp(int N, int x2[], float y[], int x){
	float res = 0;
	for (int i = 0; i < N; i++){
	double k = y[i];
		for (int j = 0; j < N; j++){
		if (j!=i)
			k = k*(x - x2[j])/double(x2[i]-x2[j]);
		}
	res += k;
	}
	return res;
}
