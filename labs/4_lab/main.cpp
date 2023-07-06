#include <matrix.h>

int main() {
    matrix<int, 2, 2> firstMatrix{};
    std::cin >> firstMatrix;

    matrix<int, 2, 4> secondMatrix{};
    std::cin >> secondMatrix;

    std::cout << "First Matrix:" << std::endl;
    std::cout << firstMatrix << std::endl;

    std::cout << "Second Matrix:" << std::endl;
    std::cout << secondMatrix << std::endl;

    std::cout << "Matrix Multiplication Result:" << std::endl;
    std::cout << (firstMatrix * secondMatrix) << std::endl;

    return 0;
};