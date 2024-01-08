//1. Прямий метод пошуку. Нехай задамо масив S з "n" елементів та масив Р з m елементів(Студенти вибирають самостійно). Необхідно знайти перше входження масиву Р у масиві S.
//2. Алгоритм Кнута, Моріса і Прата (КМП). На вхід надходять два масиви символів: S розміром n (текст) та інший масив Р розміром m (слово), які студент вибирає самостійно. Необхідно знайти перше входження слова у тексті. 
//Підготувати необхідний код мовою С++ для реалізації методів(відповідних)

// Прямий метод пошуку
#include <iostream>
#include <string>
int directSearch(const std::string& S, const std::string& P) {
    int n = S.length();
    int m = P.length();

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && S[i + j] == P[j]) {
            ++j;
        }

        if (j == m) {
            return i; // Знайдено входження
        }
    }

    return -1; // Не знайдено входження
}

int main() {
    std::string S = "абракадабра";
    std::string P = "кадабр";

    std::cout << "Масив S: " << S << std::endl;
    std::cout << "Масив P: " << P << std::endl;

    int result = directSearch(S, P);

    if (result != -1) {
        std::cout << "Перше входження P у S починається з позиції " << result << std::endl;
    } else {
        std::cout << "P не знайдено у S" << std::endl;
    }

    return 0;
}

 


//Алгоритм Кнута, Моріса і Прата (КМП):

#include <iostream>
#include <vector>
#include <string>

std::vector<int> computeLPS(const std::string& P) {
    int m = P.length();
    std::vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (P[i] == P[len]) {
            ++len;
            lps[i] = len;
            ++i;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }

    return lps;
}

int KMP(const std::string& S, const std::string& P) {
    int n = S.length();
    int m = P.length();

    std::vector<int> lps = computeLPS(P);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (P[j] == S[i]) {
            ++i;
            ++j;
        }

        if (j == m) {
            return i - j; // Знайдено входження
        } else if (i < n && P[j] != S[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }

    return -1; // Не знайдено входження
}

int main() {
    std::string S = "абракадабра";
    std::string P = "кадабр";

    std::cout << "Масив S: " << S << std::endl;
    std::cout << "Масив P: " << P << std::endl;

    int result = KMP(S, P);

    if (result != -1) {
        std::cout << "Перше входження P у S починається з позиції " << result << std::endl;
    } else {
        std::cout << "P не знайдено у S" << std::endl;
    }

    return 0;
}
