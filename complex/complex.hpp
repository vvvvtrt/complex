#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>
#include <cmath>


double const pi = 4 * std::atan(1);

struct Complex {
	Complex() {}
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);


	bool operator==(const Complex& rhs) const { return (re == rhs.re && im == rhs.im); }
	bool operator!=(const Complex& rhs) const { return (!(operator==(rhs))); }

	bool operator>(const Complex& rhs) const { return (std::sqrt(re * re + im * im) > std::sqrt(rhs.re * rhs.re + rhs.im * rhs.im)); }
	bool operator<(const Complex& rhs) const { return (std::sqrt(re * re + im * im) < std::sqrt(rhs.re * rhs.re + rhs.im * rhs.im)); }

	bool operator>=(const Complex& rhs) const { return (operator==(rhs) || operator>(rhs)); }
	bool operator<=(const Complex& rhs) const { return (operator==(rhs) || operator<(rhs)); }

	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return (operator+=(Complex(rhs))); }

	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return (operator-=(Complex(rhs))); }

	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs) { return (operator*=(Complex(rhs))); }

	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return (operator/=(Complex(rhs))); }

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double abs() { return std::sqrt(re * re + im * im); }
	void conjugate() { im = -im; }

	void pow(int base);
	double argument();
	void sqrt(int base);



	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};



Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const double& lhs, const Complex& rhs); 
Complex operator+(const Complex& lhs, const double& rhs); 

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const double& lhs, const Complex& rhs); 
Complex operator-(const Complex& lhs, const double& rhs); 

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const double& lhs, const Complex& rhs); 
Complex operator*(const Complex& lhs, const double& rhs); 

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const double& lhs, const Complex& rhs); 
Complex operator/(const Complex& lhs, const double& rhs); 


double abs(const Complex& num);
double argument(const Complex& num);

Complex pow(const Complex& lhs, int n);
Complex conjugate(const Complex& num);
Complex sqrt(Complex num, int base);

void errors(std::string message);


inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

#endif