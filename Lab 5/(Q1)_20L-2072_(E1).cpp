#include<iostream>
using namespace std;

struct Node {
	int prid;
	int exe_time;
	Node* next;
};

class queue {
private:
	int total;
	Node* front;
	Node* rear;
public:
	queue() {
		this->total = 0;
		this->front = nullptr;
		this->rear = nullptr;
	}

	void enqueue(int data) {
		if (data < 0) {
			cout << "Negative Process ID cannot be entered" << endl;
		}

		if (duplicate_check(data) == false) {
			cout << "The Process ID already exists" << endl;
		}

		else {
			int tmp = 0;
			cout << "Enter the time for Processing" << endl;
			cin >> tmp;

			Node* newnode = new Node();
			newnode->exe_time = tmp;
			newnode->prid = data;
			this->total++;

			if (!front) {
				newnode->next = nullptr;
				front = rear = newnode;
			}

			else {
				rear->next = newnode;
				newnode->next = nullptr;
				rear = rear->next;
			}
		}
	}

	void denque() {
		if (!front) {
			cout << "The Queue is Empty" << endl;
		}

		else {
			cout << endl << "Deleting ID " << this->front->prid << endl;
			cout << "Deleting this ID execution time " << this->front->exe_time << endl;
			Node* del_node = this->front;
			front = front->next;
			delete del_node;
			total--;
			return;
		}

	}

	bool duplicate_check(int data) {
		Node* temp = this->front;
		while (temp != nullptr) {
			if (temp->prid == data) {
				return false;
			}
			temp = temp->next;
		}
		return true;
	}

	void Show() {
		cout << endl << "Printing the whole Queue" << endl;
		Node* temp = this->front;
		while (temp != nullptr) {
			cout << "Process ID is  : " << temp->prid << " & Execution Time is  : " << temp->exe_time << endl;
			temp = temp->next;
		}
	}

	int get_length() {
		cout << "Total Number of Elements in List are" << this->total;
	}

	bool isEmpty() {
		return this->total == 0;
	}

	void getCountofSimilar(int data) {
		int count = 0;
		Node* temp = new Node();
		temp = this->front;
		while (temp != nullptr) {
			if (temp->exe_time == data) {
				count++;
			}
			temp = temp->next;
		}
		cout << endl << "There are " << count << " with same processing time of " << data << endl;
	}

	void getRear() {
		Node* temp = new Node();
		temp = this->rear;
		if (temp == nullptr) {
			cout << "List is Empty" << endl;
		}
		else {
			cout << "Process ID is  : " << temp->prid << " & Execution Time is  : " << temp->exe_time << endl;
		}
	}

	void getMin() {
		int min = this->front->prid;
		Node* temp = this->front;
		while (temp != nullptr) {
			if (temp->exe_time < min) {
				min = temp->prid;
			}
			temp = temp->next;
		}
		cout << endl << "Min time ID: " << min << endl;
	}

	void getMax() {
		int max = this->front->prid;
		Node* temp = this->front;
		while (temp->next != nullptr) {
			if (temp->exe_time > max) {
				max = temp->prid;
			}
			temp = temp->next;
		}
		cout <<endl <<  "Max time ID: " << max << endl;
	}

};

int main() {

	queue q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.Show();

	q1.denque();
	q1.Show();

	q1.getMax();
	q1.getMin();
	q1.getCountofSimilar(111);

	system("pause");
	return 0;
}