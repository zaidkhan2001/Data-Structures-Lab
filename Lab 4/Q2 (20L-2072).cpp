#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T>
class Singly_Circular_LinkList{
private:
    Node<T>* head;
    Node<T>* tail;
    int total;
public:
    
    //Default Constructor
    Singly_Circular_LinkList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->total = 0;
    }
    
    //If List is Empty
    bool isEmpty() const {
        return !this->head;
    }
    
    //Insert Node at Head
    void InsertAtHead(T element) {
        //If list is Empty
        if (isEmpty()) {
            this->head = this->tail = new Node<T>();
            this->head->data = element;
            this->head->next = this->head;
            total++;
        }
        //List contains some Elements
        else {
            Node<T>* newNode = new Node<T>;
            newNode->data = element;
            newNode->next = this->head;
            this->head = newNode;
            this->tail->next = this->head;
            total++;
        }
    }

    //Delete all Similar Elements
    void DeleteAllOccurances( T element){
		
		//List is Empty
		if (isEmpty()==1){
			return;
		}
	
		//Element Present at Head
		if(this->head->data == element){
			Node<T>* del_node = this->head;
			this->head = this->head->next;
			this->tail->next = this->head;
			delete del_node;
			
			if (this->head == nullptr){ 	
				this->tail = nullptr;
				return;
			}
		}

		Node<T>* curr = this->head;

		while (curr->next != this->tail->next){

			//Required Data Found
			if (curr->next->data == element){
				Node<T>* del_node = curr->next;
				
				//Joining Linked List
				if(curr->next == this->tail){
					curr->next = curr->next->next;
					this->tail = curr;
				}
				else curr->next = curr->next->next;
				delete del_node;
				
				if (curr->next == nullptr){
					this->tail = curr;
				}
			}
			//Data not Found
			else curr = curr->next;
		}
	}

    //Delete From Head
    void DeleteAtHead() {

        //List is Empty
        if (this->isEmpty()) {
            return;
        }

        //List Contains 1 Element
        if (this->head == this->tail) {
            delete this->head;
            this->head = this->tail = nullptr;
            this->total--;
            return;
        }

        Node<T>* delNode = this->head;
        this->head = this->head->next;
        delete delNode;
        this->tail->next = this->head;
        this->total--;
    }

    //Delete From Tail
    void DeleteAtTail() {
        //List is Empty
        if (this->isEmpty())
            return;

        //List contains 1 Element
        if (this->head == this->tail) {
            delete this->head;
            this->head = this->tail = nullptr;
            this->total--;
        }

        else {
            Node<T>* curr = this->head;
            while (curr->next != this->tail){
                curr = curr->next;
            }

            delete this->tail;
            this->tail = curr;
            this->tail->next = this->head;
            this->total--;
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
    ~Singly_Circular_LinkList() {
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

    Singly_Circular_LinkList<int> l1;
    l1.InsertAtHead(30);
    l1.InsertAtHead(20);
	l1.InsertAtHead(20);
	l1.InsertAtHead(20);
	l1.InsertAtHead(20);
	l1.InsertAtHead(20);
	l1.DeleteAtHead();
    l1.Print();
	l1.DeleteAllOccurances(20);
	l1.Print();

	system("pause");
	return 0;
}