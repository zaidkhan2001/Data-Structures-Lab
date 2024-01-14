#include<iostream>
#include<string>
#define lf 0.75
using namespace std;

template<typename k, typename v>
struct Hash_Item {
	k key;
	v value;
	int nature;

	//Default Constructor
	Hash_Item() {
		nature = -1;
	}

	//Parameterized Constructor
	Hash_Item(k KEY, v VAL) {
		nature = -1;
		key = KEY;
		value = VAL;
	}

	//Set If Item Exist 
	void setnature(int a) {
		nature = a;
	}

	//Print Hash Item
	void Print_Item() {
		cout << "key = " << key << endl;
		cout << "value = " << value << endl;
	}

	//Check if two Hash Items are equal or not
	bool operator==(Hash_Item& obj) {
		if (this->key == obj.key) {return true;}
		else {return false;}
	}

	//Get Key Value
	int get_key() {
		int a = key.get_integer();
		return a;
	}

	//Operator Overloading
	void operator=(Hash_Item& obj) {
		this->key = obj.key;
		this->value = obj.value;
	}
};

template<typename k, typename v>
class Hash_Map {
private:
	Hash_Item<k, v>* arr;
	int capacity;
	int totalElements;

	//Double Size of Hash Map
	void Double_Size() {

		//Double the Size
		int New_Cap = 2 * capacity;

		//Create New Hash Item
		Hash_Item<k, v>* ptr;
		ptr = new Hash_Item<k, v>[New_Cap];

		for (int a = 0; a < capacity; a++) {

			//If Node Exist Copy it
			if (arr[a].nature == 1) {

				int hashcode = int(arr[a].key.hashcode());

				for (int b = 0; b < New_Cap; b++) {
					int index = (hashcode + b * b) % New_Cap;

					//Perform Deep Copy
					if (ptr[index].nature == -1) {
						ptr[index] = arr[a];
						ptr[index].setnature(1);
						ptr[index].Print_Item();
						break;
					}
				}
			}
		}
		//Update The Values
		capacity = New_Cap;
		arr = ptr;
	}

public:

	//Default Constructor
	Hash_Map() {
		arr = nullptr;
		capacity = 0;
		totalElements = 0;
	}

	//Parameterized Constructor
	Hash_Map(int size) {
		capacity = size;
		arr = new Hash_Item<k, v>[capacity];
		totalElements = 0;
	}

	//Load Factor to Control Double of Array
	bool load() {
		float load = (1.0 * totalElements) / capacity;
		if (load <= 0.75) {
			return true;
		}
		else {
			return false;
		}
	}

	//Insert in Hash Function
	void Insert(k Key, v Val) {

		int hashcode = int(Key.hashcode());

		for (int i = 0; i < capacity; i++) {
			int index = (hashcode + i * i) % capacity;

			//Provided Index Empty Insert
			if (this->arr[index].nature == -1) {
				Hash_Item<k, v> temp(Key, Val);
				temp.setnature(1);
				this->arr[index] = temp;
				this->arr[index].setnature(1);
				this->arr[index].Print_Item();
				totalElements++;
				break;
			}
		}
		//Double The Size of Array
		if (!load()) {
			cout << endl << "Doubleing the Size of Array" << endl << endl;
			Double_Size();
		}
	}

	//Delete The Element
	void Delete_(k data) {

		for (int i = 0; i < capacity; i++) {

			int hashcode = int(data.hashcode());
			int index = (hashcode + i * i) % capacity;

			//If occupied Index Found
			if (arr[index].nature == 1) {
				Hash_Item<k, v>a;
				a.key = data;

				int num = arr[index].get_key();
				int num2 = a.get_key();

				//If Data Found Set its Nature 0 Automatic Deleted
				if (num == num2) {
					cout << "Successfully Delete: " << data << endl;
					arr[index].setnature(0);
					totalElements--;
					break;
				}
			}

		}
	}

	//Get Ptr Address of Key
	void Get_Hash(k key, v*& ptr) {
		//Ptr is Passed By Reference

		bool flag = false;
		
		//Checking if Key found
		for (int i = 0; i < capacity; i++) {
			int hashcode = int(key.hashcode());
			int index = (hashcode + i * i) % capacity;

			//If Index Occupied Check if Key Found
			if (arr[index].nature == 1) {
				Hash_Item<k, v>a;
				a.key = key;

				int num = arr[index].get_key();
				int num2 = a.get_key();
			
				//If Key Found Copy ptr
				if (num == num2) {
					flag = true;
					ptr = new v(arr[index].value);
					break;
				}
			}
		}

		//Key not Found
		if (flag == false) {
			ptr = nullptr;
		}
	}

	//Search For Hash Key
	bool Search_hashkey(k data){
		bool flag = false;
		
		for (int i = 0; i < capacity; i++) {
			int hashcode = int(data.hashcode());
			int index = (hashcode + i * i) % capacity;

			if (arr[index].nature == 1) {
				Hash_Item<k, v>a;
				a.key = data;
				int num = arr[index].get_key();
				int num2 = a.get_key();
				
				//If Key found Return true
				if (num == num2) {
					flag = true;
					break;
				}
			}
		}
		return flag;
	}

	//Overloaded Operator
	void operator[](int index) {

		//Provided Index Greater than Capacity
		if (index<0 || index>capacity - 1) {
			cout << "Provided Index Does Not Exist" << endl;
		}

		//Print Value at that Specific index
		else {
			cout << "Value at Index : " << index << endl;
			arr[index].Print_Item();
			cout << endl;
		}
	}

	//Destructor
	~Hash_Map() {
		if (arr != nullptr) {
			delete[] arr;
			arr = nullptr;
		}
	}
};

struct integer {
	int integerNum;

	//Parameterized Constructor
	integer(int num) {
		integerNum = num;
	}

	//Default Constructor
	integer() {
		integerNum = 0;
	}

	//Getter Function
	int get_integer() {
		return integerNum;
	}

	//Hash Function
	int hashcode() {
		int hashCode = integerNum << 1 | integerNum >> 5;
		return hashCode;
	}

	//Operator Overloading
	bool operator==(integer& obj) {
		if (obj.integerNum == this->integerNum) { return true; }
		else { return false; }
	}

	//Assigning Value
	void operator=(integer& x) {
		this->integerNum = x.integerNum;
	}

	//Ostream Printing
	friend ostream& operator<<(ostream& out, const integer& x) {
		out << x.integerNum;
		return out;
	}
};

int main() {

	Hash_Map<integer, string> hash(4);

	cout << "Inserting These Elements" << endl;
	
	hash.Insert(2, "Zaid");
	cout << endl;

	hash.Insert(4, "Khan");
	cout << endl;

	hash.Insert(1, "ZAID");
	cout << endl;


	cout << "Finding Key '4' " << endl;
	if (hash.Search_hashkey(4)) {
		cout << "Key Found"<< endl;
	}
	else {
		cout << "Key Not Found" << endl;
	}
	cout << endl;

	cout << "Finding Key '3' " << endl;
	if (hash.Search_hashkey(3)) {
		cout << "Key Found" << endl;
	}
	else {
		cout << "Key Not Found" << endl;
	}
	cout << endl;

	cout << "Getting Value Using Operator" << endl;
	hash[2];

	hash.Delete_(2);
	cout << endl;

	cout << "Pointer For Corresponding key" << endl;
	string* temp = nullptr;
	hash.Get_Hash(4, temp);
	if (temp == nullptr) {
		cout << "Ptr=nullptr" << endl;
	}
	else {
		cout << "Value = " << temp << endl << endl;
	}

	system("pause");
	return 0;

}