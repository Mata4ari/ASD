#include <iostream>
#include <string>
#include <stack>
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "ru");
	stack <char> A;
	string str;
	char x;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			A.push('(');
		if (str[i] == '[')
			A.push('[');
		if (str[i] == '{')
			A.push('{');
		if (str[i] == ')')
		{
			if (A.top() == '(')
				A.pop();
			else
				break;
		}
		if (str[i] == ']')
		{
			if (A.top() == '[')
				A.pop();
			else
				break;
		}
		if (str[i] == '}')
		{
			if (A.top() == '{')
				A.pop();
			else
				break;
		}
	}
	if (A.empty())
		cout << "Скобки расставлены правильно";
	else
		cout << "Скобки расставлены неправильно";
}