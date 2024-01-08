//Варіант 4: Створити новий (третій) однозв'язний список. Помістити в нього перші п'ять елементів з першого і другого списків. Результуючий список вивести на екран(списки заповнити з клавіатури мова С++
#include <iostream>

// Структура для представлення елемента однозв'язного списку
struct Node {
    int data;
    Node* next;
};

// Функція для додавання елемента в кінець однозв'язного списку
void append(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функція для виведення списку на екран
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* list1 = nullptr; // Перший список
    Node* list2 = nullptr; // Другий список
    Node* result = nullptr; // Результуючий список

    // Заповнення перших двох списків з клавіатури
    std::cout << "Введіть перші п'ять елементів для першого списку:" << std::endl;
    for (int i = 0; i < 5; i++) {
        int data;
        std::cin >> data;
        append(list1, data);
    }

    std::cout << "Введіть перші п'ять елементів для другого списку:" << std::endl;
    for (int i = 0; i < 5; i++) {
        int data;
        std::cin >> data;
        append(list2, data);
    }

    // Додавання перших п'ять елементів з обох списків до результуючого списку
    Node* current1 = list1;
    Node* current2 = list2;
    for (int i = 0; i < 5; i++) {
        append(result, current1->data);
        append(result, current2->data);
        current1 = current1->next;
        current2 = current2->next;
    }

    // Виведення результуючого списку
    std::cout << "Результуючий список:" << std::endl;
    printList(result);

    // Звільнення пам'яті
    while (list1 != nullptr) {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;
    }
    while (list2 != nullptr) {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }
    while (result != nullptr) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}


//Завданя 12: Створити новий(третій) однозв’язний список. Помістити в нього всі символи нижнього регістра з перших двох. Результуючий список вивести на екран
#include <iostream>
// Структура для представлення елемента однозв'язного списку
struct Node {
    char data;
    Node* next;
};

// Функція для додавання елемента в кінець однозв'язного списку
void append(Node*& head, char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функція для виведення списку на екран
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        if (islower(current->data)) {
            std::cout << current->data;
        }
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* list1 = nullptr; // Перший список
    Node* list2 = nullptr; // Другий список
    Node* result = nullptr; // Результуючий список

    // Заповнення перших двох списків з клавіатури
    std::string input1, input2;
    std::cout << "Введіть перший рядок: ";
    std::cin >> input1;
    std::cout << "Введіть другий рядок: ";
    std::cin >> input2;

    // Додавання всіх маленьких букв з обох рядків до результуючого списку
    for (char c : input1) {
        if (islower(c)) {
            append(result, c);
        }
    }
    for (char c : input2) {
        if (islower(c)) {
            append(result, c);
        }
    }

    // Виведення результуючого списку
    std::cout << "Результуючий список маленьких букв: ";
    printList(result);

    // Звільнення пам'яті
    while (list1 != nullptr) {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;
    }
    while (list2 != nullptr) {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }
    while (result != nullptr) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
