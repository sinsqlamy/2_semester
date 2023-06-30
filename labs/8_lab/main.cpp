#include <iostream>
#include "stack.h"

int main() {
    setlocale(LC_ALL, "Rus");
    Stack<int> first(1);
//    first.push(1);
//    first.push(2);
    try {
        first.pop();
    }
    catch (const std::out_of_range& currentError) {
        std::cerr << "������: ";
        std::cerr << currentError.what() << std::endl;
    }
    catch ( const std::bad_alloc& currentError){
        std::cerr << "��������� ���������� ���������� ���������:" << std::endl;
    }
    system("pause");
}
