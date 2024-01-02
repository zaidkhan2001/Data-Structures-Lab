#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

static int total;

class LinkList{
private:
	Node* head;
	int totalElements;
public:
	Node* GetHead(){
		return this->head;
	}

	LinkList(){
		this->head = nullptr;
		this->totalElements = 0;
	}

	void insert(int data){
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		totalElements++;
	}

	void recursiveprint(Node* temp){
		if(temp==nullptr){
			return;
		}
		else{
			cout << temp->data << " , ";
			return recursiveprint(temp->next);
		}
	}

	static int length(Node* temp){
		if(temp==nullptr){
			return total;
		}
		else{
			total++;
			return length(temp->next);
		}
	}

	bool isSorted(Node* temp){
		if(temp==nullptr || temp->next ==nullptr){
			return true;
		}
		else{
			return temp->data > temp->next->data && isSorted(temp->next);
		}
	}

	void DeleteAll(Node* temp){
		if (temp==nullptr){
			return;
		}
		else{
			Node* delete_node=temp;
			temp=temp->next;
			delete delete_node;
			cout << "Element Deleted " << endl;
			return DeleteAll(temp);
		}
	}

	~LinkList(){
		Node* ptr = this->head;
		while (head){
			ptr = ptr->next;
			delete head;
			head = ptr;
		}
	}
};

int main(){
	LinkList list;

	list.insert(0);
	list.insert(300);
	list.insert(200);
	list.insert(100);

	list.recursiveprint(list.GetHead());
	cout << endl << endl;

	cout << "Length of Linked List is : " << list.length(list.GetHead()) << endl;
	cout << endl;

	if(list.isSorted(list.GetHead())==true){
		cout << "The Linked List is Sorted" << endl;
	}
	else{
		cout << "The Linked List is Not Sorted" << endl;
	}
	cout << endl;

	list.DeleteAll(list.GetHead());
	cout << endl;

	system("pause");
	return 0;
}