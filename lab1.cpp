//Знайти мінімальний і максимальний елементи і їх порядкові номери(розмірність 17):
#include <iostream>

int main() {
    const int size = 17;
    int array[size] = {5, 3, 8, 12, 1, 7, 9, 4, 6, 15, 10, 2, 14, 11, 13, 16, 17};

    int minElement = array[0];
    int maxElement = array[0];
    int minIndex = 0;
    int maxIndex = 0;

    // Знаходження мінімального та максимального елементів та їхніх порядкових номерів
    for (int i = 1; i < size; ++i) {
        if (array[i] < minElement) {
            minElement = array[i];
            minIndex = i;
        }
        if (array[i] > maxElement) {
            maxElement = array[i];
            maxIndex = i;
        }
    }

    // Виведення результатів
    std::cout << "Мінімальний елемент: " << minElement << std::endl;
    std::cout << "Порядковий номер мінімального елемента: " << minIndex << std::endl;
    std::cout << "Максимальний елемент: " << maxElement << std::endl;
    std::cout << "Порядковий номер максимального елемента: " << maxIndex << std::endl;

    return 0;
}
 
//Знайти в масиві і вивести на екран суму елементів кожного непарного стовпця(4х5):
#include <iostream>

int main() {
    const int rows = 4;
    const int cols = 5;
    int array[rows][cols] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    // Знаходження та виведення сум елементів кожного непарного стовпця
    for (int j = 0; j < cols; j += 2) {
        int columnSum = 0;
        for (int i = 0; i < rows; ++i) {
            columnSum += array[i][j];
        }
        std::cout << "Сума елементів непарного стовпця " << j << ": " << columnSum << std::endl;
    }

    return 0;
}
 

