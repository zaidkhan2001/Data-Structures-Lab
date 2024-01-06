#include<iostream>
using namespace std;

template <typename K, typename V>
struct TreeNode{
	K key;
	V value;
	TreeNode* lChild;
	TreeNode* rChild;

	//Default Constructor
	TreeNode(){
		this->lChild = this->rChild = nullptr;
	}

	//Parametereized Constructor
	TreeNode(K key, V value){
		this->key = key;
		this->value = value;
		this->lChild = this->rChild = nullptr;
	}

	//Return True if Leaf Node
	bool isLeaf(){
		return !this->lChild && !this->rChild;
	}
};

template <typename K, typename V>
class BinarySearchTree{
private:
	TreeNode<K, V>* root;
	int total;

	//In Order Printing using recursion
	void inorderPrintKeys(TreeNode<K, V>* ptr){
		if (ptr){
			inorderPrintKeys(ptr->lChild);
			cout << ptr->key << endl;
			inorderPrintKeys(ptr->rChild);
		}
	}

	//Pre Order Printing using recursion
	void preOrderPrintKeys(TreeNode<K, V>* ptr){
		if (ptr){
			cout << ptr->key << endl;
			preOrderPrintKeys(ptr->lChild);
			preOrderPrintKeys(ptr->rChild);
		}
	}

	//Post Order Printing using recursion
	void postOrderPrintKeys(TreeNode<K, V>* ptr){
		if (ptr){
			postOrderPrintKeys(ptr->lChild);
			postOrderPrintKeys(ptr->rChild);
			cout << ptr->key << endl;
		}
	}

	//Delete and Element
	void delete_(K key, TreeNode<K, V>*& ptr) {
		if (ptr == nullptr){
			return;
		}
		else if (key < ptr->key){
			delete_(key, ptr->lChild);
		}
		else if (key > ptr->key){
			delete_(key, ptr->rChild);
		}
		else{
			//leaf node
			if (ptr->isLeaf()){
				delete ptr;
				ptr = nullptr;
			}

			//only left child exists
			else if (ptr->lChild && !ptr->rChild){
				TreeNode<K, V>* delNode = ptr;
				ptr = ptr->lChild;
				delete delNode;
			}

			//only right child exists
			else if (!ptr->lChild && ptr->rChild){
				TreeNode<K, V>* delNode = ptr;
				ptr = ptr->rChild;
				delete delNode;
			}

			//both children exits
			else{
				TreeNode<K, V>* successor = ptr->rChild;
				while (successor->lChild)
					successor = successor->lChild;

				ptr->key = successor->key;
				ptr->value = successor->value;
				delete_(successor->key, ptr->rChild);

			}
		}
	}

	//Insert in tree
	void insert(K key, V value, TreeNode<K, V>*& ptr){
		
		//No Node
		if (ptr == nullptr){
			ptr = new TreeNode<K, V>(key, value);
			total++;
		}

		//Provided Value less Than Current
		else if (key < ptr->key){
			insert(key, value, ptr->lChild);
		}
		
		//Provided Value Greater Than Current
		else if (key > ptr->key){
			insert(key, value, ptr->rChild);
		}
	}

	//Search an Element From Tree and Return Node
	V const* search(K key, TreeNode<K, V>* ptr){
		if (ptr == nullptr)
			return nullptr;

		else if (key < ptr->key)
			return this->search(key, ptr->lChild);
		
		else if (key > ptr->key)
			return this->search(key, ptr->rChild);
		
		else return &ptr->value;
	}

	int findADepth(TreeNode<K, V>* ptr) {
		int d = 0;
		while (ptr != nullptr) {
			d++;
			ptr = ptr->lChild;
		}
		return d;
	}

	bool isPerfect(TreeNode<K, V>* ptr, int d, int level = 0) {
		if (ptr == nullptr)
			return true;

		if (ptr->lChild == nullptr && ptr->rChild == nullptr)
			return (d == level + 1);

		if (ptr->lChild == NULL || ptr->rChild == nullptr)
			return false;

		else
			return isPerfect(ptr->lChild, d, level + 1) && isPerfect(ptr->rChild, d, level + 1);		
	}

	void printallancestor(int num) {
		TreeNode<K, V>* ptr = this->root;
		bool flag = true;

		while (flag != false) {
			
			if (num == ptr->value) {
				flag = false;
			}

			if (num > ptr->value) {
				ptr = ptr->rChild;
			}

			if (num < ptr->value) {
				ptr = ptr->lChild;
			}
		}
		inorderPrintKeys(ptr);
	}

	//Dsstructor
	void deleteAll(TreeNode<K, V>* ptr){
		if (ptr){
			deleteAll(ptr->lChild);
			deleteAll(ptr->rChild);
			delete ptr;
		}
	}

public:
	//Default Constructor
	BinarySearchTree(){
		this->root = nullptr;
		total = 0;
	}

	//Wrapper Function
	void inorderPrintKeys(){
		inorderPrintKeys(this->root);
	}

	//Wrapper Function
	void preOrderPrintKeys(){
		this->preOrderPrintKeys(this->root);
	}

	//Wrapper Function
	void postOrderPrintKeys(){
		this->postOrderPrintKeys(this->root);
	}

	//Wrapper Function
	void insert(K key, V value){
		insert(key, value, this->root);
	}

	//Wrapper Function
	void delete_(K key){
		delete_(key, this->root);
	}

	bool isPerfect() {
		int d = findADepth(this->root);
		return this->isPerfect(this->root, d);
	}

	//Wrapper Function
	V const* search(K key){
		return this->search(key, this->root);
	}

	//Get Number of Nodes
	int length() {
		return total;
	}

	void printallancestors(int x) {
		this->printallancestor(x);
	}

	//Destructor
	~BinarySearchTree(){
		this->deleteAll(this->root);
	}

};

int main(){
	BinarySearchTree <int, int> tree; //the key and value both are of type int

	tree.insert(500, 500);
	tree.insert(1000, 1000);
	tree.insert(1, 1);
	tree.insert(600, 600);
	tree.insert(700, 700);
	tree.insert(10, 10);
	tree.insert(30, 30);
	tree.insert(9000, 9000);
	tree.insert(50000, 50000);
	tree.insert(20, 20);

	cout << endl << "Printing keys using recursive inorder traversal: ";
	tree.inorderPrintKeys();

	cout << endl << "Tree Length: " << tree.length() << endl << endl;

	if (tree.search(123) != nullptr) {
		cout << "123 found" << endl;
	}

	if (tree.search(123) == nullptr) {
		cout << "123 not found" << endl;
	}

	cout << endl << "Printing the keys using preOrder traversal: " << endl;
	tree.preOrderPrintKeys();

	cout << endl << "Printing the keys of ancestor nodes of 20" << endl;
	tree.printallancestors(20);
	
	tree.delete_(1);
	cout << endl <<  "Post order traversal: " << endl;
	tree.postOrderPrintKeys();

	if (tree.isPerfect() == 0) {
		cout << endl << "Tree is Not Perfect" << endl;
	}
	else {
		cout << endl << "Tree is Perfect" << endl;
	}

	system("pause");
	return 0;
}