//Author: Hope Walton
//Version: 06/17/2024
 

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Fraction
{
public:

	Fraction(int a, int b);
	// generate a fraction which is a/b

	Fraction(int a);
	// generate a fraction which is a/1

	Fraction();
	// generate a fraction which is 0/1. i.e 0

	int get_numerator() const;
	// return the numerator of the fraction

	int get_denominator() const;
	// return the denominator of the fraction

	void reduce();
	// reduce this fraction to simplest form. for instance,
	// 2/4 will be reduced to 1/2

	Fraction reciprocal() const;
	// return the reciprocal of this fraction

	friend Fraction operator +(const Fraction& f1, const Fraction& f2);
	// return the sum of f1 and f2,
	// the result is reduced

	friend Fraction operator -(const Fraction& f1, const Fraction& f2);
	// return the difference of f1 and f2,
	// the result is reduced

	friend Fraction operator *(const Fraction& f1, const Fraction& f2);
	// return the product of f1 and f2,
	// the result is reduced

	friend Fraction operator /(const Fraction& f1, const Fraction& f2);
	// return the quotient of f1 and f2,
	// the result is reduced

	friend Fraction operator -(const Fraction& f);
	// return the negation of f

	friend bool operator < (const Fraction& f1, const Fraction& f2);
	// return true if f1 is less than f2.
	// False otherwise

	friend bool operator > (const Fraction& f1, const Fraction& f2);
	// return true if f1 is greater than f2.
	// False otherwise

	friend bool operator <= (const Fraction& f1, const Fraction& f2);
	// return true if f1 is less or equal to f2.
	// False otherwise

	friend bool operator >= (const Fraction& f1, const Fraction& f2);
	// return true if f1 is greater or equal to f2.
	// False otherwise

	friend bool operator == (const Fraction& f1, const Fraction& f2);
	// return true if f1 is equal to f2.
	// False otherwise

	friend bool operator != (const Fraction& f1, const Fraction& f2);
	// return true if f1 is not equal to f2.
	// False otherwise

	friend istream& operator >> (istream& in, Fraction& f);
	// input f in the form of a/b, where b cannot be zero. Also,
	// if b is negative, the Fraction will change b to be positive.
	// So, again, 1/-3 will be changed to -1/3

	friend ostream& operator << (ostream& out, Fraction& f);
	// output a Fraction f in form of a/b

private:
	int num; // numerator of the fraction
	int den; // denominator of the fraction

	int gcd();
	// A prvate function that is used to find the gcd of numerator
	// and denominator by using Euclidean Algorithm
};


double test1();
 //Test all constructors and two get methods.

double test2();
// test neg, reduce, and reciprocal functions.

double test3();
// test add, sub, mul, and div functions.

double test4();
// test less, greater, equal, less_or_equal, greater_or_equal,
// not_equal.

double test5();
// test input and output function.

int main()
{
	double totalScore = 0.0;

	cout << "Let's see your grade. \n\n";
	system("pause");
	cout << endl;

	// Test constructors, and get functions
	totalScore += test1();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test neg, reciprocal, and reduce functions
	totalScore += test2();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test +, -, *, / operators
	totalScore += test3();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test all >, <, >=, <=, ==, != operators
	totalScore += test4();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test >> and << operators
	totalScore += test5();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	cout << "If you turn in your program to Dr. Zeng now, your will get " << totalScore << " out of 9\n";
	cout << "Dr. Zeng will read your program and decide if you will get 1 more point for program style\n";

	system("pause");
	return 0;

}


int Fraction::gcd()
{
	if (num == 0) return 1;

	int a = max(abs(num), abs(den));
	int b = min(abs(num), abs(den));

	while (b != 0)
	{
		int result = a % b;
		a = b;
		b = result;
	}

	return a;
}


Fraction::Fraction() : num(0), den(1)
{
}

Fraction::Fraction(int a) : num(a), den(1)
{
}

Fraction::Fraction(int a, int b)
{
	num = a;
	den = b;
	if (den < 0) {
		num *= -1;
		den *= -1;
	}
}

int Fraction::get_numerator() const 
{
	return num;
}

int Fraction::get_denominator() const 
{
	return den;
}

void Fraction::reduce() 
{
	int a = gcd();
	den /= a;
	num /= a;
}

Fraction Fraction::reciprocal() const
{
	if (num < 0) {
		// If denominator is negative, make it positive
		return Fraction(-den, -num);
	}
	else {
		// If denominator is positive, return reciprocal as is
		return Fraction(den, num);
	}
}
Fraction operator -(const Fraction& f)
{
	return Fraction(-(f.num), f.den);
}

Fraction operator +(const Fraction& f1, const Fraction& f2) 
{
	int den = f1.den * f2.den;
	int num = f1.num * f2.den + f1.den * f2.num;
	Fraction result = Fraction(num, den);
	result.reduce();
	return result;
}

Fraction operator -(const Fraction& f1, const Fraction& f2)
{
	return f1 + (-f2);
}

Fraction operator *(const Fraction& f1, const Fraction& f2)
{
	int num = f1.num * f2.num;
	int den = f1.den * f2.den;

	return Fraction(num, den);
}

Fraction operator /(const Fraction& f1, const Fraction& f2)
{
	Fraction reciprocalOfF2 = f2.reciprocal();
	Fraction result = f1 * reciprocalOfF2;
	result.reduce();
	return result;
}

bool operator < (const Fraction& f1, const Fraction& f2)
{
	Fraction f = f1 - f2;
	return f.num < 0;
}

bool operator == (const Fraction& f1, const Fraction& f2)
{
	Fraction f = f1 - f2;
	return f.num == 0;
}

bool operator <= (const Fraction& f1, const Fraction& f2)
{
	return (f1 < f2) || (f1 == f2);
}

bool operator > (const Fraction& f1, const Fraction& f2)
{
	return !(f1 <= f2);
}

bool operator >= (const Fraction& f1, const Fraction& f2)
{
	return !(f1 < f2);
}

bool operator != (const Fraction& f1, const Fraction& f2)
{
	return !(f1 == f2);
}

istream& operator >> (istream& in, Fraction& f)
{
	int num, den;
	char slash;
	cin >> num;
	cin >> slash; // read '/'
	cin >> den;
	f = Fraction(num, den);
	if (den < 0) {
		num = -num;
		den = -den;
	}
	return in;
}
ostream& operator << (ostream& out, Fraction& f)
{
	out << f.num << "/" << f.den;
	return out;
}

//Test constructors and two get methods

double test1()
{
	double result = 1.5;
	// Test no argument constructor
	Fraction f1; // the fraction should be 0/1
	if (f1.get_numerator() != 0 || f1.get_denominator() != 1)
	{
		cout << "The constructor with no arguments was wrong.\n";
		result -= 0.5;
	}
	// Test one argument constructor
	Fraction f2(2); // the fraction should shoule be 2/1
	if (f2.get_numerator() != 2 || f2.get_denominator() != 1)
	{
		cout << "The constructor with one argument was wrong.\n";
		result -= 0.5;
	}
	// Test two arguments constructors
	Fraction f3(3, -4); // the fraction should be -3/4
	if (f3.get_numerator() != -3 || f3.get_denominator() != 4)
	{
		cout << "The constructor with two arguments was wrong. Make sure that the denominator is always positive.\n";
		result -= 0.5;
	}
	// finish test
	if (result < 1.5 && result > 0)
		cout << "Test 1 partially failed. You got " << result << " more points\n";
	else if (result > 1.4)
		cout << "Test 1 fully passed. You got 1.5 more points\n";
	else
		cout << "Test 1 completely failed. You may check your constructors and get methods\n";
	return result;
}

 /*Test neg, reduce, and reciprocal functions.*/

double test2()
{
	double result = 1.5;
	Fraction f1(12, -15), f2(2, 3), f3, f4;
	// Test neg
	f3 = -f1; // f3 is 12/15
	f4 = -f2; // f4 is -2/3
	if (f3.get_numerator() != 12 || f3.get_denominator() != 15
		|| f4.get_numerator() != -2 || f4.get_denominator() != 3)
	{
		cout << "The negation function was wrong.\n";
		result -= 0.5;
	}
	// Test reciprocal
	f3 = f1.reciprocal(); // f3 is -15/12
	f4 = f2.reciprocal(); // f4 is 3/2
	if (f3.get_numerator() != -15 || f3.get_denominator() != 12
		|| f4.get_numerator() != 3 || f4.get_denominator() != 2)
	{
		cout << "The reciprocal function was wrong.\n";
		result -= 0.5;
	}

	// Test reduce
	f1.reduce(); // f1 is -4/5
	f2.reduce(); // f2 is 2/3
	if (f1.get_numerator() != -4 || f1.get_denominator() != 5 || f2.get_numerator() != 2 || f2.get_denominator() != 3)
	{
		cout << "The reduce function was wrong.\n";
		result -= 0.5;
	}
	// finish test
	if (result < 1.5 && result > 0)
		cout << "Test 2 partially failed. You got " << result << " more points\n";
	else if (result > 1.4)
		cout << "Test 2 fully passed. You got 1.5 more points\n";
	else
		cout << "Test 2 completely failed. \n";
	return result;
}

 //Test +, -, *, and / operators.
 
double test3()
{
	Fraction f1(-1, 2), f2(3, 5), f;
	double result = 3.0;
	// Test +
	f = f1 + f2; // f is -1/2+3/5 = 1/10
	if (f.get_numerator() != 1 || f.get_denominator() != 10)
	{
		cout << "The add function was wrong.\n";
		result -= 1.0;
	}
	// Test subtraction
	f = f1 - f2; // f is -1/2 - 3/5 = -11/10
	if (f.get_numerator() != -11 || f.get_denominator() != 10)
	{
		cout << "The sub function was wrong.\n";
		result -= 0.5;
	}
	// Test multiplication
	f = f1 * f2; // f is -3/10
	if (f.get_numerator() != -3 || f.get_denominator() != 10)
	{
		cout << "The mul function was wrong.\n";
		result -= 1.0;
	}
	// Test division
	f = f1 / f2; // f is -5/6
	if (f.get_numerator() != -5 || f.get_denominator() != 6)
	{
		cout << "The div function was wrong.\n";
		result -= 0.5;
	}
	// finish test
	if (result < 3.0 && result > 0)
		cout << "Test 3 partially failed. You got " << result << " more points\n";
	else if (result > 2.9)
		cout << "Test 3 fully passed. You got 3.0 more points\n";
	else
		cout << "Test 3 completely failed. \n";
	return result;

}

 //Test less, greater, equal, less_or_equal, greater_or_equal,

double test4()
{

	Fraction f1(-1, 2), f2(3, 5), f3(2, -4);
	double result = 2.0;
	// test <
	if (!(f1 < f2) || f1 < f3 || f2 < f3)
	{
		cout << "the < operator was wrong.\n";
		result -= 0.5;
	}
	// test >
	if (f1 > f2 || !(f2 > f1) || f1 > f3)
	{
		cout << "the > operator was wrong.\n";
		result -= 0.5;
	}
	// test ==
	if (f1 == f2 || !(f1 == f3) || f2 == f3)
	{
		cout << "the equal function was wrong.\n";
		result -= 0.5;
	}
	// test <=
	if (!(f1 <= f2) || !(f1 <= f3) || f2 <= f3)
	{
		cout << "the less_or_equal function was wrong.\n";
		result -= 0.5;
	}
	// test >=
	if (f1 >= f2 || !(f1 >= f3) || !(f2 >= f3))
	{
		cout << "the greater_or_equal function was wrong.\n";
		result -= 0.5;
	}
	// test !=
	if (!(f1 != f2) || f1 != f3 || !(f2 != f3))
	{
		cout << "the not_equal function was wrong.\n";
		result -= 0.5;
	}

	// finish test
	if (result < 2.0 && result > 0)
		cout << "test 4 partially failed. you got " << result << " more points\n";
	else if (result > 1.9)
		cout << "test 4 fully passed. you got 2.0 more points\n";
	else
		cout << "test 4 completely failed. \n";
	return max(result, 0.0);
}

//Test input and output

double test5()
{
	double result = 1.0;
	Fraction f;
	cout << "This test has to be interactive, please follow the instruction\n";
	cout << "Enter a fraction exactly as 3/-4:";
	cin >> f;
	if (f.get_denominator() != 4 || f.get_numerator() != -3)
	{
		cout << "The input function is not correct\n";
		result -= 0.5;
	}
	Fraction f1(3, -4);
	cout << f1;
	cout << "\nDoes the previous line show you -3/4? Y or N: ";
	char choice;
	cin >> choice;
	if (choice != 'y' && choice != 'Y')
	{
		cout << "The output function is not correct\n";
		result -= 0.5;
	}
	// finish test
	if (result < 1.0 && result > 0)
		cout << "Test 5 partially failed. You got " << result << " more points\n";
	else if (result > 0.9)
		cout << "Test 5 fully passed. You got 1.0 more points\n";
	else
		cout << "Test 5 completely failed. \n";
	return result;
}