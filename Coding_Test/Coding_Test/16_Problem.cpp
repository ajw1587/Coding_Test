#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Anagram�̶� �� ���ڿ��� ���ĺ��� ���� ������ �ٸ����� �� ������ ��ġ�ϸ� �� �ܾ�� �Ƴ��׷��̶�� �Ѵ�.
// �� �ܾ �Ƴ��׷����� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�. (��ҹ��� ����)
int No16()
{
	string s_1 = "ASDADZZzzzz";
	string s_2 = "ASDADZZzzzz";
	//cin >> s_1;
	//cin >> s_2;

	// ���̰� �ٸ��� ���ʿ� ������ ����!
	if (s_1.size() != s_2.size())
	{
		cout << "NO" << endl;
		return 0;
	}

	// �м��ϱ�
	// �빮�� A ~ Z = 65 ~ 90 = 0 ~ 25
	// �ҹ��� a ~ z = 97 ~ 122 = 26 ~ 51
	vector<int> s_1_v(52, 0);
	vector<int> s_2_v(52, 0);
	int test1, test2;

	for (int i = 0; i < s_1.size(); i++)
	{
		test1 = s_1[i];
		test2 = s_2[i];

		if (test1 >= 65 && test1 <= 90) test1 -= 65;
		else test1 -= 71;
		if (test2 >= 65 && test2 <= 90) test2 -= 65;
		else test2 -= 71;

		s_1_v[test1]++;
		s_2_v[test2]++;
	}

	// ��
	for (int i = 0; i < s_1_v.size(); i++)
	{
		if (s_1_v[i] != s_2_v[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}

//int main()
//{
//	No16();
//
//	return 0;
//}