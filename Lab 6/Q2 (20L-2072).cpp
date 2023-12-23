#include <iostream>
using namespace std;

template <typename T>
struct Node{
	T data;
	Node* next;
};

template <typename T> 
class Stack{
private:
	Node<T>* top;
	int total_elements;
public:
	//Default Constructor
	Stack(){
		total_elements=0;
		top=nullptr;
	}

	//Return Size of Stack
	int size(){
		return total_elements;
	}

	//List is Empty
	bool isEmpty(){
		return top==nullptr;
	}

	//Top Element Check
	bool topp(T& data){
		if(isEmpty()){
			cout << "Stack is Empty" << endl;
			return false;
		}
		else{
			data=top->data;
			return true;
		}
	}

	//Pop Element from Stack
	T pop(){
		if(total_elements==0){
			cout << "Stack is Empty" << endl;
			return 0;
		}

		if(top->next==nullptr){
			T tmp;
			tmp=top->data;
			delete top;
			top=nullptr;
			total_elements--;
			return tmp;
		}


			T tmp;
			tmp=top->data;
			Node<T>* deletenode=top;
			top=top->next;
			delete deletenode;
			total_elements--;
			return tmp;
		
	}

	//Push Elementy in Stack
	void push(T dat){
		if(total_elements==0){
			Node<T>* newnode=new Node<T>();
			newnode->data=dat;
			newnode->next=nullptr;
			top=newnode;
			total_elements++;
		}
		else{
			Node<T>* newnode=new Node<T>();
			newnode->data=dat;
			newnode->next=top;
			top=newnode;
			total_elements++;
		}
	}

	void Print(){
		cout << "Printing Elements In Stack" << endl;
		Node<T>* temp=new Node<T>();
		temp=top;
		while(temp!=nullptr){
			cout << temp->data << " ";
			temp=temp->next;
		}
		cout << endl;
	}

};

int main(){

	Stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.push(5);
	stk.push(6);

	cout<<"Total Elements Pushed in Stack : "<<stk.size()<< endl << endl;

	stk.Print();

	cout << endl << "Popping First 2 Elements From Stack" << endl << endl;
	stk.pop();
	stk.pop();
	
	stk.Print();

	system("pause");
	return 0;
}