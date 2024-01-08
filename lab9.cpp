//1.	Заповнити масив цілочисельними випадковими числами в діапазоні (10-100).
//2.	Розмір масиву N обчислюється як ціла частина від значення виразу N = 20 + 0.6 * K, де K – номер студента в журналі.
//3.	Відсортувати масив за методом бульбашки.
//4.	Знайти ключ, що знаходиться в середині лівої частини масиву.
//Студентам з парними номерами варіантів використовувати метод бінарного пошуку.

#include <iostream>
#include <cstdlib>
#include <ctime>

const int LOWER_LIMIT = 10;
const int UPPER_LIMIT = 100;

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (UPPER_LIMIT - LOWER_LIMIT + 1) + LOWER_LIMIT;
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    const int K = 2;
    int N = 20 + 0.6 * K;

    srand(time(0));

    int array[N];
    fillArray(array, N);

    std::cout << "Випадковий масив:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(array, N);

    std::cout << "Відсортований масив:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Розмір масиву (N): " << N << std::endl;

    int keyToFind = array[N / 2 - 1];
    int result = binarySearch(array, 0, N / 2 - 1, keyToFind);

    if (result != -1) {
        std::cout << "Ключ " << keyToFind << " знайдено на позиції " << result << std::endl;
    } else {
        std::cout << "Ключ " << keyToFind << " не знайдено в масиві" << std::endl;
    }

    return 0;
}


