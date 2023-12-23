#include <iostream>
#include<stack>
using namespace std;

bool isBalanced(string expression){

	char token;
	stack<char> stk;

	//Traverse Along the String
	for(int i=0;i<expression.length();i++){

		//If Opening Token Found Push in Stach
		if(expression[i]=='{' || expression[i]=='['||expression[i]=='('){
			stk.push(expression[i]);
		}

		//If Not Found pop element from Stack
		else{
			token=stk.top();
			if(token== '(' && expression[i] == ')' ||token == '{' && expression[i]== '}' || token== '[' && expression[i]==']'){
				stk.pop();
			}

			//IF popped Element Not Equal to Expression Return False Their
			else {
				return false;
			}
		}
	}

	if(stk.empty()){
		return true;
	}
}

int main(){

	string str= "{[{}{}]}[()}";

	if(isBalanced(str)){
		cout << "Expression is Balanced"<<endl;
	}
	else{
		cout<<"Expression is not Balanced"<<endl; 
	}

	cout << endl;

	system("pause");
	return 0;
}