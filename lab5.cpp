//Варіант 4 – Непарні завдання 1,3,5
//1.Заданий рядок тексту, який в тому числі містить множину дужок: “(”, “{”,”[” що відкриваються і закриваються. Рядок вважається коректним в тому випадку, якщо всім дужка, що відкриваються є відповідні дужки, що закриваються. Перевірити конкретність рядка з використанням стека.
//3. Дано дві не пусті черги, які містять однакову кількість елементів, об'єднати черги в одну з збереженням упорядкованості елементів
//5. Написати функцію, яка дозволяє визначити число входжень елемента x в бінарне дерево. 

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool checkBrackets(const string& str) {
    stack<char> brackets;
    
    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch); 
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (brackets.empty()) return false; 
            char openBracket = brackets.top(); 
            if ((ch == ')' && openBracket == '(') || (ch == '}' && openBracket == '{') || (ch == ']' && openBracket == '[')) {
                brackets.pop(); 
            } else {
                return false; 
            }
        }
    }
    
    return brackets.empty(); 
}

queue<int> mergeQueues(queue<int>& qA, queue<int>& qB) {
    queue<int> result;
    
    while (!qA.empty() && !qB.empty()) {
        if (qA.front() < qB.front()) {
            result.push(qA.front()); 
            qA.pop(); 
        } else {
            result.push(qB.front()); 
            qB.pop(); 
        }
    }
    
    while (!qA.empty()) {
        result.push(qA.front()); 
        qA.pop(); 
    }
    
    while (!qB.empty()) {
        result.push(qB.front()); 
        qB.pop(); 
    }
    
    return result; 
}

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int countOccurrences(TreeNode* root, int target) {
    if (root == nullptr) {
        return 0; 
    }
    
    int count = 0;
    
    if (root->value == target) {
        count++; 
    }
    
    count += countOccurrences(root->left, target);
    count += countOccurrences(root->right, target);
    
    return count; 
}

int main() {
    // Task 1: Checking brackets
    string inputStr;
    cout << "Enter a string for bracket checking: ";
    cin.ignore(); // Add this line to ignore the newline character in the buffer
    getline(cin, inputStr);
    bool isCorrect = checkBrackets(inputStr);
    cout << "String is correct: " << (isCorrect ? "Yes" : "No") << endl;

    // Task 2: Merging queues
    queue<int> queueA, queueB;
    int sizeA, sizeB;
    cout << "Enter size of queue A: ";
    cin >> sizeA;
    cout << "Enter elements of queue A: ";
    for (int i = 0; i < sizeA; i++) {
        int element;
        cin >> element;
        queueA.push(element);
    }

    cout << "Enter size of queue B: ";
    cin >> sizeB;
    cout << "Enter elements of queue B: ";
    for (int i = 0; i < sizeB; i++) {
        int element;
        cin >> element;
        queueB.push(element);
    }

    cout << "Merged queue:" << endl;
    queue<int> mergedQueue = mergeQueues(queueA, queueB);
    while (!mergedQueue.empty()) {
        cout << mergedQueue.front() << " ";
        mergedQueue.pop();
    }
    cout << endl;

    // Task 3: Counting occurrences in the binary tree
    int targetValue;
    cout << "Enter a number to search in the binary tree: ";
    cin >> targetValue;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(1);

    cout << "Occurrences in the binary tree:" << endl;
    int occurrences = countOccurrences(root, targetValue);
    cout << "Number of occurrences of " << targetValue << " in the binary tree: " << occurrences << endl;

    return 0;
}
