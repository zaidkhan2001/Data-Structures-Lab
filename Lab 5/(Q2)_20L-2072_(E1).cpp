#include <iostream>
using namespace std;

class queue {
private:
	int size;
	int total;
	int front;
	int rear;
	int* list;
public:
	//Default Constructor
	queue(int sz) {

		list = new int[sz];
		this->size = sz;
		this->total = 0;
		this->rear = 0;
		this->front = 0;
	}

	//List Full 
	bool isFull(){
		return this->total == size;
	}

	//List Empty
	bool isEmpty(){
		return this->total == 0;
	}

	//Inserting Data In List At Start
	void enque(int data){

		//Data less than 0
		if (data < 0) {
			cout << "Negative Number Insertion Not Allowed" << endl;
			return;
		}

		//Queue is Full
		if (isFull()==true){
			cout << "Queue is full" << endl;
			return;
		}

		//Inserting Data
		else{
			list[rear] = data;
			rear = (rear + 1) % size;
			total++;
			return;
		}
	}

	//Deleting Last Element
	void deque(){

		if (isEmpty()){
			cout << "Deletion Not Performed Queue is Empty" << endl;
			return;
		}

		else{
			int value = this->list[front];
			front = (front + 1) % size;
			total--;
			cout << "Value " <<" Deleted From List : " << endl;
			return;
		}
	}

	//Length of List
	void getLength() {
		cout << "Total Elements in Queue are : " << total << endl << endl;
	}

	//Finding Last Element of List
	void getRear() {
		cout << "Finding Last Element of List." << endl <<  "Time :  " << list[rear] << endl;
	}

	//Total Size of the Queue
	void getSize() {
		cout << "Size of the Queue: " << size << endl;
	}

	//Getting Min from List
	void getMin() {
		int min = list[front];
		int i = 0;

		while (i < this->total) {

			if (list[i] < min) {
				min = list[i];
			}
			i++;
		}
		cout << "Minimum Time : " << min << endl;
	}

	//Getting Max from List
	void getMax() {
		int max = list[front];
		int i = 0;

		while (i < this->total) {

			if (list[i] > max) {
				max = list[i];
			}
			i++;
		}
		cout << "Maximum Time : " << max << endl;
	}

	//Print Function
	void show() {
		cout << "Time : ";
		for (int i = front, j = 0; j < total; i = (i + 1) % size, j++){
			cout << list[i] << " , ";
		}
		cout << endl << endl;
	}

	//Resize List
	void resize(int sz) {
		int* temp = new int[size];
		
		for (int i=0; i < size; i++) {
			temp[i] = list[i];
		}

		if (sz > size) {
			list = new int[sz];
		}
		
		else {
			cout << "Resize Not Possible" << endl;
		}

		for (int i = 2 , j=0 ; i < sz , j<size; i++,j++) {
			this->list[i] = temp[j];
		}

		this->size = sz;
		this->rear = 0;
		this->front = 0;
	}

	//Total Similiar Elements of a specific data
	void getSimilar(int data) {
		int counter = 0;
		
		for (int i = 0; i < this->total;i++) {
			if (list[i] == data) {
				counter++;
			}
		}
		cout << "Elements with Similar Time " << data << " are : " << counter << endl;
	}

	//Destructor
	~queue(){
		delete[] list;
		list = nullptr;
	}

};

int main() {
	int size = 5;
	queue q(size);

	q.enque(2);
	q.enque(1);
	q.enque(8);
	q.enque(56);
	q.enque(73);
	q.enque(12);
	q.show();

	q.deque();
	q.enque(65);

	cout << endl;
	q.show();

	q.getMax();
	q.getMin();

	cout << endl;
	q.getRear();

	cout << endl;
	q.getLength();

	q.resize(7);
	q.enque(22);
	q.enque(11);
	cout << endl << "Array Resized to 7 Elements " << endl;
	q.show();
	q.getLength();

	system("pause");
	return 0;
}