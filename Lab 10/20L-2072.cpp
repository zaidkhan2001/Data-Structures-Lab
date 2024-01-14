#include<iostream>
#include <assert.h>
using namespace std;

template <typename k, typename v>
struct HeapItem{
	k key;
	v value;
};

template <typename k, typename v>
class MinHeap{

public:
	
	HeapItem<k, v>* arr;
	int total;
	int capacity;

	//Double Capacity
	void doubleCapacity(){
		HeapItem<k, v>* newArr = new HeapItem<k, v>[this->capacity * 2];
		this->capacity *= 2;
		
		for (int i = 0; i < this->total; i++){
			newArr[i] = this->arr[i];
		}

		delete[]this->arr;
		this->arr = newArr;
	}

public:

	//Default Constructor
	MinHeap(){
		this->arr = new HeapItem<k, v>[1];
		this->total = 0;
		this->capacity = 1;
	}

	//Parameterised Constructor
	MinHeap(int _capacity){
		assert(_capacity > 0);
		this->arr = new HeapItem[_capacity];
		this->total = 0;
		this->capacity = _capacity;
	}

	//Insert An Element 
	void insert(k key, v value){
		if (this->total == this->capacity)
			this->doubleCapacity();

		arr[this->total].key = key;
		arr[this->total].value = value;

		shiftUp(this->total);
		this->total++;
	}

	//Shift Up The Index
	void shiftUp(int index){
		int parent = (index - 1) / 2;

		if (this->arr[index].key < this->arr[parent].key) {
			swap(this->arr[index], this->arr[parent]);
		}
		
		else {
			return;
		}
		
		if (parent > 0) {
			shiftUp(parent);
		}
	}

	//Delete Min Value
	void deleteMin(){
		if (this->total == 0) {
			return;
		}
		swap(this->arr[total - 1], this->arr[0]);
		this->total--;
		shiftDown(0);
	}

	//Shift Down Provided index
	void shiftDown(int index) {
		int lChild = index * 2 + 1;
		int rChild = index * 2 + 2;
		int min = index;

		if (lChild < this->total && this->arr[lChild].key < this->arr[min].key){
			min = lChild;
		}
		
		if (rChild < this->total && this->arr[rChild].key < this->arr[min].key) {
			min = rChild;
		}

		if (min == index) {
			return;
		}

		swap(this->arr[min], this->arr[index]);
		shiftDown(min);
	}

	//Get Total Element Count
	int getElementCount() const{
		return this->total;
	}

	//Get Capacity of Array
	int getCapacity() const{
		return this->capacity;
	}

	//Get Min Value
	void getMin(v& _value){
		assert(total > 0);
		_value = arr[0].value;
	}

	//Get Max
	void getMax(v& _value){
		assert(total > 0);
		_value = 0;
		int key = 0;

		for (int i = 0; i < total; i++){
			if (key < arr[i].key){
				key = arr[i].key;
				_value = arr[i].value;
			}
		}
	}

	//If Array is Empty
	bool isEmpty() {
		if (total == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//Get Total Element in Array
	int gettotal(){
		return total;
	}

	//Convert a Provided Array Into Heap Elements
	void heapify(k* arr, int size) {
		int startIndex = (size / 2) - 1;

		for (int i = startIndex; i >= 0; i--) {
			insert(i, arr[i]);
		}

	}

	//Shrink the Heap
	void shrinkHeap() {
		if (this->totalElements == (this->capacity / 4)) {
			HeapItem<k, v>* newArr2 = new HeapItem<k, v>[this->capacity / 2];
			this->capacity /= 2;
			for (int i = 0; i < this->totalElements; i++) {
				newArr2[i] = this->arr[i];
			}
			delete[]this->arr;
			this->arr = newArr2;
		}
	}

	//Delete Max Element 
	void deleteMax(){
		int index = 0;
		int key = arr[0].key;
		for (int i = 0; i < total; i++)
		{
			if (key < arr[i].key)
			{
				key = arr[i].key;
				index = i;
			}
		}
		swap(arr[index], arr[total - 1]);
		total--;
		shiftDown(index);
	}

	//Destructor
	~MinHeap(){
		delete[]this->arr;
	}
};

template <typename k, typename v>
class MaxHeap {

	HeapItem<k, v>* arr;
	int total;
	int capacity;

	//Double Capacity of Array
	void doubleCapacity() {
		HeapItem<k, v>* newArr = new HeapItem<k, v>[this->capacity * 2];
		this->capacity *= 2;
		for (int i = 0; i < this->total; i++)
		{
			newArr[i] = this->arr[i];
		}
		delete[]this->arr;
		this->arr = newArr;
	}

public:
	//Default Constructor
	MaxHeap() {
		this->arr = new HeapItem<k, v>[1];
		this->total = 0;
		this->capacity = 1;
	}

	//Parameterized Constructor
	MaxHeap(int _capacity) {
		assert(_capacity > 0);
		this->arr = new HeapItem[_capacity];
		this->total = 0;
		this->capacity = _capacity;
	}

	//Insert Eleemnt in Array
	void insert(k key, v value) {
		if (this->total == this->capacity)
			this->doubleCapacity();

		arr[this->total].key = key;
		arr[this->total].value = value;

		shiftUp(this->total);
		this->total++;
	}

	//Shift Up Provided Index
	void shiftUp(int index) {
		int parent = (index - 1) / 2;

		if (this->arr[index].key > this->arr[parent].key)
			swap(this->arr[index], this->arr[parent]);
		else return;

		if (parent > 0)
			shiftUp(parent);
	}

	//Delete the Max Key
	void deleteMax() {
		if (this->total == 0) {
			return;
		}
		swap(this->arr[total - 1], this->arr[0]);

		this->total--;
		shiftDown(0);
	}

	//Shift Down Provided Index
	void shiftDown(int i) {
		int lChild = i * 2 + 1;
		int rChild = i * 2 + 2;
		int min = i;

		if (lChild < this->total && this->arr[lChild].key > this->arr[min].key){
			min = lChild;
		}
		
		if (rChild < this->total && this->arr[rChild].key > this->arr[min].key){
		min = rChild;
		}
		
		if (min == i){
			return;
		}
		
		swap(this->arr[min], this->arr[i]);
		shiftDown(min);
	}


	//Convert a Provided Array Into Heap Elements
	void heapify(k* arr, int size) {
		int startIndex = (size / 2) - 1;

		for (int i = startIndex; i >= 0; i--) {
			insert(i, arr[i]);
		}

	}

	//Shrink the Heap
	void shrinkHeap() {
		if (this->totalElements == (this->capacity / 4)) {
			HeapItem<k, v>* newArr2 = new HeapItem<k, v>[this->capacity / 2];
			this->capacity /= 2;
			for (int i = 0; i < this->totalElements; i++) {
				newArr2[i] = this->arr[i];
			}
			delete[]this->arr;
			this->arr = newArr2;
		}
	}


	//Get Total Element Count
	int getElementCount() const{
		return this->total;
	}

	//Get Capacity of Array
	int getCapacity() const{
		return this->capacity;
	}

	//Get Max Key -> Value
	void getMax(v& _value){
		assert(total > 0);
		_value = arr[0].value;
	}

	//Get Min Key -> Value
	void getMin(v& _value){
		assert(total > 0);
		_value = 0;
		int key = arr[0].key;
		for (int i = 0; i < total; i++)
		{
			if (key > arr[i].key)
			{
				key = arr[i].key;
				_value = arr[i].value;
			}
		}
	}

	//If Array is Empty
	bool isEmpty(){
		if (total == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//Destructor
	~MaxHeap(){
		delete[]this->arr;
	}
};


int main(){

	//Min Heap
	MinHeap<int, float> M1;
	M1.insert(9, 2.53);
	M1.insert(254, 2.98);
	M1.insert(111, 3.20);
	M1.insert(6, 3.3);
	M1.insert(5, 3.1);
	M1.insert(4, 3.2);
	M1.insert(176, 3.5);
	M1.insert(101, 3.2);
	M1.insert(153, 2.34);
	M1.insert(10, 2.64);
	M1.insert(16, 2.5);
	M1.insert(300, 2.38);
	M1.insert(43, 2.9);
	M1.insert(15, 3.5);

	float value = 0;

	cout << "Getting Min and Max Value From Heap" << endl;

	M1.getMax(value);
	cout << "Maximum value : " << value << endl;

	M1.getMin(value);
	cout << "Minimum value : " << value << endl << endl;
	
	M1.deleteMax();
	M1.deleteMin();

	cout << "After Deleting Min and Max Heap Values" << endl;

	M1.getMax(value);
	cout << "Maximum value : " << value << endl;

	M1.getMin(value);
	cout << "Minimum value : " << value << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << endl << "--------Using Max Heap--------" << endl << endl;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	MaxHeap<float, float> M2;

	float arr[] = {3.2, 1.8, 2.4, 1.9, 2.4};
	M2.heapify(arr,5);

	cout << "Getting Min and Max Value From Heap" << endl;

	M2.getMax(value);
	cout << "Maximum value : " << value << endl;

	M2.getMin(value);
	cout << "Minimum value : " << value << endl << endl;


	system("pause");
	return 0;
}