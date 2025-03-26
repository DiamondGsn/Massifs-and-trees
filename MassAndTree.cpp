#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <clocale>  
#include <limits>   
#include <queue>   

using namespace std;

// узел
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// высота узла
int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// новый узел
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

// правый поворот
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// левый поворот
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// баланс узла
int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// вставка узла
Node* insert(Node* node, int key) {
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    // балансировка
    int balance = getBalance(node);

    // ЛЛ
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // ПП
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // ЛП
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // ПЛ
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// прямой обход
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// центральный
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// обратный
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

// последовательный поиск
int sequentialSearch(const vector<vector<int>>& matrix, int target, int& steps) {
    steps = 0;
    for (size_t i = 0; i < matrix.size(); i++) { 
        for (size_t j = 0; j < matrix[i].size(); j++) { 
            steps++;
            if (matrix[i][j] == target)
                return steps;
        }
    }
    return -1;
}

// бинарный поиск
int binarySearch(const vector<int>& arr, int target, int& steps) {
    steps = 0;
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return steps;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// ввод матрицы
int inputMatrixSize(const string& prompt) {
    int size;
    while (true) {
        cout << prompt;
        cin >> size;
        if (cin.fail() || size <= 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Ошибка: введите целое число больше 0." << endl;
        } else {
            break;
        }
    }
    return size;
}

// ввод элемента для поиска по матрице
int inputTarget() {
    int target;
    while (true) {
        cout << "Введите элемент для поиска: ";
        cin >> target;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Ошибка: введите целое число." << endl;
        } else {
            break;
        }
    }
    return target;
}

// вывод матрицы
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); 
    srand(time(0));

    // ввод размеров матрицы
    int rows = inputMatrixSize("Введите количество строк матрицы: ");
    int cols = inputMatrixSize("Введите количество столбцов матрицы: ");

    // создание и заполнение матрицы случайными числами
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    // вывод основной матрицы
    cout << "\nОсновная матрица:" << endl;
    printMatrix(matrix);

    // ввод искомого элемента
    int target = inputTarget();

    int steps;

    // последовательный поиск
    cout << "\nПоследовательный поиск:" << endl;
    int seqResult = sequentialSearch(matrix, target, steps);
    if (seqResult != -1) {
        cout << "Элемент " << target << " найден за " << steps << " шагов." << endl;
    } else {
        cout << "Элемент " << target << " не найден." << endl;
    }

    // создание массива для бинарного поиска
    vector<int> flattenedAll;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) { 
            flattenedAll.push_back(matrix[i][j]);
        }
    }
    sort(flattenedAll.begin(), flattenedAll.end());

    // вывод массива для бинарного поиска
    cout << "\nМассив для бинарного поиска:" << endl;
    for (int val : flattenedAll) {
        cout << val << " ";
    }
    cout << endl;

    // бинарный поиск 
    cout << "\nБинарный поиск:" << endl;
    int binResult = binarySearch(flattenedAll, target, steps);
    if (binResult != -1) {
        cout << "Элемент " << target << " найден за " << steps << " шагов." << endl;
    } else {
        cout << "Элемент " << target << " не найден." << endl;
    }

    // генерация дерева
    Node* root = nullptr;
    for (int i = 0; i < rows; i += 2) { 
        for (int j = 0; j < cols; j += 2) { 
            root = insert(root, matrix[i][j]);
        }
    }

    // обходы + дерево
    cout << "\nДерево:" << endl;
    cout << "Прямой обход дерева: ";
    preOrder(root);
    cout << endl;

    cout << "Центральный обход дерева: ";
    inOrder(root);
    cout << endl;

    cout << "Обратный обход дерева: ";
    postOrder(root);
    cout << endl;

    return 0;
}