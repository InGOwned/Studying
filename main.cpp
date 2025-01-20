#include <iostream>

using namespace std;

#include <iostream>

struct Node {
    int data;
    Node* right;
    Node* left;
};

void Print(Node* sent);
void AddFront(Node* sent, int data);
void Remove(Node* sent);
void Sort(Node* sent);
void SwapData(Node* a, Node* b);
void Duplicate(Node* node);

bool isPrime(int n);
bool IsAllDigitsOdd(int n);
bool IsAllDigitsEven(int number);

int main() {
    Node* sent = new Node;
    sent->right = sent;
    sent->left = sent;

    int n;
    cout << "Enter numbers of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) { 
        int elem;
        cout << "Enter an element > 0: ";
        cin >> elem;
        AddFront(sent, elem);
    } 

    Node* p = sent->right;
    bool hasPrime = false;

    while (p != sent) 
    {
        if (isPrime(p->data))
        {
            hasPrime = true;
            break;
        }
        p = p->right;
    }

    if (!hasPrime) 
    {
        Sort(sent);
    } else {
        p = sent->right;
        while (p != sent) 
        {   
            Node* next = p->right;
            if (IsAllDigitsOdd(p->data))
            {
                Remove(p);
            } else if(IsAllDigitsEven(p->data))
            {
                Duplicate(p);
                p = p->right;
            }
            p = next;
        }
    }

    Print(sent);
}


void Print(Node* sent) {
    Node* p = sent->right;
    while (p != sent) {
        std::cout << p->data << " ";
        p = p->right;
    }
}

void AddFront(Node* sent, int data) {
    Node* p = new Node;
    p->data = data;
    p->right = sent->right;
    p->left = sent;
    sent->right->left = p;
    sent->right = p;
}

void Remove(Node* toRemove) {
    // Обновляем связи соседних узлов
    toRemove->left->right = toRemove->right;
    toRemove->right->left = toRemove->left;

    delete toRemove;
}

void Sort(Node* sent) {
    bool swapped;
    Node* p;
    Node* last = sent; // Последний отсортированный узел

    do {
        swapped = false;
        p = sent->right;

        while (p->right != last) {
            if (p->data < p->right->data) {
                SwapData(p, p->right);
                swapped = true;
            }
            p = p->right;
        }
        last = p;
    } while (swapped);
}

void SwapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void Duplicate(Node* node) {
    Node* newNode = new Node;
    newNode->data = node->data;
    newNode->right = node->right;
    newNode->left = node;
    node->right->left = newNode;
    node->right = newNode;
}

bool isPrime(int n) {
    for (int i = 2; i < n*0.5 + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool IsAllDigitsOdd(int number) {
    if (number == 0) return false;

    while (number != 0) {
        int digit = number % 10; 
        if (digit % 2 == 0) {  
            return false;
        }
        number /= 10;
    }
    return true; 
}

bool IsAllDigitsEven(int number) {
    if (number == 0) return true;

    while (number != 0) {
        int digit = number % 10;
        if (digit % 2 != 0) { 
            return false;
        }
        number /= 10;
    }
    return true; 
}
