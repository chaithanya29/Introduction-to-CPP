# include <iostream>
# include <cmath>

// Roll. no: PH17B011
// Name : Chaithanya Krishna Moorthy
// Part B Q3
using namespace std;

float equation(float x){
	// defining the equation given in the question
	return (pow(x,2) - 4*x*sin(x) + pow(2*sin(x),2));
}
float der_eq(float x){
	// derivative of the given equation
	return (2*x - 4*sin(x) - 4*x*cos(x) + 4*sin(2*x));
}


class root_finder {
	//class containing all three root finding methods
	float lower, upper, tol; // private access members
	public:
	root_finder(float,float,float); // constructor for the class, public access
	void bisection(); // member functions
	void newt_raph();
	void secant();
	
};
root_finder :: root_finder (float L, float U, float Tol){
	// constructor
	lower = L;
	upper = U;
	tol = Tol;
}
void root_finder::bisection(){
	// bisection method
	float l = lower;
	float u = upper;
	int it = 0;
	float c;
	if (equation(l)==0){
		cout << "The root is " << l << endl;
	}
	if (equation(u)==0){
		cout << "The root is " << u << endl;
	}
	
	if (equation(l)*equation(u)<0){
		do{
		
			it++;
			c = (l+u)/2; //mid point
			if (equation(c) == 0){
				cout << "Root is : " << c << endl;
				break;
			}
			if (equation(l)*equation(c) < 0){
				u = c;
			} else (l = c);
		
		} while (abs (l - c) >= tol); // tolerance condition
		
		cout << "Root of the equation using Bisection method within the given tolerance is " << c << endl;
		cout << "Number of iterations till convergence: " << it << endl;
	
	
	} else 
		cout << "There is no root using Bisection method in the given range!" << endl;
		
}

void root_finder::newt_raph(){
	// Newton-Raphson method
	float x1,x0 = lower;
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
		x1 = x0 - equation(x0)/der_eq(x0);
	} while (fabs(x0 - x1) >= tol); // tolerance condition
	
	cout << "Root of the equation using Newton-Raphson method within the given tolerance is " << x1 << endl;
	cout << "Number of iterations till convergence: " << it << endl;
}

void root_finder::secant(){
	// Secant method
	float x, x0 = lower, x1 = upper;
	int it = 0;
	
	if (equation(x0)==0){
		cout << "The root is " << x0 << endl;
	}
	if (equation(x1)==0){
		cout << "The root is " << x1 << endl;
	}
	

	x = (x0*equation(x1) - x1*equation(x0))/(equation(x1) - equation(x0));
	do {
		it++;

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
int main(){
	float L = 1.5, U = 2, Tol = 1e-5; // initial values chosen to achieve positive roots
	root_finder obj(L,U,Tol); // instantiating the class root_finder with object obj
	obj.bisection();
	cout << endl;
	obj.newt_raph();
	cout << endl;
	obj.secant();
	return 0;
	
}
