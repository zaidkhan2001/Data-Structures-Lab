#include<stack>
#include<iostream>
using namespace std;

void Output(stack<char>);//Output result in correct order
int Precedence(char);//Precedence of Operands
stack<char> InfixToPostFix(string);//Single Digit Infix to Postfix Converter,Question 1
int Compute(int, char, int);//Compute Result
stack<char>PostFixSolver(string);//Single Digit postfix equation solver,Question 2

int main()
{
	//2+2*3-3+1 -> 223*+31+-
	string infixEqu = "2+2*3-3+1";//Q1
	cout << "Your Infix Euqtion : " << infixEqu << endl;
	stack<char> postEqu = InfixToPostFix(infixEqu);
	cout << "Yout Postfix Equation :";
	Output(postEqu);
	string postFixEqu = "223*+31+-";//Q2
	stack<char> ans = PostFixSolver(postFixEqu);
	cout << "PostFix Equation Answer : ";
	Output(ans);
	system("pause");
}

void Output(stack<char> reverseEqu)
{
	stack<char> straightEqu;
	while (reverseEqu.size() > 0)
	{
		straightEqu.push((reverseEqu.top()));
		reverseEqu.pop();
	}
	while (straightEqu.size() > 0)
	{
		cout << straightEqu.top();
		straightEqu.pop();
	}
	cout << endl;
}

int Precedence(char operd)
{
	switch (operd)
	{
	case '*':
		return 4;
	case '/':
		return 3;
	case '+':
		return 2;
	case '-':
		return 1;
	}
}

stack<char> InfixToPostFix(string str)
{
	stack<char> postFixEqu;
	stack<char> operators;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			postFixEqu.push(str[i]);
		}
		else
		{
			while (!operators.empty() && Precedence(operators.top()) > Precedence(str[i]))
			{
				postFixEqu.push(operators.top());
				operators.pop();
			}
			operators.push(str[i]);
		}
	}
	while (operators.size() > 0)
	{
		postFixEqu.push(operators.top());
		operators.pop();
	}
	return postFixEqu;
}

int Compute(int op1, char oprt, int op2)
{
	switch (oprt)
	{
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	}

}

stack<char>PostFixSolver(string str)
{
	stack<char>ans;
	char ch;
	for (int i = 0; i < str.length(); ++i)
	{
		ch = str[i];
		if (ch >= '0' && ch <= '9')
		{
			ans.push(ch);
		}
		else
		{
			char op1, op2;
			op2 = ans.top();
			ans.pop();
			op1 = ans.top();
			ans.pop();
			ans.push(Compute(op1 - '0', ch, op2 - '0') + '0');
		}
	}
	return ans;
}