#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int arr[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int value) {

        if (size == 100) {
            cout << "Priority Queue is full\n";
            return;
        }

        int i = size - 1;

        while (i >= 0 && arr[i] < value) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = value;
        size++;
    }

    int peek() {
        if (size == 0) {
            cout << "Priority Queue is empty\n";
            return -1;
        }

        return arr[0];
    }

    void remove() {

        if (size == 0) {
            cout << "Priority Queue is empty\n";
            return;
        }

        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;

      }


    void display() {

        if (size == 0) {
            cout << "Priority Queue is empty\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    PriorityQueue pq;

    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(20);
    pq.insert(40);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Highest Priority: " << pq.peek() << endl;

    pq.remove();

    cout << "After removing highest priority: ";
    pq.display();

    return 0;
}