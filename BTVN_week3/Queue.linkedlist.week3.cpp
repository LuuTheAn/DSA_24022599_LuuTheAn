#include "SinglyLinkedList.week1.cpp"
struct QueueLinkedList {

    LinkedList list;

    /**
     * Constructor.
     */
    QueueLinkedList() : list() {};

    /**
     * Kiểm tra xem Queue có rỗng không.
     *
     * @return true nếu rỗng, false nếu không rỗng
     */
    bool isEmpty() {
        return list.isEmpty();
    }

    /**
     * Thêm giá trị vào cuối queue. (Độ phức tạp: O(1))
     *
     * @param item giá trị cần thêm
     */
    void enqueue(int item) {
        list.addLast(item);
        cout << "enqueue(" << item << "): OK" << endl;
    }

    /**
     * Xóa giá trị ở đầu queue. (Độ phức tạp: O(1))
     *
     * @return giá trị vừa xóa
     */
    int dequeue() {
        cout << "dequeue(): ";
        if (list.isEmpty()) {
            cout << "FAILED - The queue is empty!" << endl;
            return -1;
        }
        cout << list.getHead() << " - OK" << endl;
        return list.deleteFirst();
    }

    /**
     * Kiểm tra kích cỡ của queue.
     *
     * @return kích cỡ của queue
     */
    int size() {
        cout << "Current size: " << list.getSize() << endl;
        return list.getSize();
    }

    /**
     * Xuất ra giá trị đang ở đầu queue.
     *
     * @return giá trị đầu queue
     */
    int peek() {
        cout << "peek(): " << list.getHead() << " - OK" << endl;
        return list.getHead();
    }

};




// ===== TEST FUNCTION =====
int main() {
    cout << "\n=== Test QueueLinkedList ===" << endl;
    QueueLinkedList ql;
    ql.enqueue(100);
    ql.enqueue(200);
    ql.enqueue(300);
    ql.peek();
    ql.dequeue();
    ql.dequeue();
    ql.size();
    ql.dequeue();
    ql.dequeue(); // empty case

    return 0;
}
