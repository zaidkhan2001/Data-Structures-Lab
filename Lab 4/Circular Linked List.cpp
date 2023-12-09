#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
};

template <typename T>
class CircularLinkList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int totalElements;
public:
    
    //Default Constructor
    CircularLinkList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->totalElements = 0;
    }
    
    //If List is Empty
    bool isEmpty() const {
        return !this->head;
    }
    
    //Insert Node at Head
    void insertAtHead(T data) {
        //If list is Empty
        if (isEmpty()) {
            this->head = this->tail = new Node<T>();
            this->head->data = data;
            this->head->next = this->head;
            totalElements++;
        }
        //List contains some Elements
        else {
            Node<T>* newNode = new Node<T>;
            newNode->data = data;
            newNode->next = this->head;
            this->head = newNode;
            this->tail->next = this->head;
            totalElements++;
        }
    }

    //Insert Node at Tail
    void insertAtTail(T data) {
        //If List is Empty
        if (this->isEmpty()) {
            Node<T>* newNode = new Node<T>;
            newNode->data = data;
            this->head = this->tail = newNode;
            this->tail->next = this->head;
            totalElements++;
        }
        //List Contains some elements
        else {
            Node<T>* newNode = new Node<T>();
            newNode->data = data;
            this->tail->next = newNode;
            this->tail = this->tail->next;
            this->tail->next = this->head;
        }
    }
    //Delete Provided Data Node 
    void delete_(T data) {
        //List is Empty
        if (this->isEmpty())
            return;

        Node<T>* delNode = this->head;
        Node<T>* prevNode = nullptr;

        //Storing 1 Previous Pointer
        while (delNode!=nullptr) {
            if (delNode->data == data) {
                break;
            }
            prevNode = delNode;
            delNode = delNode->next;
        }

        //If we are going to Delete from Head
        if (delNode == this->head) {
            return this->deleteFromHead();
        }

        //If we are going to Delete from Tail
        if (delNode == this->tail) {
            return this->deleteFromTail();
        }

        //Data neither at Tail nor Head
        prevNode->next = delNode->next;
        delete delNode;
        this->totalElements--;
        return;
    }

    //Delete From Head
    void deleteFromHead() {

        //List is Empty
        if (this->isEmpty()) {
            return;
        }

        //List Contains 1 Element
        if (this->head == this->tail) {
            delete this->head;
            this->head = this->tail = nullptr;
            this->totalElements--;
            return;
        }

        Node<T>* delNode = this->head;
        this->head = this->head->next;
        delete delNode;
        this->tail->next = this->head;
        this->totalElements--;
    }

    //Delete From Tail
    void deleteFromTail() {
        //List is Empty
        if (this->isEmpty())
            return;

        //List contains 1 Element
        if (this->head == this->tail) {
            delete this->head;
            this->head = this->tail = nullptr;
            this->totalElements--;
        }

        else {
            Node<T>* curr = this->head;
            while (curr->next != this->tail){
                curr = curr->next;
            }

            delete this->tail;
            this->tail = curr;
            this->tail->next = this->head;
            this->totalElements--;
        }
    }

    //Print Data
    void Print() {
        Node<T>* tmp = this->head;

        while (tmp != tail){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        if (tmp)
            cout << tmp->data << " ";
        cout << endl;
    }

    //Destructor
    ~CircularLinkList() {
        Node<T>* ptr;
        this->tail->next = nullptr;
        while (this->head) {
            ptr = this->head->next;
            delete this->head;
            this->head = ptr;
        }
    }
};

int main() {

    CircularLinkList<int> l1;
    l1.insertAtHead(10);
    l1.insertAtHead(20);
    l1.insertAtHead(30);
    l1.insertAtTail(60);
    l1.insertAtTail(50);
    l1.Print();
    l1.delete_(10);
    l1.Print();
    l1.delete_(30);
    l1.Print();
    l1.delete_(50);
    l1.Print();
}