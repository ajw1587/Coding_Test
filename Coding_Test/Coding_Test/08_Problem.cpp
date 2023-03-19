#include <iostream>
#include <stack>

using namespace std;

// ��ȣ�� �ԷµǸ� �ùٸ� ��ȣ�̸� "YES", �ùٸ��� ������ "NO"�� ����Ͻÿ�.
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