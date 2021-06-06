#include<iostream>
#include <cstdlib>

using namespace std;

void collatz_demo(int n){	
	if(n == 0)
		return;
	
	if(n % 2 == 0){
		n = n / 2;
		if( n == 1)
			cout << n << endl;
		else {
			cout << n << ", ";
			collatz_demo(n);
		}
	}
	else{
		n = (n * 3) + 1;
		cout << n << ", ";
		collatz_demo(n);
	}
	
}

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	if(n <= 0){
		cout << "Positive natural number only!" << endl;
		return 0;
	}
		
	cout << "Start Collatz sequence for " << n << ":\n";
	collatz_demo(n);
	return 0;
}