#include<iostream>
using namespace std;
#define CAP 10

template <typename T>
class Stack{
private:
	T *arr;
	int top;
	int size;
	int total_elements;
public:
	//Default Constructor
	Stack(){
		top=-1;
		total_elements=0;
		size=10;
		arr=new T[size];
	}

	//Stack is Full
	bool isFull(){
		return top==(CAP-1);
	}

	//Stack is Empty
	bool isEmpty(){
		return top==-1;
	}

	//Total Elements in Stack
	int getCount(){
		return total_elements;
	}

	int getCapacity(){
		return size;
	}

	//Getting Top Most Element
	bool topp(T& data){

		if (isEmpty()){
			cout<<"The Stack is Empty"<<endl;
			return false;
		}
		else{
			data=arr[top];
			return true;
		}
	}

	//Take out Top most Element 
	bool pop(){
		if (isEmpty()){
			cout<<"The Stack is Empty"<<endl;
			return false;
		}
		else{
			total_elements--;
			arr[top--];
			return true;
		}
	}

	//Resize the Stack
	void Resize(){
		T *arr2=new int[size*2];
			for(int i=0;i<size;i++)
				arr2[i]=arr[i];
			delete [] arr;
			arr=arr2;
			arr2=nullptr;
			size=size*2;
	}

	//Push Data in Stack
	void push(T data){
		if (isFull()){
			cout<<"The Stack is full" << endl;
			cout << "Resizing the Stack. Capacity*2 "<<endl;
			Resize();
		}
				arr[++top] = data;
			total_elements++;
	}

	//Printing Data from Stack
	void Print(){
		cout << endl << "Printing The Stack" << endl;
		for (int i=top;i>=0;i--){
		cout << arr[i] << " ";
	}
		cout << endl;
	}

};

int main(){
	
	Stack<int> stk;

	stk.push(11);
	stk.push(10);
	stk.push(9);
	stk.push(8);
	stk.push(7);
	stk.push(6);
	stk.push(5);
	stk.push(4);
	stk.push(3);
	stk.push(2);
	stk.push(1);

	stk.Print();

	stk.pop();
	stk.pop();
	stk.pop();

	cout << endl << "Popping First 3 Elements of Stack" << endl;
	stk.Print();

	system("pause");
	return 0;
}