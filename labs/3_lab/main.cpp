#include <iostream>

class Complex {
private:
    double real;    // Действительная часть
    double imag;    // Мнимая часть

public:
    // Базовый конструктор
    Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    // Конструктор копирования
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    // Оператор присваивания копированием
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    // Деструктор
    ~Complex() {}

    // Оператор +=
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // Оператор +
    friend Complex operator+(const Complex& left, const Complex& right) {
        Complex result;
        result.real = left.real + right.real;
        result.imag = left.imag + right.imag;
        return result;
    }

    // Оператор *=
    Complex& operator*=(const Complex& other) {
        double tempReal = real * other.real - imag * other.imag;
        double tempImag = real * other.imag + imag * other.real;
        real = tempReal;
        imag = tempImag;
        return *this;
    }

    // Оператор *
    friend Complex operator*(const Complex& left, const Complex& right) {
        Complex result;
        result.real = left.real * right.real - left.imag * right.imag;
        result.imag = left.real * right.imag + left.imag * right.real;
        return result;
    }

    // Префиксный оператор ++
    Complex& operator++() {
        real += 1.0;
        return *this;
    }

    // Постфиксный оператор ++
    Complex operator++(int) {
        Complex temp(*this);
        real += 1.0;
        return temp;
    }

    // Оператор вывода <<
    friend std::ostream& operator<<(std::ostream& output, const Complex& number) {
        output << number.real;
        if (number.imag >= 0)
            output << "+";
        output << number.imag << "i";
        return output;
    }

    // Оператор ввода >>
    friend std::istream& operator>>(std::istream& input, Complex& number) {
        std::cout << "Введите действительную часть: ";
        input >> number.real;
        std::cout << "Введите мнимую часть: ";
        input >> number.imag;
        return input;
    }
};

int main() {
    Complex first(10, 15);
    std::cout << "Первое комплексное число: " << first << std::endl;

    Complex second;
    std::cout << "Введите второе комплексное число: ";
    std::cin >> second;
    std::cout << "Второе комплексное число: " << second << std::endl;

    Complex third = first + second;
    std::cout << "Сумма: " << third << std::endl;

    third *= Complex(2, 2);
    std::cout << "Умножение на (2 + 2i): " << third << std::endl;

    Complex fourth = ++third;
    std::cout << "Префиксный инкремент: " << fourth << std::endl;

    Complex fifth = third++;
    std::cout << "Постфиксный инкремент: " << fifth << std::endl;
    std::cout << "Текущее значение: " << third << std::endl;

    return 0;
}
