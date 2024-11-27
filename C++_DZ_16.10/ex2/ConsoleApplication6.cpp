#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class Queue {
private:
    Node* head;
    Node* tail;
    int size;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void AddToEndQueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    int deleteFirstElementFromQueue() {
        if (isEmpty()) {
            return -1;
        }

        Node* temp = head;
        int value = temp->data;

        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

        delete temp;
        size--;
        return value;
    }

    void printQueue() const {
        if (isEmpty()) {
            return;
        }

        Node* current = head;
        cout << "Queue: ";

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int getSize() const {
        return size;
    }

    Queue clone() const {
        Queue clonedQueue;
        Node* current = head;
        while (current != nullptr) {
            clonedQueue.AddToEndQueue(current->data);
            current = current->next;
        }
        return clonedQueue;
    }

    Queue operator+(const Queue& other) const {
        Queue mergedQueue = this->clone();

        Node* current = other.head;
        while (current != nullptr) {
            mergedQueue.AddToEndQueue(current->data);
            current = current->next;
        }
        return mergedQueue;
    }

    Queue operator*(const Queue& other) const {
        Queue intersectedQueue;
        Node* current = head;

        while (current != nullptr) {
            Node* temp = other.head;
            while (temp != nullptr) {
                if (current->data == temp->data) {
                    intersectedQueue.AddToEndQueue(current->data);
                    break;
                }
                temp = temp->next;
            }
            current = current->next;
        }

        return intersectedQueue; 
    }

    ~Queue() {
        while (!isEmpty()) {
            deleteFirstElementFromQueue();
        }
    }
};

int main() {
    Queue queue1;
    queue1.AddToEndQueue(10);
    queue1.AddToEndQueue(20);
    queue1.AddToEndQueue(30);

    Queue queue2;
    queue2.AddToEndQueue(20);
    queue2.AddToEndQueue(30);
    queue2.AddToEndQueue(40);

    cout << "Queue 1: ";
    queue1.printQueue();

    cout << "Queue 2: ";
    queue2.printQueue();

    Queue clonedQueue = queue1.clone();
    cout << "Cloned Queue from Queue 1: ";
    clonedQueue.printQueue();

    Queue mergedQueue = queue1 + queue2;
    cout << "Merged Queue (Queue 1 + Queue 2): ";
    mergedQueue.printQueue();

    Queue commonQueue = queue1 * queue2;
    cout << "Common elements (Queue 1 * Queue 2): ";
    commonQueue.printQueue();

    return 0;
}
