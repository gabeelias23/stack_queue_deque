#include <iostream>
using namespace std; 

class ArrayStack {
private: 
    // Array storage, top index, and maximum capacity
    int *arr;
    int top; 
    int capacity; 

public: 
    ArrayStack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1; 
    }

    bool isEmpty() { return top == -1;}

    bool isFull() { return top == capacity - 1;}
    
    // Push an element x onto the stack
    void push(int x) {
        if (isFull()){
            cout << "Array Stack Overflow.\n";
            return; 
        }

        // Increment top and add the element
        arr[++top] = x; 
    }

    // Remove and return element from top of the stack
    int pop(){
        if (isEmpty()) {
            cout << "Array Stack Underflow.\n";
            return -1;
        }

        // Decrement top and remove top element
        return arr[top--];
    }

    // Return the top element of the stack
    int peek(){
        if (!isEmpty()) {
            return arr[top];
        }
        else {
            cout << "Array stack is empty.\n";
            return -1;
        }     
    }

    void display() {
        if (isEmpty()) {
            cout << "Array stack is empty.\n";
            return;
        }

        // Print elements from top to bottom
        for (int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }

        cout << "\n";
    }
};

class StackNode {
public: 
    int data; 
    StackNode* next; 

    // Initializes the node with a value and a pointer to the next node
    StackNode(int dataValue, StackNode* nextNode) {
        data = dataValue; 
        next = nextNode; 
    }
};

class LinkedStack {
private: 
    StackNode* top; 
    
public:
    LinkedStack() {
        top = nullptr; 
    };

    bool isEmpty(){
        return top == nullptr; 
    }

    // Add a new node to the top of the stack
    void push(int value) {
        top = new StackNode(value, top);
    }

    // Removes and returns a value at the top of the stack 
    int pop(){

        if (isEmpty()){
            cout << "Linked list stack is empty.\n";
            return -1; 
        }

        // Get the data from the top node
        StackNode* poppedNode = top; 
        int poppedValue = poppedNode->data; 
        
        // Remove top node
        top = top->next; 

        // Delete previous top node
        delete poppedNode; 

        return poppedValue;
    }

    // Return the data of the top node without removing it
    int peek(){
        if (isEmpty()){
            cout << "Linked list stack is empty.\n";
            return -1; 
        }

        return top->data; 
    }  

    void display() {
        if (isEmpty()) {
            cout << "Linked list stack is empty.\n";
            return;
        }

        // Start at the top node
        StackNode* current = top; 

        // Print each node until the end of the stack
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << "\n";
    }
};

class ArrayQueue {
private: 
    // Pointer to the array holding the queue elements
    int *arr;
    // Index of the front element of the queue
    int front; 
    // Index of the rear element of the queue
    int rear; 
    // Max size of the queue
    int capacity; 

public: 
    ArrayQueue(int size) {
        arr = new int[size];
        capacity = size;
        front = -1; 
        rear = -1; 
    }

    bool isEmpty() {return front == -1 && rear == -1;}

    bool isFull() {return rear == capacity - 1;}

    void enqueue(int value) {
        if (isFull() ){
            cout << "Array Queue Overflow.\n";
            return; 
        }
        // Set front to zero if the queue is empty
        if(isEmpty()) {
            front = 0; 
            rear = 0; 
        }
        else {
            // Move rear to the next index
            rear++;
        }
        // Store the value at the rear of the queue
        arr[rear] = value; 
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Array Queue Underflow.\n";
            return -1; 
        }

        // Save the front element before removing it
        int item = arr[front];

        // Reset front and rear if the queue becomes empty
        if (front == rear) {
            front = -1; 
            rear = -1; 
        }
        else {
            // Move front to the next element in the queue
            front++; 
        }

        return item; 
    }

    void display() {
        if (isEmpty()) {
            cout << "Array queue is empty.\n";
            return;
        }

        // Print elements from front to rear
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";        
        }

        cout << "\n";
    }
};

class QueueNode {
public: 
    int data; 
    QueueNode* next; 

    QueueNode(int dataValue, QueueNode* nextNode) {
        data = dataValue; 
        next = nextNode; 
    }
};

class LinkedQueue {
private: 
    QueueNode* front; 
    QueueNode* end; 

public: 
    LinkedQueue() {
        front = nullptr; 
        end = nullptr; 
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        QueueNode* newNode = new QueueNode(value, nullptr);
        
        // Set front and end to the new node if the queue is empty
        if (isEmpty()) {
            front = newNode; 
            end = newNode; 
        }
        else {
            // Add the new node to the end of the queue
            end->next = newNode; 
            end = newNode; 
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Linked List Queue Underflow.\n";
            return -1; 
        }

        // Store the front node and its value
        QueueNode* dequeueNode = front; 
        int dequeueItem = front->data; 

        // Move the front to the next node
        front = front->next; 

        delete dequeueNode; 

        // Reset the end pointer if the queue is now empty
        if (isEmpty()) {
            end = nullptr; 
        }

        return dequeueItem; 
    }

    void display() {
        if (isEmpty()) {
            cout << "Linked list queue is empty.\n";
            return;
        }

        // Start at the front node
        QueueNode* current = front; 
        
        // Print each node until the end of the queue
        while(current != nullptr) {
            cout << current->data << " "; 
            current = current->next;
        }

        cout << "\n";
    }
};

class ArrayDeque {
private: 
    // Array storage, front/rear indices, capacity, and element count
    int *arr;
    int front; 
    int rear; 
    int capacity; 
    int count; 

public: 
    ArrayDeque(int size) {
        arr = new int[size];
        capacity = size;
        front = -1; 
        rear = -1; 
        count = 0; 
    }

    bool isEmpty() {return front == -1 && rear == -1;}

    bool isFull() {return count == capacity;}

    void enqueue(int value) {
        if (isFull() ){
            cout << "Array Deque Overflow.\n";
            return; 
        }
        // Initialize front and rear when inserting the first element
        if(isEmpty()) {
            front = 0; 
            rear = 0; 
        }
        else {
            // Move rear to the next index
            rear++;
        }
        // Store the value at the rear of the deque
        arr[rear] = value; 

        count++; 
    }

    void frontEnqueue(int value) {
        if (isFull()) {
            cout << "Array Deque Overflow.\n";
            return;
        }

        if (isEmpty()) {
            front = 0; 
            rear = 0; 
            arr[front] = value; 
        }
        
        
        else {
            // Shift elements to the right
            for (int i = rear + 1; i > front; i--) {
                arr[i] = arr[i - 1]; 
            }

            // Store the new value at the front
            arr[front] = value;

            // Update the rear index
            rear++; 
        }

        count++; 
        
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Empty Array Deque Front Removal.\n";
            return -1; 
        }

        // Save the front element before removing it
        int item = arr[front];

        // Reset front and rear if the deque becomes empty
        if (front == rear) {
            front = -1; 
            rear = -1; 
        }
        else {
            // Move front to the next element in the deque
            front++; 
        }

        count--; 
        return item; 
    }

    int endDequeue() {
        if (isEmpty()){
            cout << "Empty Array Deque Rear Removal.\n";
            return -1; 
        }

        // Save the rear element before removing it 
        int item = arr[rear];

        // Reset front and rear if only one element remains
        if (front == rear){
            front = -1; 
            rear = -1; 
        }
        else{
            // Move rear to the previous element
            rear--; 
        }
        
        count--; 

        return item; 
    }

    void display() {
        if (isEmpty()) {
            cout << "Array Deque is empty.\n";
            return;
        }

        // Print elements from front to rear
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";        
        }

        cout << "\n";
    }
};

class DequeNode {
public: 
    int data; 
    DequeNode* next; 

    DequeNode(int dataValue, DequeNode* nextNode) {
        data = dataValue; 
        next = nextNode; 
    }
};

class LinkedDeque {
private: 
    DequeNode* front; 
    DequeNode* end; 

public: 
    LinkedDeque() {
        front = nullptr; 
        end = nullptr; 
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        DequeNode* newNode = new DequeNode(value, nullptr);
        
        // Set front and end to the new node if the deque is empty
        if (isEmpty()) {
            front = newNode; 
            end = newNode; 
        }
        else {
            // Add the new node to the end of the deque
            end->next = newNode; 
            end = newNode; 
        }
    }

    void frontEnqueue (int value){
        DequeNode* newNode = new DequeNode(value, front);

        // Set end to the new node if the deque is empty 
        if (isEmpty()) {
            end = newNode; 
        }

        // Update front to point to the new node
        front = newNode;  
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Empty Linked List Deque Front Removal.\n";
            return -1; 
        }

        // Store the front node and its value
        DequeNode* dequeueNode = front; 
        int dequeueItem = front->data; 

        // Move the front to the next node
        front = front->next; 

        delete dequeueNode; 

        // Reset the end pointer if the deque is now empty
        if (isEmpty()) {
            end = nullptr; 
        }

        return dequeueItem; 
    }

    int endDequeue() {
        if (isEmpty()) { 
            cout << "Empty Linked List Deque Rear Removal.\n";
            return -1;
        }

        // If there is only one node 
        if (front == end){
            int dequeueItem = end->data; 

            delete end; 
            front = nullptr; 
            end = nullptr; 

            return dequeueItem; 
        }

        // Find the second last node 
        DequeNode* secondLast = front; 

        while (secondLast->next != end){
            secondLast = secondLast->next;
        }
        
        // Store the last item's value
        int item = end->data; 

        // Delete the last node
        delete end; 

        // Update end to the second last node
        end = secondLast; 
        end->next = nullptr; 

        return item; 
    }

    void display() {
        if (isEmpty()) {
            cout << "Linked list deque is empty.\n";
            return;
        }

        // Start at the front node
        DequeNode* current = front; 
        
        // Print each node until the end of the deque
        while(current != nullptr) {
            cout << current->data << " "; 
            current = current->next;
        }

        cout << "\n";
    }
};

int main() {

    cout << "\n=== Array Stack ===\n";

    ArrayStack ArrayStack(10);

    ArrayStack.push(10); // Operation 1
    ArrayStack.push(20); // Operation 2
    ArrayStack.push(30); // Operation 3

    cout << "Array Stack (top to bottom):\n";
    ArrayStack.display();

    cout << "Peek: " << ArrayStack.peek() << "\n"; // Extra operation

    ArrayStack.push(40);  // Operation 4
    ArrayStack.push(50);  // Operation 5
    ArrayStack.pop();     // Operation 6
    ArrayStack.pop();     // Operation 7
    ArrayStack.push(60);  // Operation 8
    ArrayStack.push(70);  // Operation 9
    ArrayStack.pop();     // Operation 10
    ArrayStack.pop();     // Operation 11

    cout << "Final Array Stack (top to bottom):\n";
    ArrayStack.display();
    
    while (!ArrayStack.isEmpty()) {
        ArrayStack.pop();
    }

    cout << "Testing Empty Stack:\n";
    ArrayStack.pop();

    cout << "\n=== Linked Stack ===\n";

    LinkedStack linkedStack;

    linkedStack.push(10);  // Operation 1
    linkedStack.push(20);  // Operation 2
    linkedStack.push(30);  // Operation 3

    cout << "Linked List Stack (top to bottom):\n";
    linkedStack.display();

    cout << "Peek: " << linkedStack.peek() << endl; // Extra operation

    linkedStack.push(40);  // Operation 4
    linkedStack.push(50);  // Operation 5
    linkedStack.pop();     // Operation 6
    linkedStack.pop();     // Operation 7
    linkedStack.push(60);  // Operation 8
    linkedStack.push(70);  // Operation 9
    linkedStack.pop();     // Operation 10
    linkedStack.pop();     // Operation 11

    cout << "Final Stack (top to bottom):\n";
    linkedStack.display();

    while (!linkedStack.isEmpty()) {
        linkedStack.pop();
    }

    cout << "Testing Empty Linked List Stack:\n";
    linkedStack.pop();

    cout << "\n=== Array Queue ===\n";

    ArrayQueue arrayQueue(10);

    arrayQueue.enqueue(10);  // Operation 1
    arrayQueue.enqueue(20);  // Operation 2
    arrayQueue.enqueue(30);  // Operation 3

    cout << "Array Queue (front to rear):\n";
    arrayQueue.display();

    arrayQueue.enqueue(40);  // Operation 4
    arrayQueue.enqueue(50);  // Operation 5
    arrayQueue.dequeue();    // Operation 6
    arrayQueue.dequeue();    // Operation 7
    arrayQueue.enqueue(60);  // Operation 8
    arrayQueue.enqueue(70);  // Operation 9
    arrayQueue.dequeue();    // Operation 10
    arrayQueue.dequeue();    // Operation 11

    cout << "Final Array Queue (front to rear):\n";
    arrayQueue.display();

    while (!arrayQueue.isEmpty()) {
        arrayQueue.dequeue();
    }

    cout << "Testing Empty Array Queue:\n";
    arrayQueue.dequeue();

    cout << "\n=== Linked List Queue ===\n";

    LinkedQueue linkedQueue;

    linkedQueue.enqueue(10);  // Operation 1
    linkedQueue.enqueue(20);  // Operation 2
    linkedQueue.enqueue(30);  // Operation 3

    cout << "Linked List Queue (front to rear):\n";
    linkedQueue.display();

    linkedQueue.enqueue(40);  // Operation 4
    linkedQueue.enqueue(50);  // Operation 5
    linkedQueue.dequeue();    // Operation 6
    linkedQueue.dequeue();    // Operation 7
    linkedQueue.enqueue(60);  // Operation 8
    linkedQueue.enqueue(70);  // Operation 9
    linkedQueue.dequeue();    // Operation 10
    linkedQueue.dequeue();    // Operation 11

    cout << "Final Linked List Queue (front to rear):\n";
    linkedQueue.display();

    while (!linkedQueue.isEmpty()) {
        linkedQueue.dequeue();
    }

    cout << "Testing Empty Queue:\n";
    linkedQueue.dequeue();

    cout << "\n=== Array Deque ===\n";

    ArrayDeque arrayDeque(10);

    arrayDeque.enqueue(10);       // Operation 1
    arrayDeque.enqueue(20);       // Operation 2
    arrayDeque.enqueue(30);       // Operation 3

    cout << "Array Deque (front to rear):\n";
    arrayDeque.display();

    arrayDeque.frontEnqueue(5);   // Operation 4
    arrayDeque.enqueue(40);       // Operation 5
    arrayDeque.dequeue();         // Operation 6
    arrayDeque.endDequeue();      // Operation 7
    arrayDeque.frontEnqueue(15);  // Operation 8
    arrayDeque.enqueue(50);       // Operation 9
    arrayDeque.dequeue();         // Operation 10
    arrayDeque.endDequeue();      // Operation 11

    cout << "Final Array Deque (front to rear):\n";
    arrayDeque.display();

    while (!arrayDeque.isEmpty()) {
        arrayDeque.dequeue();
    }

    cout << "Testing Empty Array Deque:\n";
    arrayDeque.dequeue();
    arrayDeque.endDequeue();

    cout << "\n=== Linked List Deque ===\n";

    LinkedDeque linkedDeque;

    linkedDeque.enqueue(10);       // Operation 1
    linkedDeque.enqueue(20);       // Operation 2
    linkedDeque.enqueue(30);       // Operation 3

    cout << "Linked List Deque (front to rear):\n";
    linkedDeque.display();

    linkedDeque.frontEnqueue(5);   // Operation 4
    linkedDeque.enqueue(40);       // Operation 5
    linkedDeque.dequeue();         // Operation 6
    linkedDeque.endDequeue();      // Operation 7
    linkedDeque.frontEnqueue(15);  // Operation 8
    linkedDeque.enqueue(50);       // Operation 9
    linkedDeque.dequeue();         // Operation 10
    linkedDeque.endDequeue();      // Operation 11

    cout << "Final Linked List Deque (front to rear):\n";
    linkedDeque.display();

    while (!linkedDeque.isEmpty()) {
        linkedDeque.dequeue();
    }

    cout << "Testing empty deque:\n";
    linkedDeque.dequeue();
    linkedDeque.endDequeue();

    return 0;
}