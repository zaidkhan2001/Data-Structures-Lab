#include<iostream>
#include<queue>
#include<list>
using namespace std;

template <typename K, typename V>
struct TreeNode {
	K key;
	V value;
	TreeNode* lChild;
	TreeNode* rChild;
	int height;

	//Default Constructor
	TreeNode() {
		this->lChild = this->rChild = nullptr;
		this->height = 0;
	}

	//Parametereized Constructor
	TreeNode(K key, V value) {
		this->key = key;
		this->value = value;
		this->lChild = this->rChild = nullptr;
		this->height = 0;
	}

	//Return True if Leaf Node
	bool isLeaf() {
		return !this->lChild && !this->rChild;
	}
};

template <typename K, typename V>
class BST {
public:
	TreeNode<K, V>* root;
	int total;

	//Default Constructor
	BST() {
		this->root = nullptr;
		total = 0;
	}

	//In Order Printing using recursion
	void inorderPrintKeys(TreeNode<K, V>* ptr) {
		if (ptr) {
			inorderPrintKeys(ptr->lChild);
			cout << ptr->key << endl;
			inorderPrintKeys(ptr->rChild);
		}
	}

	//Pre Order Printing using recursion
	void preOrderPrintKeys(TreeNode<K, V>* ptr) {
		if (ptr) {
			cout << ptr->key << endl;
			preOrderPrintKeys(ptr->lChild);
			preOrderPrintKeys(ptr->rChild);
		}
	}

	//Post Order Printing using recursion
	void postOrderPrintKeys(TreeNode<K, V>* ptr) {
		if (ptr) {
			postOrderPrintKeys(ptr->lChild);
			postOrderPrintKeys(ptr->rChild);
			cout << ptr->key << endl;
		}
	}

	//Search an Element From Tree and Return Node
	V const* search(K key, TreeNode<K, V>* ptr) {
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
	void deleteAll(TreeNode<K, V>* ptr) {
		if (ptr) {
			deleteAll(ptr->lChild);
			deleteAll(ptr->rChild);
			delete ptr;
		}
	}

	//Wrapper Function
	void inorderPrintKeys() {
		inorderPrintKeys(this->root);
	}

	//Wrapper Function
	void preOrderPrintKeys() {
		this->preOrderPrintKeys(this->root);
	}

	//Wrapper Function
	void postOrderPrintKeys() {
		this->postOrderPrintKeys(this->root);
	}

	//Tree is Perfect
	bool isPerfect() {
		int d = findADepth(this->root);
		return this->isPerfect(this->root, d);
	}

	//Wrapper Function
	V const* search(K key) {
		return this->search(key, this->root);
	}

	//Get Number of Nodes
	int length() {
		return total;
	}

	//Printing Ancestors
	void printallancestors(int x) {
		this->printallancestor(x);
	}

	//Destructor
	~BST() {
		this->deleteAll(this->root);
	}

};

template <typename K, typename V>
class AVL :public BST<K, V> {
public:
	//Insert a New Node
	void ins(K key, V value, TreeNode<K, V>*& ptr) {

		if (ptr == nullptr) {
			ptr = new TreeNode<K, V>(key, value);
		}

		else if (key > ptr->key || key < ptr->key) {
			if (key < ptr->key)
				ins(key, value, ptr->lChild);
			else
				ins(key, value, ptr->rChild);

			int balanceFactor = getBalanceFactor(ptr);

			//left left case
			if (balanceFactor > 1 && key < ptr->lChild->key) {
				this->rightRotate(ptr);
			}

			//right right case
			else if (balanceFactor<-1 && key>ptr->rChild->key) {
				this->leftRotate(ptr);
			}

			//left right
			else if (balanceFactor > 1 && key > ptr->lChild->key) {
				this->leftRotate(ptr->lChild);
				this->rightRotate(ptr);
			}

			//right left
			else if (balanceFactor < -1 && key < ptr->rChild->key) {
				this->rightRotate(ptr->rChild);
				this->leftRotate(ptr);
			}

			else this->updateHeight(ptr);
		}
	}

	//Delete A Node
	void del(K key, TreeNode<K, V>*& ptr) {

		if (ptr == nullptr)
			return;

		else if (key < ptr->key || key>ptr->key) {

			if (key < ptr->key)
				del(key, ptr->lChild);

			else del(key, ptr->rChild);

			//Getting Balance Factor
			int balanceFactor = getBalanceFactor(ptr);

			//left left case
			if (balanceFactor > 1 && getBalanceFactor(ptr->lChild) >= 0) {
				this->rightRotate(ptr);
			}

			//right right case
			else if (balanceFactor < -1 && getBalanceFactor(ptr->rChild) <= 0) {
				this->leftRotate(ptr);
			}

			//left right case
			else if (balanceFactor > 1 && getBalanceFactor(ptr->lChild) < 0) {
				this->leftRotate(ptr->lChild);
				this->rightRotate(ptr);
			}

			//right left case
			else if (balanceFactor < -1 && this->getBalanceFactor(ptr->rChild)>0) {
				this->rightRotate(ptr->rChild);
				this->leftRotate(ptr);
			}

			else this->updateHeight(ptr);
		}
		else {

			//leaf node
			if (ptr->isLeaf())
			{
				delete ptr;
				ptr = nullptr;
			}

			//left child exists
			else if (ptr->lChild && !ptr->rChild)
			{
				TreeNode<K, V>* delNode = ptr;
				ptr = ptr->lChild;
				delete delNode;
			}

			//right child exists
			else if (!ptr->lChild && ptr->rChild)
			{
				TreeNode<K, V>* delNode = ptr;
				ptr = ptr->rChild;
				delete delNode;
			}

			//both children exits
			else
			{
				TreeNode<K, V>* successor = ptr->rChild;
				while (successor->lChild)
					successor = successor->lChild;

				ptr->key = successor->key;
				ptr->value = successor->value;
				del(successor->key, ptr->rChild);

				int balanceFactor = getBalanceFactor(ptr);

				//left left case
				if (balanceFactor > 1 && getBalanceFactor(ptr->lChild) >= 0) {
					this->rightRotate(ptr);
				}

				//right right case
				else if (balanceFactor < -1 && getBalanceFactor(ptr->rChild) <= 0) {
					this->leftRotate(ptr);
				}

				//left right
				else if (balanceFactor > 1 && getBalanceFactor(ptr->lChild) < 0) {
					this->leftRotate(ptr->lChild);
					this->rightRotate(ptr);
				}

				//right left
				else if (balanceFactor < -1 && this->getBalanceFactor(ptr->rChild)>0) {
					this->rightRotate(ptr->rChild);
					this->leftRotate(ptr);
				}
				else this->updateHeight(ptr);
			}
		}
	}

	//Get Node Height
	int getHeight(TreeNode<K, V>* ptr) {
		if (ptr == nullptr) {
			return -1;
		}
		else return ptr->height;
	}

	// Update Nodes Height
	void updateHeight(TreeNode<K, V>* ptr) {
		ptr->height = 1 + (max(getHeight(ptr->lChild), getHeight(ptr->rChild)));
	}

	//Get Balance Factor of A Specific Node
	int getBalanceFactor(TreeNode<K, V>* ptr) {
		return getHeight(ptr->lChild) - getHeight(ptr->rChild);
	}

	//Left Rotation
	void leftRotate(TreeNode<K, V>*& ptr) {
		TreeNode<K, V>* y = ptr;
		TreeNode<K, V>* x = y->rChild;
		TreeNode<K, V>* T2 = x->lChild;
		ptr = x;
		x->lChild = y;
		y->rChild = T2;
		this->updateHeight(y);
		this->updateHeight(x);
	}

	//Right Rotation
	void rightRotate(TreeNode<K, V>*& ptr) {
		TreeNode<K, V>* y = ptr;
		TreeNode<K, V>* x = y->lChild;
		TreeNode<K, V>* T2 = x->rChild;
		ptr = x;
		x->rChild = y;
		y->lChild = T2;

		this->updateHeight(y);
		this->updateHeight(x);
	}

	void PrintCommonAncestors(TreeNode<K, V>* ptr, K key1, K key2) {
		if (ptr) {
			if (ptr->key > key1 && ptr->key < key2) {
				cout << ptr->key << endl;
			}
			PrintCommonAncestors(ptr->lChild,key1,key2);
			PrintCommonAncestors(ptr->rChild, key1, key2);
		}
	}

	void findMaxWidth(TreeNode<K,V>* ptr){

		if (ptr == nullptr) {
			return;
		}

		list<TreeNode<K,V>*> l;
		l.push_back(ptr);

		TreeNode<K,V>* curr = nullptr;

		int max = 0;

		while (!l.empty()){
			
			int width = l.size();

			if (max < width) {
				max = width;
			}

			while (width--){
				curr = l.front();
				l.pop_front();

				if (curr->lChild) {
					l.push_back(curr->lChild);
				}

				if (curr->rChild) {
					l.push_back(curr->rChild);
				}
			}
		}
		cout << "The Maximum width is " << max<< endl;
	}

	//Insert Wrapper Function
	void insert(K key, V value) {
		ins(key, value, this->root);
	}

	//Delete Wrapper Function
	void delete_(K key) {
		del(key, this->root);
	}

};

int main() {
	AVL<int, int> tree;

	for (int i = 1; i <= 100; i++)
		tree.insert(i, i);

	for (int i = -1; i >= -100; i--)
		tree.insert(i, i);

	for (int i = 150; i > 100; i--)
		tree.insert(i, i);

	for (int i = -150; i < -100; i++)
		tree.insert(i, i);

	for (int i = 150; i > 100; i--)
		tree.delete_(i);


	tree.inorderPrintKeys();
	cout << endl << endl;

	cout << "Tree Height: " << tree.getHeight(tree.root) << endl;

	const int* val = tree.search(-100);

	if (val != nullptr) {
		cout << "Key= -100 found" << endl;
	}

	val = tree.search(-151);
	if (val == nullptr) {
		cout << "Key= -151 not found" << endl;
	}

	cout << endl << "Common Ancestors Between two Keys 96 & 99 are" << endl;
	tree.PrintCommonAncestors(tree.root, 96, 99);

	if (tree.isPerfect()) {
		cout << endl << "AVL Tree is Perfect" << endl;
	}

	else {
		cout << endl << "AVL Tree is not Perfect" << endl;
	}

	tree.findMaxWidth(tree.root);

	system("pause");
	return 0;
}