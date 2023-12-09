#include<iostream>
using namespace std;

template<typename T>
struct Node{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template<typename T>
class Doublylist{
	Node<T>* head;
	Node<T>* tail;
	int total;
public:
	Doublylist(){
		this->head=nullptr;
		this->tail=nullptr;
		this->total=0;
	}

	bool isEmpty(){
		return !this->head;
	}

	void InsertAtHead(const T element){

		//List is Empty
		if(isEmpty()==1){
			Node<T>* new_node = new Node<T>();
			new_node->data=element;
			new_node->next=nullptr;
			new_node->prev=nullptr;
			this->head=this->tail=new_node;
			total++;
			return;
		}

		//List Contains Some Elements
		else{
			Node<T>* new_node = new Node<T>();
			new_node->data=element;
			new_node->next=this->head;
			new_node->prev=nullptr;
			this->head->prev=new_node;
			this->head=new_node;
			total++;
			return;
		}
	}

	void InsertAtTail (const  T element){

		//List is Empty
		if(isEmpty()==1){
			Node<T>* new_node = new Node<T>();
			new_node->data=element;
			new_node->next=nullptr;
			new_node->prev=nullptr;
			this->head=this->tail=new_node;
			total++;
			return;
		}

		//List Contains Some Elements
		else{
			Node<T>* new_node = new Node<T>();
			new_node->data=element;
			new_node->prev=tail;
			new_node->next=nullptr;
			this->tail->next=new_node;
			tail=new_node;
			total++;
			return;
		}
	}

	void delete_from_tail(){
		//Linked List is Empty
		if(isEmpty()==1){
			return;
		}

		//List contains only 1 Element
		if(this->head==this->tail){
			delete head;
			this->head=nullptr;
			this->tail=nullptr;
			total--;
			return;
		}

		//List Contains More than 1 Element
		else{
			Node<T>* del_node =tail;
			tail=tail->previous;
			tail->next=nullptr;
			delete del_node;
		}
	}

	void InsertBefore(T element1, T element2){
		
		//List is Empty
		if(isEmpty()==1){
			cout<<"Linked List is Empty" <<endl;
		}

		//Placing at Head
		if(this->head->data == element2){
			InsertAtHead(element1);
		}

		else{	
			Node<T>* curr = this->head;
			
			//Storing 1 Previous Pointer
			while(curr->next != nullptr && curr ->next -> data != element2){
				curr=curr->next;
			}

			if(curr->next == nullptr){
				cout<<"Element " << element2 << " not found in the Provided List "<<endl;
			}
			
			else{
		     	Node<T>* newnode = new Node<T>;
		    	newnode->data = element1;
		    	newnode->next = curr->next;
			    curr->next = newnode;
		    	newnode->prev = curr;
			}
		}
	}

	void DeleteAllOccurances( T element){
		//List is Empty
		if (isEmpty()==1){
			return;
		}
	
		//Data is Present at the Start of Head
		if (this->head->data==element){
			Node<T>* del_node = this->head;
			this->head = this->head->next;
			this->head->prev = nullptr;
			delete del_node;

			//Will Work only if we have 1 Element
			if (this->head == nullptr){ 	
				this->tail = nullptr;
				return;
			}
		}

		//If the Same Element is Present at other Locations of List
		Node<T>* curr = this->head;
		while (curr->next != nullptr){

			//Required Data Found
			if (curr->next->data == element){
				Node<T>* del_node = curr->next;
				curr->next = curr->next->next;

				//Joining the Gap of Linked List
				if(curr->next != nullptr && curr->next->next != nullptr){
				curr->next->next->prev = curr->next;
				}
				
				delete del_node;
				
				if (curr->next == nullptr){
					this->tail = curr;
				}
			}
			//Data not Found Traverse Foward
			else curr = curr->next;
		}
	}

	void Print(){

		//If List is Empty
		if(isEmpty()==1){
			cout << "Linked List is Empty" << endl;
		}

		//List Contains Some Elements
		else{
		Node<T>* ptr=this->head;
		while(ptr!=nullptr){
			cout << ptr->data << " " ;
			ptr=ptr->next;
		}
		cout << endl;
		}
	}
};

int main(){

	Doublylist<int> d1;
	d1.InsertAtHead(10);
	d1.InsertAtHead(20);
	d1.InsertAtTail(30);
	d1.InsertAtTail(40);
	d1.InsertAtTail(20);
	d1.Print();
	d1.DeleteAllOccurances(20);
	d1.Print();
	d1.InsertBefore(50,30);
	d1.Print();

	system("pause");
	return 0;
}
