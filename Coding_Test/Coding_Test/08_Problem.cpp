#include <iostream>
#include <stack>

using namespace std;

// 괄호가 입력되면 올바른 괄호이면 "YES", 올바르지 않으면 "NO"를 출력하시오.
int No08()
{
	stack<char> temp;
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			temp.push(input[i]);
			continue;
		}
		else  // input[i] == ')'
		{
			if (temp.empty())
			{
				cout << "NO" << endl;
				return 0;
			}
			else
			{
				temp.pop();
			}
		}
	}

	cout << "YES" << endl;

	return 0;
}

//int main()
//{
//	No08();
//
//	return 0;
//}