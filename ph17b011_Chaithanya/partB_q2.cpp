# include<iostream>
# include <cmath>
// Roll. no: PH17B011
// Name : Chaithanya Krishna Moorthy
// Part B Q2

using namespace std;

float equation(float x){
	// defining the equation given in the question
	return (pow(x,2) - 4*x*sin(x) + pow(2*sin(x),2));
}
float der_eq(float x){
	// derivative of the given equation
	return (2*x - 4*sin(x) - 4*x*cos(x) + 4*sin(2*x));
}
float root_equation(float x){
	// square root of the given equation to use in bisection method
	return (x - 2*sin(x));
}
void secant(float x0, float x1, float tol){
	// secant method for root finding
	float x;
	int it = 0;
	if (equation(x0)==0){
		cout << "The root is " << x0 << endl;
	}
	if (equation(x1)==0){
		cout << "The root is " << x1 << endl;
	} // initial checks
	

	x = (x0*equation(x1) - x1*equation(x0))/(equation(x1) - equation(x0));// finding next x value
	do {
		it++; // iterations

		if (equation(x) == 0 ){
			cout << "Root is " << x << endl;
			break;
		}
		x0 = x1;
		x1 = x;
		x = (x0*equation(x1) - x1*equation(x0))/(equation(x1) - equation(x0));
	} while (fabs(x - x1) >= tol); // tolerance
	
	cout << "Root of the equation using Secant method within the given tolerance is "<< x << endl;
	cout << "Number of iterations till convergence: " << it << endl;

}
void newt_raph(float x0, float tol){
	// Newton - Raphson method
	float x1;
	int it = 0;
	if (equation(x0)==0){
		cout << "Root is : " << x0 << endl;
	}
	x1 = x0 - equation(x0)/der_eq(x0);
	do{
		it ++;

		if (equation(x1)==0){
			cout << "Root is : " << x1 << endl;
			break;
		}
		x0 = x1;
		x1 = x0 - equation(x0)/der_eq(x0); // next iterations
	} while (fabs(x0 - x1) >= tol); // tolerance condition
	
	cout << "Root of the equation using Newton-Raphson method within the given tolerance is " << x1 << endl;
	cout << "Number of iterations till convergence: " << it << endl;
}
void bisection(float (*f)(float), float l, float u, float tol){
	// bisection method
	int it = 0;
	float c;
	if (f(l)==0){
		cout << "The root is " << l << endl;
	}
	if (f(u)==0){
		cout << "The root is " << u << endl;
	}
	
	if (f(l)*f(u)<0){ // sign changing condition for the function
		do{
		
			it++;
			c = (l+u)/2; // mid point
			if (f(c) == 0){
				cout << "Root is : " << c << endl;
				break;
			}
			if (f(l)*f(c) < 0){
				u = c;
			} else (l = c);
		
		} while (abs (l - u) >= tol); // tolerance condition
		
		cout << "Root of the equation using Bisection method within the given tolerance is " << c << endl;
		cout << "Number of iterations till convergence: " << it << endl;
	
	
	} else 
		cout << "There is no root using Bisection method in the given range!" << endl;
}
	
int main(){
	float X0 = 1.5, X1 = 2; // initial values chosen to achieve positive roots
	float tolerance = 1e-5;
	bisection(equation,X0,X1,tolerance);
	cout << endl;
	secant(X0,X1,tolerance);
	cout << endl;
	newt_raph(X0,tolerance);
	cout << endl;
	cout << "Finding solution to the root of the given equation, since it is symmetric and can be reduced to (x - 2sin(x)) " << endl;
	// since bisection could not be used in the original function, using it on the square
	// root of the function (it is a perfect square).
	cout << endl;
	bisection(root_equation,X0,X1,tolerance);
	
	return 0;

}





