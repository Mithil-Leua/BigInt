//Standard libraries.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <istream>
#include <ostream>
#include <string>
#include <stdexcept>

using namespace std;

class bigint{
	public : 
		//minus used to maintain sign of the number.
		bool minus ;
		//Stores the number in form of vector.
		vector<int> array;

		//constructors
		bigint();
		bigint(string);

		//Helper Functions
		//Used for the convenience. :p 
		
		//read input to console.
		void getint();
		//write output to console.
		void printint();
		//overloaded output stream
		std::ostream &operator <<(bigint);

		//revert the number.
		//helper function.
		bigint revert();
		//removes insignificant zeroes from number.
		//helper function.
		void removeinsignificantzero();
		
		//operators
		//adds two number and stores the result in the object which called it. 
		void add(bigint);
		//subtracts two number and stores the result in the object which called it.
		void subtract(bigint);
		//multiplies two number and stores the product in the object which called it.
		void multiply(bigint);
		//divides two number and stores the quotient in the object which called it.
		//Integer division , does not deal with floating point division.
		void divide(bigint);

		//Other standard functions
		//Computes factorial and stores the result in the object which called it.
		void factorial();
		//x.power(y);
		//calculates x^y and stores the result in x.
		void power(bigint);
		//returns gcd of two numbers in the form of "bigint".
		bigint gcd(bigint,bigint);

		//overloaded operators
		bigint operator+(bigint);
		bigint operator-(bigint);
		bigint operator*(bigint);
		bigint operator/(bigint);

		//prefix and postfix meaning are kept standard.
		// overloaded prefix ++ operator
		bigint operator ++();
		// overloaded postfix ++ operator
		bigint operator ++(int);
		// overloaded prefix -- operator	
		bigint operator --();
		// overloaded postfix -- operator
		bigint operator --(int);

		//Overloaded assignment operators.
		//returns the result as a bigint. 
		bigint operator+=(bigint);
		bigint operator-=(bigint);
		bigint operator*=(bigint);
		bigint operator/=(bigint);

		//Overloaded Bitwise operators.
		bigint operator~();
		bigint operator&(bigint);
		bigint operator|(bigint);
		bigint operator^(bigint);

		//Overloaded modulo.
		//calculates x%y or x mod y and returns a bigint.
		bigint operator%(bigint);

		//logical.
		//boolean functions.
		//Checks whether a number is greater than a other given number.
		//a.isgreater(b) returns true if a>b else false.
		bool isgreater(bigint);
		//Checks whether given two numbers are equal or not.
		//returns true if a==b else false.
		bool isequal(bigint);
		//Checks whether a number is negative or not.
		//returns true if a < 0. 
		bool isnegative();
		//Checks if it is zero or not.
		//returns true if a == 0.
		bool iszero();

		//Overloaded logical operations.
		//returns true when conditions are satisfied.
		bool operator>(bigint);
		bool operator<(bigint);
		bool operator==(bigint);
		bool operator>=(bigint);
		bool operator<=(bigint);

		//Binary and Decimal conversions.
		//returns a bigint of the resultant.
		bigint ConvertToBinary();
		bigint ConvertToDecimal();
};
