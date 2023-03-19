#include <iostream>
#include <string>

using namespace std;

// 숫자만 추출
int No06()
{
	int output = 0;
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if ((input[i] - 48) >= 0 && (input[i] - 48) <= 9)
		{
			output = output * 10 + input[i] - 48;
		}
	}

	cout << output << endl;

	return 0;
}

//int main()
//{
//	No06();
//
//	return 0;
//}