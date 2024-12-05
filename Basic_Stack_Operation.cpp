#include <iostream>

using namespace std;

class Stack {
private:
    int top;
    int maxSize;
    int* stackArray;

public:
    Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << value << ".\n";
        } else {
            stackArray[++top] = value;
            cout << "Pushed " << value << " onto the stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
        } else {
            cout << "Popped " << stackArray[top--] << " from the stack.\n";
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return -1;
        } else {
            return stackArray[top];
        }
    }
};

int main() {
    Stack numStack(5);

    cout << "Is the stack empty? " << (numStack.isEmpty() ? "Yes" : "No") << endl;

    numStack.push(10);
    numStack.push(20);
    numStack.push(30);

    cout << "Is the stack full? " << (numStack.isFull() ? "Yes" : "No") << endl;

    numStack.push(40);
    numStack.push(50);

    numStack.push(60);

    numStack.pop();
    numStack.pop();

    cout << "Top element is: " << numStack.peek() << endl;

    return 0;
}