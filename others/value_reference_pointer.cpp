#include <iostream>
using namespace std;
void FuncA(int a){
	a=5;}         //call by value
void FuncB(int &b){
	b=5;}        //call by reference
void FuncC(int *c){
	*c=5;}       //call by reference using pointer
void FuncD(int *v){
	v[0]=4;}
int main(){
	int a=10, b=10, c=10;
	FuncA(a);  
	cout<<"Result of FuncA: "<<a<<endl;
	FuncB(b);  
	cout<<"Result of FuncB: "<<b<<endl;
	FuncC(&c); 
	cout<<"Result of FuncC: "<<c<<endl;
	int Arr[]={6,7,3};
	FuncD(Arr);       
	cout<<"Result of FuncD: "<< Arr[0]<<endl;
}
