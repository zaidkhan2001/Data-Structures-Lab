#include<iostream>
#include<string>
using namespace std;

int product(int x , int y){
	if(y==0){
		return y;
	}
	else{
		return x + product(x,y-1);
	}
}

int stringCompare (string const string1,string const string2){
	if(string1[0]=='\0' && string2[0]=='\0'){
		return 0;
	}
	if(string1[0] < string2[0]){
		return -1;
	}
	if (string1[0] > string2[0]){
		return 1;
	}

	else{
		string s1=string1.substr(1);
		string s2=string2.substr(1);
		return stringCompare(s1,s2);
	}

}

int main(){

	cout << "Implementing the Product of 2 Numbers (4,3) Using Recursion : " << endl;
	cout << product(4,3);
	cout << endl;

	cout << endl << "Comparing 2 Strings Using Recursion" << endl;
	
	int value =stringCompare("ahmed","ahmed");

	if(value==0){
		cout << "Strings Are Equal" << endl;
	}
	if(value==1){
		cout << "Strings1 > String2" << endl;
	}
	if(value==-1){
		cout << "String1 < String2" << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}