//Варіант 4: Скласти рекурсивну функцію для обчислення кінцевої суми S = 2 +4 +...+2n
#include <iostream>

// Рекурсивна функція для обчислення суми
int calculateSum(int n) {
    // Базовий випадок: сума для n=0 дорівнює 0
    if (n == 0) {
        return 0;
    } else {
        // Рекурсивний виклик: сума для n обчислюється як сума для (n-1) плюс 2n
        return calculateSum(n - 1) + 2 * n;
    }
}

int main() {
    int n;
    std::cout << "Введіть n: ";
    std::cin >> n;
    
    int result = calculateSum(n);
    
    std::cout << "Сума S = 2 + 4 + ... + 2n дорівнює " << result << std::endl;
    
    return 0;
}
