// Sample program demonstrating the use of the Big Integer Library.

//Standard libraries.
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
//Sample program.
//Describes the general format and usage of most of the functions.
//contains all headers and function definitions.
#include "bigint.cc"

using namespace std;

int main(){
	bigint a;

	//uncomment the following line to read input from console.
	//a.getint();

	//you could either use console or hardcode in the form of string to give input.
	bigint m("84567892345678765437542332345674532465");
	bigint n("2562475234678654232456765456623456432");

	//Refer to the header file for more details of function.
	//prints the number to console.
	//Use printint() function or the standard output stream.
	m.printint();  //just an example , a much better way would be though to use cout << m ;

	//You could either way use overloaded operators as well.
	//uncomment the below line.
	// bigint c = m+n; 
	//Arithmetic Operations.
	//adds m and n and stores m+n in m.
	m.add(n);
	m.printint();
	//subtracts n and m and stores n-m in n.
	n.subtract(m);
	n.printint();

	bigint x("74148825");
	bigint y("345715243");

	//multiplies x and y and stores the product in x. 
	x.multiply(y);
	//divides y and m and stores the quotient in y.
	y.divide(m);
	x.printint();
	y.printint();

	//Some special functions like factorial,power and gcd.
	bigint n1("256");
	//Calculates factorial and stores the result in n1.
	n1.factorial();
	n1.printint();

	//Calculates gcd of two numbers and gcd function returns a bigint.
	//just a another way to use, you could use in other ways as well.
	bigint hcf = hcf.gcd(m,n1);
	hcf.printint();


	//Overloaded functions.
	hcf++;
	hcf.printint();
	hcf--;
	hcf.printint();	

	//Logical functions.
	cout << hcf.isgreater(m) << endl;
	cout << hcf.isequal(m) << endl;
	cout << hcf.isequal(hcf) << endl;

	return 0;
}

/*
sample program generates this output:

mithil@mithil-HP-15-Notebook-PC:~/pop/BigInt/BigInt$ ./a.out 
84567892345678765437542332345674532465
87130367580357419669999097802297988897
-84567892345678765437542332345674532465
25634379053039475
252029290997612794498618904698
857817775342842654119082271681232625157781520279485619859655650377269452553147589377440291360451408450375885342336584306157196834693696475322289288497426025679637332563368786442675207626794560187968867971521143307702077526646451464709187326100832876325702818980773671781454170250523018608495319068138257481070252817559459476987034665712738139286205234756808218860701203611083152093501947437109101726968262861606263662435022840944191408424615936000000000000000000000000000000000000000000000000000000000000000
103
104
103
0
0
1

*/