#include <iostream>
#include <chrono>
#include <vector>
#include <stack>

using namespace std;
using namespace chrono;

// ��ȣ�� �ԷµǸ� �ùٸ� ��ȣ�̸� "YES", �ùٸ��� ������ "NO"�� ����Ͻÿ�.
int No54()
{
	system_clock::time_point start = system_clock::now();

	const char* test = "(()(()))(()";
	stack<char> buffer;

	for (int i = 0; test[i] != '\0'; i++)
	{
		if (test[i] == '(')
		{
			buffer.push('(');
		}
		else	// test[i] == ')'
		{
			if (buffer.empty())
			{
				break;
			}
			else buffer.pop();
		}
	}
	if (buffer.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No54();

	return 0;
}