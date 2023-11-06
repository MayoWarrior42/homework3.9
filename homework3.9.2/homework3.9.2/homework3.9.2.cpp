#include <iostream>


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
        simplify();
    }

    void simplify() {
        int commonDivisor = gcd(numerator, denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
    }

    Fraction operator+(const Fraction& other) const {
        int resultNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        int resultDenominator = denominator * other.denominator;
        return Fraction(resultNumerator, resultDenominator);
    }

    Fraction operator-(const Fraction& other) const {
        int resultNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        int resultDenominator = denominator * other.denominator;
        return Fraction(resultNumerator, resultDenominator);
    }

    Fraction operator*(const Fraction& other) const {
        int resultNumerator = numerator * other.numerator;
        int resultDenominator = denominator * other.denominator;
        return Fraction(resultNumerator, resultDenominator);
    }

    Fraction operator/(const Fraction& other) const {
        int resultNumerator = numerator * other.denominator;
        int resultDenominator = denominator * other.numerator;
        return Fraction(resultNumerator, resultDenominator);
    }

    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }

    Fraction& operator++() {
        numerator += denominator;
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp(numerator, denominator);
        numerator += denominator;
        return temp;
    }

    Fraction& operator--() {
        numerator -= denominator;
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp(numerator, denominator);
        numerator -= denominator;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

int main() {
    system("chcp 1251");
    int n1, d1, n2, d2;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> n1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> d1;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> n2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> d2;

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    Fraction f3 = f1 + f2;
    std::cout << f1 << " + " << f2 << " = " << f3 << std::endl;

    Fraction f4 = f1 - f2;
    std::cout << f1 << " - " << f2 << " = " << f4 << std::endl;

    Fraction f5 = f1 * f2;
    std::cout << f1 << " * " << f2 << " = " << f5 << std::endl;

    Fraction f6 = f1 / f2;
    std::cout << f1 << " / " << f2 << " = " << f6 << std::endl;

    Fraction f7 = ++f1 * f2;
    std::cout << "++" << f1 << " * " << f2 << " = " << f7 << std::endl;
    std::cout << "Значение дроби 1 = " << f1 << std::endl;

    Fraction f8 = f1-- * f2;
    std::cout << f1 << "-- * " << f2 << " = " << f8 << std::endl;
    std::cout << "Значение дроби 1 = " << f1 << std::endl;

    return 0;
}