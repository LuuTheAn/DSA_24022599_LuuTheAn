#include <iostream>
#include <string>
using namespace std;

const int M = 100;

struct HashTable {
    string keys[M];
    string vals[M];
    int n = 0; // số cặp key-value hiện tại

    // Hàm băm
    int hash(string key) {
        unsigned long h = 0;
        for (char c : key)
            h = (h * 31 + c) % M;
        return h;
    }

    // thêm hoặc cập nhật
    void put(string key, string value) {
        if (n >= M - 1) {
            return;
        }

        int i = hash(key);
        while (!keys[i].empty()) {
            if (keys[i] == key) { // nếu key đã tồn tại thì cập nhật
                vals[i] = value;
                return;
            }
            i = (i + 1) % M; // dò tuyến tính
        }
        keys[i] = key;
        vals[i] = value;
        n++;
    }

    // tìm và trả về value
    string get(string key) {
        int i = hash(key);
        while (!keys[i].empty()) {
            if (keys[i] == key)
                return vals[i];
            i = (i + 1) % M;
        }
        return "null";
    }

    void print() {
        for (int i = 0; i < M; i++) {
            if (!keys[i].empty())
                cout << i << ": (" << keys[i] << ", " << vals[i] << ")\n";
        }
    }
};

int main() {

}
