//C++ to implement trapezoidal rule
#define _USE_MATH_DEFINES
#include<cmath>
#include<ctime>
// Command input, Result and Error:

// g++ CalculatePi.cpp -o CalculatePi && CalculatePi 80000

//N: 80000

// Output:
// Number of interval: 80000:
// Calculation Time: 0.01499999966 seconds
// Aproximate of PI is: 3.141596556
// Error: -3.902120046e-06


//	Optimization Level		N		Time(seconds)
//		O0				8*10^8		29.61800003
//		O1				8*10^8		3.157000065
//		O2				8*10^8		2.045000076
//		O3				8*10^8		2.046000004
//		Os				8*10^8		23.24399948


#include<iostream>
#include<iomanip>

using namespace std;

//f(x)=sqrt(1-x*x) from the assignment
long double f(long double x){
	return sqrt(1-x*x);
}

//approximate for pi
long double calculate_pi(unsigned long long n){
	long double delta = 1/(long double)n;
	long double sum = 0;
	for(unsigned long long i = 1; i <= n; i++){
		sum += (f(delta*(i-1)) +f(delta*i));
	}
	return 2*delta*sum;
}

int main(int argc, char* argv[]){
	//input the number of the interval
	unsigned long long n = strtoull(argv[1], 0 , 10);
	if(n <= 0){
		cout << "Positive natural number only!" << endl;
		return 0;
	}
		
	cout << "Number of interval: " << n << ":\n";
	const clock_t begin_time = clock();
	// computing pi and calculate time
	long double pi = calculate_pi(n);

	cout.precision(10);
	std::cout << "Calculation Time: " 
			  << setw(10)
			  << ((double)( clock () - begin_time )) / CLOCKS_PER_SEC
			  << " seconds" << endl;
	cout << "Aproximate of PI is: " << pi << endl;
	cout << "Error: " << M_PI - pi << endl;
}


