#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string str)
{
	stack<char> st;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') { st.push(str[i]); }

		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if (st.empty()) { return false; }
			else if (st.top() == '{' && str[i] == '}' || st.top() == '(' && str[i] == ')' || st.top() == '[' && str[i] == ']') { st.pop(); }
			else { return false; }
		}
	}

	return st.empty();
}

int main()
{
	setlocale(LC_ALL, "rus");

	string str;
	cout << "Введите строку:" << endl;
	getline(cin, str);

	if (check(str)) { cout << "Скобки расставлены верно" << endl; }
	else { cout << "Скобки расставлены неверно!" << endl; }
}