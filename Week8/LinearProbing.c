
#include <iostream>
#include <string>
using namespace std;

const int M = 10; // số lượng chuỗi băm

struct Node {
    string key;
    string value;
    Node* next;
    Node(string k, string v) : key(k), value(v), next(nullptr) {}
};

struct HashTable {
    Node* table[M];

    HashTable() {
        for (int i = 0; i < M; i++) table[i] = nullptr;
    }

    // Hàm băm
    int hash(string key) {
        int h = 0;
        for (char c : key) h = (h * 31 + c) % M;
        return h;
    }

    // Tìm giá trị theo key
    string get(string key) {
        int i = hash(key);
        Node* p = table[i];
        while (p) {
            if (p->key == key) return p->value;
            p = p->next;
        }
        return "null";
    }

    // Chèn hoặc cập nhật (put)
    void put(string key, string value) {
        int i = hash(key);
        Node* p = table[i];

        // Nếu key đã tồn tại thì cập nhật
        while (p) {
            if (p->key == key) {
                p->value = value;
                return;
            }
            p = p->next;
        }

        // Nếu chưa có thì chèn vào đầu danh sách
        Node* newNode = new Node(key, value);
        newNode->next = table[i];
        table[i] = newNode;
    }

    void print() {
        for (int i = 0; i < M; i++) {
            cout << "[" << i << "]: ";
            Node* p = table[i];
            while (p) {
                cout << "(" << p->key << "," << p->value << ") ";
                p = p->next;
            }
            cout << "\n";
        }
    }
};

int main() {

}
