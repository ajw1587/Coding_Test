#include <iostream>
#include <string>

using namespace std;

// �ԷµǴ� ���ڸ� �ҹ��ڷ� �����ؼ� ����Ͻÿ�.
// a: 97, z: 122
// A: 65, Z: 90
int No07()
{
	string output;
	string input;
	getline(cin, input);

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 65 && input[i] <= 90) output.push_back(input[i] + 32);
		else if (input[i] >= 97 && input[i] <= 122) output.push_back(input[i]);
	}

	cout << output << endl;

	return 0;
}

//int main()
//{
//	No07();
//
//	return 0;
//}