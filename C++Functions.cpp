// Write a function that determines whether a number is prime.
#include<iostream>
#include<sstream>
#include<vector>

using namespace std;



bool isprime(int n)
{
	// 1 is not a prime number
	if(n==1){
		return false;
	}
	
	// check the prime start from 2 to int(sqrt(x))
	int i=2;

	while(i*i<=n){
	// whether n is prime or not by checking the remainder
		if (n%i==0){
			return false;
		}
		i++;
	}
	return true;
}
	

void test_isprime( )
{
	cout << "\n=============Test isprime================\n";
	cout << " isprime (2) = " << isprime (2) << '\n';
	cout << " isprime (10) = " << isprime (10) << '\n';
	cout << " isprime (17) = " << isprime (17) << '\n';
}

vector<int> factorize(int n){
	vector<int> answer;
	
	for(int i = 1; i <= n; i++){
		if(n % i == 0)
			answer.push_back(i);
	}
	
	return answer;
}

void print_vector(const vector<int>& v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
		if(i < v.size() - 1)
			cout << ", ";
		else
			cout << endl;
	}
	cout << endl;
}

void test_factorize(){
	cout << "\n=============Test Factorize==============\n";
	cout << "Factors of 2:\n";
	print_vector(factorize(2));
	cout << "Factors of 72:\n";
	print_vector(factorize(72));
	cout << "Factors of 196:\n";
	print_vector(factorize(196));
}

vector<int> prime_factorize(int n){
	vector<int> factors = factorize(n);
	vector<int> prime_factors;
	for(auto f : factors){
		if(isprime(f))
			prime_factors.push_back(f);
	}
	return prime_factors;
}

void test_prime_factorize(){
	cout << "\n=============Test Prime Factorize==============\n";
	cout << "Prime Factors of 2:\n";
	print_vector(prime_factorize(2));
	cout << "Prime Factors of 72:\n";
	print_vector(prime_factorize(72));
	cout << "Prime Factors of 196:\n";
	print_vector(prime_factorize(196));
}

int main()
{
	test_isprime();
	test_factorize();
	test_prime_factorize();
	return 0;
}