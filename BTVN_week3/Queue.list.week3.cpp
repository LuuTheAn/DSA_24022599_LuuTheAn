#include "list.week1.cpp"
#include "SinglyLinkedList.week1.cpp"

struct QueueList {

    List list;

    /**
     * Constructor.
     */
    QueueList(int cap) : list(cap) {}

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
        cout << "enqueue(" << item << "): ";
        if (list.isFull()) {
            cout << "FAILED - The queue is full!" << endl;
        } else {
            list.addLast(item);
        }
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
        cout << list.data[0] << " - OK" << endl;
        return list.deleteFirst();
    }

    /**
     * Kiểm tra kích cỡ của queue.
     *
     * @return kích cỡ của queue
     */
    int size() {
        cout << "Current size: " << list.getCount() << endl;
        return list.getCount();
    }

    /**
     * Xuất ra giá trị đang ở đầu queue.
     *
     * @return giá trị đầu queue
     */
    int peek() {
        cout << "peek(): ";
        if (list.isEmpty()) {
            cout << "FAILED - The queue is empty!" << endl;
            return -1;
        }
        cout << list.data[0] << " - OK" << endl;
        return list.getFirst();
    }
};







// ===== TEST FUNCTION =====
int main() {
    cout << "=== Test QueueList ===" << endl;
    QueueList qa(5);
    qa.enqueue(10);
    qa.enqueue(20);
    qa.enqueue(30);
    qa.peek();
    qa.dequeue();
    qa.dequeue();
    qa.size();
    qa.dequeue();
    qa.dequeue(); // empty case
}
