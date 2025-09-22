#include <iostream>
using namespace std;

// Node trong danh sách liên kết đôi
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Lớp Linked List đôi
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // 1. Truy cập phần tử tại vị trí i
    int getAt(int index) {
        Node* temp = head;
        for (int i = 0; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) throw out_of_range("Index không hợp lệ!");
        return temp->data;
    }

    // 2. Chèn vào đầu
    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // 3. Chèn vào cuối
    void insertBack(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // 4. Chèn vào vị trí i
    void insertAt(int index, int value) {
        if (index == 0) {
            insertFront(value);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Vị trí không hợp lệ!\n";
            return;
        }
        if (temp->next == nullptr) { // chèn cuối
            insertBack(value);
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // 5. Xóa đầu
    void removeFront() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // 6. Xóa cuối
    void removeBack() {
        if (tail == nullptr) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // 7. Xóa tại vị trí i
    void removeAt(int index) {
        if (index == 0) {
            removeFront();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Vị trí không hợp lệ!\n";
            return;
        }
        if (temp == tail) {
            removeBack();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // 8. Duyệt xuôi
    void traverseForward() {
        cout << "Duyệt xuôi: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 9. Duyệt ngược
    void traverseBackward() {
        cout << "Duyệt ngược: ";
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

// ================== Demo ==================
int main() {
    DoublyLinkedList lst;

    lst.insertFront(10);   // [10]
    lst.insertBack(20);    // [10, 20]
    lst.insertAt(1, 15);   // [10, 15, 20]

    cout << "Phần tử tại vị trí 1: " << lst.getAt(1) << endl;

    lst.removeFront();     // [15, 20]
    lst.removeBack();      // [15]
    lst.insertBack(25);
    lst.insertBack(30);    // [15, 25, 30]
    lst.removeAt(1);       // [15, 30]

    lst.traverseForward();   // Duyệt xuôi
    lst.traverseBackward();  // Duyệt ngược

    return 0;
}
