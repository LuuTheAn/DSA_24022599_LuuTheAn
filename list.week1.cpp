#include <iostream>
using namespace std;

// Node trong danh sách liên kết đơn
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Lớp List
class List {
private:
    Node* head;

public:
    List() {
        head = nullptr;
    }

    // 1. Chèn vào đầu
    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // 2. Chèn vào cuối
    void insertBack(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 3. Chèn vào vị trí i (0-based)
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
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 4. Truy cập phần tử tại vị trí i
    int getAt(int index) {
        Node* temp = head;
        for (int i = 0; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            throw out_of_range("Index không hợp lệ!");
        }
        return temp->data;
    }

    // 5. Xóa phần tử đầu
    void removeFront() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 6. Xóa phần tử cuối
    void removeBack() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // 7. Xóa tại vị trí i
    void removeAt(int index) {
        if (index == 0) {
            removeFront();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Vị trí không hợp lệ!\n";
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // 8. Duyệt xuôi
    void traverseForward() {
        Node* temp = head;
        cout << "Duyệt xuôi: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 9. Duyệt ngược (dùng đệ quy)
    void traverseBackwardHelper(Node* node) {
        if (node == nullptr) return;
        traverseBackwardHelper(node->next);
        cout << node->data << " ";
    }
    void traverseBackward() {
        cout << "Duyệt ngược: ";
        traverseBackwardHelper(head);
        cout << endl;
    }
};

int main() {
    List lst;

    lst.insertFront(10);   // [10]
    lst.insertBack(20);    // [10, 20]
    lst.insertAt(1, 15);   // [10, 15, 20]

    cout << "Phần tử tại vị trí 1: " << lst.getAt(1) << endl;

    lst.removeFront();     // [15, 20]
    lst.removeBack();      // [15]
    lst.insertBack(25);
    lst.insertBack(30);    // [15, 25, 30]
    lst.removeAt(1);       // [15, 30]

    lst.traverseForward();  // Duyệt xuôi
    lst.traverseBackward(); // Duyệt ngược

    return 0;
}
