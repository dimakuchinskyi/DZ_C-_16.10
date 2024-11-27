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

    void printQueue()
    {
        if (isEmpty()) {
            return;
        }

        Node* current = head;
        cout << "Queue: ";

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << std::endl;
    }



    int getSize() const {
        return size;
    }

    ~Queue() {
        while (!isEmpty()) {
            deleteFirstElementFromQueue();
        }
    }
};

int main() {
    Queue queue;

    queue.AddToEndQueue(10);
    queue.AddToEndQueue(20);
    queue.AddToEndQueue(30);

    queue.printQueue();

    queue.deleteFirstElementFromQueue();
    queue.printQueue();

    queue.deleteFirstElementFromQueue();
    queue.printQueue();

    queue.deleteFirstElementFromQueue();
    queue.printQueue();

    return 0;
}