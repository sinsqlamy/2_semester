#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Базовый конструктор
    Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    // Конструктор копирования
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    // Оператор присваивания копированием
    Complex& operator=(const Complex& other) {
        if (this == &other) return *this;
        real = other.real;
        imag = other.imag;
        return *this;
    }

    // Деструктор
    ~Complex() {}

    // Операторы += и +
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Операторы *= и *
    Complex& operator*=(const Complex& other) {
        double temp_real = real * other.real - imag * other.imag;
        imag = real * other.imag + imag * other.real;
        real = temp_real;
        return *this;
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    // Операторы ++ префиксный и постфиксный
    Complex& operator++() {
        real += 1.0;
        return *this;
    }

    Complex operator++(int) {
        Complex temp = *this;
        ++(*this);
        return temp;
    }

    // Операторы ввода и вывода
    friend std::istream& operator>>(std::istream& is, Complex& num) {
        is >> num.real >> num.imag;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& num) {
        os << num.real << " + " << num.imag << "i";
        return os;
    }
};

int main() {
    // Пример работы с классом Complex
    Complex a(2.0, 3.0);
    Complex b(1.0, -2.0);

    Complex c = a + b;
    Complex d = a * b;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << c << std::endl;
    std::cout << "a * b: " << d << std::endl;

    a += b;
    std::cout << "a += b: " << a << std::endl;

    Complex e = ++a;
    std::cout << "++a: " << a << std::endl;
    std::cout << "e: " << e << std::endl;

    Complex f = a++;
    std::cout << "a++: " << a << std::endl;
    std::cout << "f: " << f << std::endl;

    return 0;
}
